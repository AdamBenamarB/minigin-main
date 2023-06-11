#pragma once
#include <iostream>

#include "GameObject.h"
#include "../BubbleBobble/BubComponent.h"

namespace dae
{
	class BubComponent;
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

	class Idle : public Command
	{
	public:
		Idle(std::shared_ptr<GameObject> obj) :Command(obj) {}
		void Execute() override { GetGameObject()->GetComponent<BubComponent>()->SetState(BubComponent::State::idle); }
	};

	class MoveLeft : public Command
	{
	public:
		MoveLeft(std::shared_ptr<GameObject> obj) :Command(obj) {}
		void Execute() override { GetGameObject()->GetComponent<BubComponent>()->SetState(BubComponent::State::left); }
	};

	class MoveRight : public Command
	{
	public:
		MoveRight(std::shared_ptr<GameObject> obj) :Command(obj) {}
		void Execute() override { GetGameObject()->GetComponent<BubComponent>()->SetState(BubComponent::State::right); }
	};

	class Jump : public Command
	{
	public:
		Jump(std::shared_ptr<GameObject> obj) :Command(obj) {}
		void Execute() override { GetGameObject()->GetComponent<BubComponent>()->Jump(); }
	};

	
}
