#pragma once

namespace dae
{
	class GameObject;


	class Component
	{
	public:
		Component(GameObject* owner);
		~Component() = default;
		Component(const Component& other) = delete;
		Component(Component&& other) noexcept = delete;
		Component& operator=(const Component& other) = delete;
		Component& operator=(Component&& other) noexcept = delete;

		virtual void Update(float deltaTime);
		GameObject* GetGameObject() const { return m_GameObject; }



	private:
		GameObject* m_GameObject;
	};
}

