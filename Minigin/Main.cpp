#include <SDL.h>

#if _DEBUG
// ReSharper disable once CppUnusedIncludeDirective
#if __has_include(<vld.h>)
#include <vld.h>
#endif
#endif

#include "FPS.h"
#include "GameObject.h"
#include "Minigin.h"
#include "RenderComponent.h"
#include "SceneManager.h"
#include "ResourceManager.h"
#include "Scene.h"
#include "TextComponent.h"
#include "../BubbleBobble/Game.h"

void load()
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

//int main(int, char*[]) {
//	Game engine();
//	engine.Run();
//    return 0;
//}