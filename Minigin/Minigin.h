#pragma once
#include <string>
#include <functional>

namespace dae
{
	class Minigin
	{
	public:
		Minigin();
		~Minigin();
		void Run();
		virtual void LoadGame() const;
		virtual void Cleanup();

	private:

		float m_FixedTimeStep = 0.010f;
		static const int MsPerFrame = 16;
	};
}