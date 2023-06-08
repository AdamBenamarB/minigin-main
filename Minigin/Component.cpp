#include "Component.h"
dae::Component::Component(GameObject* owner)
	:m_GameObject{ owner }
{
}

void dae::Component::Update(float /*deltaTime*/)
{
	
}
