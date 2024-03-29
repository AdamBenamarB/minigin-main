#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <Xinput.h>
#include "XBox360Controller.h"


using namespace dae;

//IMPLEMENTATION
class XBox360Controller::Xbox360ControllerImpl
{
	XINPUT_STATE previousState{};
	XINPUT_STATE currentState{};

	WORD buttonsPressedThisFrame;
	WORD buttonsReleasedThisFrame;

	int _controllerIndex;
public:
	Xbox360ControllerImpl(int controllerIndex)
	{
		ZeroMemory(&previousState, sizeof(XINPUT_STATE));
		ZeroMemory(&currentState, sizeof(XINPUT_STATE));
		_controllerIndex = controllerIndex;
	}

	void Update()
	{
		CopyMemory(&previousState, &currentState, sizeof(XINPUT_STATE));
		ZeroMemory(&currentState, sizeof(XINPUT_STATE));
		XInputGetState(_controllerIndex, &currentState);

		auto buttonChanges = currentState.Gamepad.wButtons ^ previousState.Gamepad.wButtons;
		buttonsPressedThisFrame = buttonChanges & currentState.Gamepad.wButtons;
		buttonsReleasedThisFrame = buttonChanges & (~currentState.Gamepad.wButtons);
	}


	bool IsDownThisFrame(unsigned int button) const { return buttonsPressedThisFrame & button; }
	bool IsUpThisFrame(unsigned int button) const { return buttonsReleasedThisFrame & button; }
	bool IsPressed(unsigned int button) const { return currentState.Gamepad.wButtons & button; }

	/*static int* GetConnectedIds()
	{
		int dwResult;
		for (int i{}; i < XUSER_MAX_COUNT; ++i)
			connectedIds[i] = -1;
		int connectedIdIdx = 0;
		for (int i = 0; i < XUSER_MAX_COUNT; i++)
		{
			XINPUT_STATE state;
			ZeroMemory(&state, sizeof(XINPUT_STATE));

			dwResult = XInputGetState(i, &state);

			if (dwResult == ERROR_SUCCESS)
			{
				connectedIds[connectedIdIdx] = i;
				++connectedIdIdx;
			}
		}
		return connectedIds;
	}*/

	int GetIndex() { return _controllerIndex; }
};

//XBOX CONTROLLER CLASS
XBox360Controller::XBox360Controller(int controllerIndex)
{
	pImpl = new Xbox360ControllerImpl(controllerIndex);
}


XBox360Controller::~XBox360Controller()
{
	delete pImpl;
}

void XBox360Controller::Update()
{
	pImpl->Update();
}


bool XBox360Controller::IsDown(ControllerButton button) const
{
	return pImpl->IsDownThisFrame(static_cast<unsigned int>(button));
}

bool XBox360Controller::IsUp(ControllerButton button) const
{
	return pImpl->IsUpThisFrame(static_cast<unsigned int>(button));
}

bool XBox360Controller::IsPressed(ControllerButton button) const
{
	return pImpl->IsPressed(static_cast<unsigned int>(button));
}

int XBox360Controller::GetIndex()
{
	return pImpl->GetIndex();
}

int* XBox360Controller::GetControllerIds()
{
	return nullptr;// Xbox360ControllerImpl::GetConnectedIds();
}
