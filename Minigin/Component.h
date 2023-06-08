#pragma once
#include "Transform.h"

namespace dae
{
	class GameObject;


	class Component
	{
	public:
		virtual void Update(float deltaTime);

		Component(GameObject* owner);
		~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) noexcept = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) noexcept = delete;
	private:
		GameObject* m_GameObject;
	};
}

