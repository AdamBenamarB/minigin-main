#include "CollisionComponent.h"

#include "GameObject.h"

void dae::CollisionComponent::SetSize(float width, float height)
{
	m_Width = width;
	m_Height = height;
}

void dae::CollisionComponent::SetOffset(float x, float y)
{
	m_OffsetX = x;
	m_OffsetY = y;
}


bool dae::CollisionComponent::IsOverlapping(GameObject* other)
{
	if (GetGameObject() == other)
		return false;

	if (auto othercol = other->GetComponent<CollisionComponent>())
	{
		auto pos = GetGameObject()->GetTransform()->GetWorldPosition();
		pos.x += m_OffsetX;
		pos.y += m_OffsetY;
		glm::vec3 cornerpos{ pos.x + m_Width,pos.y + m_Height,pos.z };

		auto otherpos = other->GetTransform()->GetWorldPosition();
		otherpos.x += othercol->m_OffsetX;
		otherpos.y += othercol->m_OffsetY;
		glm::vec3 othercorner{ otherpos.x + othercol->m_Width,otherpos.y + othercol->m_Height,otherpos.z };

		if (pos.x > othercorner.x || otherpos.x > cornerpos.x)
			return false;

		if (cornerpos.y < otherpos.y || othercorner.y < pos.y)
			return false;

		return true;
	}
	return false;
}

bool dae::CollisionComponent::IsOverlapping(Rect other)
{

	auto pos = GetGameObject()->GetTransform()->GetWorldPosition();
	pos.x += m_OffsetX;
	pos.y += m_OffsetY;
	glm::vec3 cornerpos{ pos.x + m_Width,pos.y + m_Height,pos.z };

	glm::vec3 otherpos = { other.x,other.y,0 };
	glm::vec3 othercorner = { other.x + other.width,other.y + other.height,0 };

	if (pos.x > othercorner.x || otherpos.x > cornerpos.x)
		return false;

	if (cornerpos.y < otherpos.y || othercorner.y < pos.y)
		return false;

	return true;
}


bool dae::CollisionComponent::IsUnder(GameObject* other)
{
	if (GetGameObject() == other)
		return false;

	auto pos = GetGameObject()->GetTransform()->GetWorldPosition();
	pos.x += m_OffsetX;
	pos.y += m_OffsetY;
	glm::vec3 cornerpos{ pos.x + m_Width,pos.y + m_Height,pos.z };
	auto othercol = other->GetComponent<CollisionComponent>();
	auto otherpos = other->GetTransform()->GetWorldPosition();
	otherpos.x += othercol->m_OffsetX;
	otherpos.y += othercol->m_OffsetY;
	glm::vec3 othercorner{ otherpos.x + othercol->m_Width,otherpos.y + othercol->m_Height,otherpos.z };


	if (cornerpos.y > othercorner.y)
		return true;

	return false;
}

bool dae::CollisionComponent::IsUnder(Rect other)
{
	auto pos = GetGameObject()->GetTransform()->GetWorldPosition();
	pos.x += m_OffsetX;
	pos.y += m_OffsetY;
	glm::vec3 cornerpos{ pos.x + m_Width,pos.y + m_Height,pos.z };

	glm::vec3 othercorner = { other.x + other.width,other.y + other.height,0 };

	if (cornerpos.y < othercorner.y)
		return true;

	return false;
}

bool dae::CollisionComponent::IsToSide(GameObject* other)
{
	if (GetGameObject() == other)
		return false;

	auto pos = GetGameObject()->GetTransform()->GetWorldPosition();
	pos.x += m_OffsetX;
	pos.y += m_OffsetY;
	glm::vec3 cornerpos{ pos.x + m_Width,pos.y + m_Height,pos.z };
	auto othercol = other->GetComponent<CollisionComponent>();
	auto otherpos = other->GetTransform()->GetWorldPosition();
	otherpos.x += othercol->m_OffsetX;
	otherpos.y += othercol->m_OffsetY;
	glm::vec3 othercorner{ otherpos.x + othercol->m_Width,otherpos.y + othercol->m_Height,otherpos.z };


	if (cornerpos.x > othercorner.x || otherpos.x > pos.x)
		return true;

	return false;
}

bool dae::CollisionComponent::IsToSide(Rect other)
{
	auto pos = GetGameObject()->GetTransform()->GetWorldPosition();
	pos.x += m_OffsetX;
	pos.y += m_OffsetY;
	glm::vec3 cornerpos{ pos.x + m_Width,pos.y + m_Height,pos.z };

	glm::vec3 otherpos{ other.x,other.y,0 };
	glm::vec3 othercorner = { other.x + other.width,other.y + other.height,0 };

	if (pos.x > otherpos.x || cornerpos.x < othercorner.x)
		return true;

	return false;
}

