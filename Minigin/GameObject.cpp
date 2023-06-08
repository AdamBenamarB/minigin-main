#include <string>
#include "GameObject.h"
#include "ResourceManager.h"
#include "Component.h"

dae::GameObject::~GameObject() = default;

void dae::GameObject::Update(float deltaTime)
{
	for (std::shared_ptr<Component> component : m_Components)
	{
		component->Update(deltaTime);
	}
}

void dae::GameObject::FixedUpdate(float /*timeStep*/)
{
	
}


//void dae::GameObject::Render() const
//{
//	const auto& pos = m_transform.GetPosition();
//}



void dae::GameObject::SetPosition(float x, float y)
{
	m_transform.SetPosition(x, y, 0.0f);
}
