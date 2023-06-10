#pragma once
#include <iostream>

#include "GameObject.h"

namespace dae
{
	class PepperComponent;
	class PeterPepperComponent;
	class HealthComponent;

	class Command
	{
	public:
		explicit Command(std::shared_ptr<GameObject> obj) :object{ obj } {}
		virtual ~Command() = default;
		virtual void Execute() = 0;
	protected:
		std::shared_ptr<GameObject>  GetGameObject() { return object; }
	private:
		std::shared_ptr<GameObject>  object;
	};

	/*class AddPointsCommand : public Command
	{
	public:
		AddPointsCommand(std::shared_ptr<GameObject> obj) :Command(obj) {}
		void Execute() override { GetGameObject()->GetComponent<PointsComponent>()->AddPoints(100); }
	};*/

	
}