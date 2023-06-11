#include "Bub.h"
#include "Structs.h"
#include <memory>
#include "GameObject.h"

#include "BubComponent.h"
#include "CollisionComponent.h"
#include "InputManager.h"
#include "RenderComponent.h"
#include "Scene.h"

dae::Bub::Bub(dae::Scene& scene, Vec2 loc)
{
	Initialize(scene, loc);
}

void dae::Bub::Initialize(dae::Scene& scene, Vec2 loc)
{
	auto go = std::make_shared<dae::GameObject>();
	m_Bub = go.get();
	auto ppcomp = go->AddComponent<BubComponent>();
	auto col = go->AddComponent<CollisionComponent>();
	col->SetSize(32, 32);
	auto rc = go->AddComponent<RenderComponent>();
	rc->SetTexture("\\Sprites\\Bub\\Bub.png");


	scene.Add(go);

	InputManager::GetInstance().AddController(0);
	auto controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadLeft,Input::KeyState::OnPressed });
	auto command = std::make_unique<dae::MoveLeft>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadLeft,Input::KeyState::OnReleased });
	auto command2 = std::make_unique<dae::Idle>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command2));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadRight,Input::KeyState::OnPressed });
	auto command3 = std::make_unique<dae::MoveRight>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command3));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::DpadRight,Input::KeyState::OnReleased });
	auto command4 = std::make_unique<dae::Idle>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command4));

	controllerkey = Input::ControllerKey({ 0, dae::XBox360Controller::ControllerButton::ButtonA,Input::KeyState::OnPressed });
	auto command5 = std::make_unique<dae::Jump>(go);
	dae::InputManager::GetInstance().AddCommand(controllerkey, std::move(command5));
}
