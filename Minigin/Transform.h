#pragma once
#include <glm/glm.hpp>
#include "Component.h"
namespace dae
{
	class Transform : public Component
	{
	public:
		Transform(GameObject* obj);
		const glm::vec3& GetWorldPosition();
		const glm::vec3& GetLocalPosition() const { return m_LocalPosition; }
		void SetLocalPosition(float x, float y, float z);
		void SetLocalPosition(const glm::vec3& pos);
		void SetPositionDirty(bool dirty) { m_IsDirty = dirty; }
	private:
		void UpdateWorldPosition();;

		glm::vec3 m_LocalPosition{};
		glm::vec3 m_WorldPosition{};

		bool m_IsDirty{ false };
	};
}
