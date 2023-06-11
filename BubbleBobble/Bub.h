#pragma once
struct Vec2;
namespace dae {
	class GameObject;
	class Scene;
	class Bub
	{
	public:
		Bub(dae::Scene& scene, Vec2 loc);
		~Bub() = default;
		Bub(const Bub& other) = delete;
		Bub(Bub&& other) noexcept = delete;
		Bub& operator=(const Bub& other) = delete;
		Bub& operator=(Bub&& other) noexcept = delete;
	private:
		void Initialize(dae::Scene& scene, Vec2 loc);
		GameObject* m_Bub{};
	};

}
