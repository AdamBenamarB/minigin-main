#include "BubComponent.h"

#include <iostream>

#include "CollisionComponent.h"
#include "GameObject.h"
#include "Scene.h"
#include "SceneManager.h"

dae::BubComponent::BubComponent(GameObject* owner)
	:Component(owner)
{
	
}

dae::BubComponent::~BubComponent()
{
	
}


void dae::BubComponent::Update(float deltaTime)
{
	HandleMovement(deltaTime);
	HandleCollision(deltaTime);
}

void dae::BubComponent::HandleMovement(float deltaTime)
{
	auto pos = GetGameObject()->GetTransform()->GetLocalPosition();
	switch(m_State)
	{
	case State::left:
		pos.x -= m_Speed * deltaTime;
		GetGameObject()->GetTransform()->SetLocalPosition(pos);
		break;
	case State::right:
		pos.x += m_Speed * deltaTime;
		GetGameObject()->GetTransform()->SetLocalPosition(pos);
		break;
	}
	if(m_IsJumping)
	{
		if (m_ElapsedJump < m_JumpTime)
		{
			m_ElapsedJump += deltaTime;
			pos.y -= m_JumpSpeed * deltaTime;
			GetGameObject()->GetTransform()->SetLocalPosition(pos);
		}
		else
		{
			m_ElapsedJump = 0.f;
			m_IsJumping = false;
		}
	}
	pos.y += m_Gravity * deltaTime;
	GetGameObject()->GetTransform()->SetLocalPosition(pos);

}

void dae::BubComponent::HandleCollision(float deltaTime)
{
	auto pos = GetGameObject()->GetTransform()->GetWorldPosition();

	for(auto& obj:SceneManager::GetInstance().GetActiveScene().GetObjects())
	{
		Vec2 overlap{};
		if(GetGameObject()->GetComponent<CollisionComponent>()->IsOverlapping(obj.get(),overlap))
		{
			if(obj->GetTag().compare("PLATFORM") == 0)
			{
				if(!m_IsJumping)
				{
					//pos.x += overlap.x;
					pos.y -= overlap.y;
					GetGameObject()->GetTransform()->SetLocalPosition(pos);
				}
			}
			if (obj->GetTag().compare("WALL") == 0)
			{
				if(GetState()==State::right)
					pos.x -= overlap.x;
				if (GetState() == State::left)
					pos.x += overlap.x;
				GetGameObject()->GetTransform()->SetLocalPosition(pos);
			}
		}
	}
}

