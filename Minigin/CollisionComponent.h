#pragma once
#include "Component.h"
#include "Structs.h"

namespace dae {
    class CollisionComponent :
        public Component
    {
    public:
        CollisionComponent(GameObject* owner) :Component(owner) {}
        void SetSize(float width, float height);
        void SetOffset(float x, float y);

        bool IsOverlapping(GameObject* other);
        bool IsOverlapping(GameObject* other, Vec2& overlappedAmt);
        bool IsOverlapping(Rect other);
        bool IsUnder(GameObject* other);
        bool IsUnder(Rect other);

        bool IsToSide(GameObject* other);
        bool IsToSide(Rect other);
    private:
        Vec2 CalculateOverlap(Rect rect1, Rect rect2);
        float m_Width{},
            m_Height{};
        float m_OffsetX{},
            m_OffsetY{};
    };

}
