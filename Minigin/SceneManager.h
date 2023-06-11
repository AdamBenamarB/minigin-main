#pragma once
#include "Singleton.h"
#include <string>
#include <memory>
#include <vector>

namespace dae
{
	class Scene;
	class SceneManager final : public Singleton<SceneManager>
	{
	public:
		Scene& CreateScene(const std::string& name);

		void Update(float deltaTime);
		void FixedUpdate(float timeStep);
		void Render();

		void SetActiveScene(std::string sceneName);
		Scene& GetActiveScene() const;

		void RemoveScene(Scene& scene);
	private:
		friend class Singleton<SceneManager>;
		SceneManager() = default;
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		Scene* m_ActiveScene{};

		Scene* m_ToRemove{};

	};
}
