#pragma once
#include "Component.h"
namespace dae {
    class GameObject;

    class BubComponent : public dae::Component
    {
    public:
        enum class State
        {
            idle,
            left,
            right,
            hit
        };
        BubComponent(GameObject* owner);
        ~BubComponent();
        void Update(float deltaTime) override;
        void SetState(State state) { m_State = state; }
        State GetState() const { return m_State; }
        void Jump() { if (!m_IsJumping) { m_IsJumping = true; m_ElapsedJump = 0.f; } }
    private:
        void HandleMovement(float deltaTime);
        void HandleCollision(float deltaTime);

        State m_State{ State::idle };
        float m_Speed = 200.f;
        float m_JumpSpeed = 400.f;
        float m_JumpTime = 0.5f;
        float m_ElapsedJump = 0.f;
        float m_Gravity = 98.1f;

        bool m_IsJumping = false;
    };

}