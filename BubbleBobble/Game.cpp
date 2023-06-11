#include "Game.h"

#include "FPS.h"
#include "RenderComponent.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Scene.h"
#include "TextComponent.h"


void Game::LoadGame() const
{
	auto& scene = dae::SceneManager::GetInstance().CreateScene("Demo");

	auto go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::RenderComponent>()->SetTexture("background.tga");
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	go->AddComponent<dae::RenderComponent>()->SetTexture("logo.tga");
	go->SetPosition(216, 180);
	scene.Add(go);

	auto font = dae::ResourceManager::GetInstance().LoadFont("Lingua.otf", 36);
	go = std::make_shared<dae::GameObject>();

	auto tc = go->AddComponent<dae::TextComponent>();
	tc->SetFont(font);
	tc->SetText("Programming 4 assignment");
	go->SetPosition(80, 20);
	scene.Add(go);

	go = std::make_shared<dae::GameObject>();
	auto text = go->AddComponent<dae::TextComponent>();
	text->SetColor(0, 1, 0);
	text->SetFont(font);
	go->SetPosition(10, 10);
	go->AddComponent<dae::FPS>();
	scene.Add(go);

}

void Game::Cleanup()
{
	Minigin::Cleanup();
}
