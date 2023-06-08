#pragma once
#include <type_traits>
#include <memory>
#include <vector>
#include "Transform.h"


namespace dae
{
	class Component;
	class Texture2D;
	
	class GameObject final
	{
	public:
		virtual void Update(float deltaTime);
		virtual void FixedUpdate(float timeStep);

		void SetPosition(float x, float y);
		Transform GetTransform() const { return m_transform; }

		template<typename T> T* AddComponent();
		template<typename T> void RemoveComponent();
		template<typename T> T* GetComponent()const;
		//bool HasComponent(Component* comp);

		GameObject() = default;
		virtual ~GameObject();
		GameObject(const GameObject& other) = delete;
		GameObject(GameObject&& other) = delete;
		GameObject& operator=(const GameObject& other) = delete;
		GameObject& operator=(GameObject&& other) = delete;

		void SetParent(GameObject* parent, bool worldPosStays);
		GameObject* GetParent() const { return m_pParent; }
		void RemoveChild(GameObject* child);
		void AddChild(GameObject* child);

	private:
		std::vector<std::shared_ptr<Component>> m_Components;
		Transform m_transform{};
		GameObject* m_pParent;
	};
}

//TEMPLATED FUNCTIONS
template <typename T>
T* dae::GameObject::AddComponent()
{
	if (std::is_base_of<Component, T>())
	{

		std::shared_ptr < T > ptr = std::make_shared<T>(this);
		m_Components.push_back(ptr);
		return ptr.get();
	}
	else return nullptr;
}

template <typename T>
T* dae::GameObject::GetComponent() const
{
	for (std::shared_ptr<Component> comp : m_Components)
	{
		if (typeid(T) == typeid(*comp))
		{
			return (T*)comp.get();
		}

	}
	return nullptr;
}


template<typename T>
void dae::GameObject::RemoveComponent()
{
	for (auto it = m_Components.begin(); it < m_Components.end();)
	{
		if (typeid(**it) == typeid(T))
		{
			it = m_Components.erase(it);
		}
		else
		{
			++it;
		}
	}

}
