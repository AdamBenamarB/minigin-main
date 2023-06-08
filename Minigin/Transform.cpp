#include "Transform.h"

#include "GameObject.h"

dae::Transform::Transform(GameObject* obj)
	:Component(obj)
{
	
}

const glm::vec3& dae::Transform::GetWorldPosition()
{
	if (m_IsDirty)
		UpdateWorldPosition();
	return m_WorldPosition;
}

void dae::Transform::SetLocalPosition(const glm::vec3& pos)
{
	m_LocalPosition = pos;
	SetPositionDirty(true);
}

void dae::Transform::SetLocalPosition(float x, float y, float z)
{
	SetLocalPosition(glm::vec3{ x,y,z });
}

void dae::Transform::UpdateWorldPosition()
{
	if(m_IsDirty)
	{
		GameObject* obj = GetGameObject();
		if(obj)
		{
			if (auto parent = obj->GetParent())
			{
				if (auto trans = parent->GetTransform())
					m_WorldPosition = trans->GetWorldPosition() + m_LocalPosition;

			}
			else
				m_WorldPosition = m_LocalPosition;
		}
	}
}
