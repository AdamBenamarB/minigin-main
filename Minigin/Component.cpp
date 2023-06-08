#include "Component.h"
#include "GameObject.h"
dae::Component::Component(GameObject* owner)
	:m_GameObject{ owner }
{
}

void dae::Component::Update(float /*deltaTime*/)
{
	
}
