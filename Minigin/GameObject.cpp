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
	m_transform->SetLocalPosition(x, y, 0.0f);
}

void dae::GameObject::SetParent(GameObject* parent,bool worldPosStays)
{
	if (m_transform == nullptr)
		return;
	if(m_pParent == nullptr)
	{
		GetTransform()->SetLocalPosition(m_transform->GetWorldPosition());
	}
	else
	{
		if(parent)
			if(auto parenttrans = parent->GetTransform())
				if (worldPosStays)
					m_transform->SetLocalPosition(m_transform->GetLocalPosition() - parenttrans->GetWorldPosition());
		m_transform->SetPositionDirty(true);
		for(GameObject*& child: m_Children)
		{
			if (auto childtrans = child->GetTransform())
				childtrans->SetPositionDirty(true);
		}
	}
	if (m_pParent)
		m_pParent->RemoveChild(this);
	m_pParent = parent;
	if (m_pParent)
		m_pParent->AddChild(this);
}

void dae::GameObject::AddChild(GameObject* child)
{
	child->SetParent(this);
	m_Children.push_back(child);

}

void dae::GameObject::RemoveChild(GameObject* child)
{
	child->SetParent(nullptr);
	m_Children.erase(std::find(m_Children.begin(), m_Children.end(), child));
}

