#include "Game.h"

#include "Bub.h"
#include "BubComponent.h"
#include "FPS.h"
#include "RenderComponent.h"
#include "ResourceManager.h"
#include "SceneManager.h"
#include "GameObject.h"
#include "Platform.h"
#include "Scene.h"
#include "TextComponent.h"
#include "Structs.h"
#include "Wall.h"


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

	/*go = std::make_shared<dae::GameObject>();
	auto bub = go->AddComponent<dae::BubComponent>();
	scene.Add(go);*/

	dae::Bub bub{ scene,Vec2{300,50} };
	dae::Wall w1{ scene,Vec2{0,0} };
	dae::Wall w2{ scene,Vec2{0,32} };
	dae::Wall w3{ scene,Vec2{0,64} };
	dae::Wall w4{ scene,Vec2{0,96} };
	dae::Wall w5{ scene,Vec2{0,128} };
	dae::Wall w6{ scene,Vec2{0,160} };
	dae::Wall w7{ scene,Vec2{0,192} };
	dae::Wall w8{ scene,Vec2{0,224} };
	dae::Wall w9{ scene,Vec2{0,256} };
	dae::Wall w10{ scene,Vec2{0,288} };
	dae::Wall w11{ scene,Vec2{0,320} };
	dae::Wall w12{ scene,Vec2{0,352} };
	dae::Wall w13{ scene,Vec2{0,384} };
	dae::Wall w14{ scene,Vec2{0,416} };
	dae::Wall w15{ scene,Vec2{0,448} };
	dae::Wall w21{ scene,Vec2{610,0} };
	dae::Wall w22{ scene,Vec2{610,32} };
	dae::Wall w23{ scene,Vec2{610,64} };
	dae::Wall w24{ scene,Vec2{610,96} };
	dae::Wall w25{ scene,Vec2{610,128} };
	dae::Wall w26{ scene,Vec2{610,160} };
	dae::Wall w27{ scene,Vec2{610,192} };
	dae::Wall w28{ scene,Vec2{610,224} };
	dae::Wall w29{ scene,Vec2{610,256} };
	dae::Wall w210{ scene,Vec2{610,288} };
	dae::Wall w211{ scene,Vec2{610,320} };
	dae::Wall w212{ scene,Vec2{610,352} };
	dae::Wall w213{ scene,Vec2{610,384} };
	dae::Wall w214{ scene,Vec2{610,416} };
	dae::Wall w215{ scene,Vec2{610,448} };
	dae::Platform p1{ scene,Vec2{32,448} };
	dae::Platform p2{ scene,Vec2{64,448} };
	dae::Platform p3{ scene,Vec2{96,448} };
	dae::Platform p4{ scene,Vec2{128,448} };
	dae::Platform p5{ scene,Vec2{160,448} };
	dae::Platform p6{ scene,Vec2{192,448} };
	dae::Platform p7{ scene,Vec2{224,448} };
	dae::Platform p8{ scene,Vec2{256,448} };
	dae::Platform p9{ scene,Vec2{288,448} };
	dae::Platform p10{ scene,Vec2{320,448} };
	dae::Platform p11{ scene,Vec2{352,448} };
	dae::Platform p12{ scene,Vec2{384,448} };
	dae::Platform p13{ scene,Vec2{416,448} };
	dae::Platform p14{ scene,Vec2{448,448} };
	dae::Platform p15{ scene,Vec2{480,448} };
	dae::Platform p16{ scene,Vec2{512,448} };
	dae::Platform p17{ scene,Vec2{544,448} };
	dae::Platform p18{ scene,Vec2{576,448} };
	dae::Platform p19{ scene,Vec2{608,448} };
	//dae::Platform p20{ scene,Vec2{640,448} };
	dae::Platform p92{ scene,Vec2{352,100} };

}

void Game::Cleanup()
{
	Minigin::Cleanup();
}
