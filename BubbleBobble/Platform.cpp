#include "Platform.h"

#include "CollisionComponent.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "Input.h"
#include "PlatformComponent.h"
#include "Scene.h"

dae::Platform::Platform(dae::Scene& scene, Vec2 loc)
{
	Initialize(scene, loc);
}

void dae::Platform::Initialize(dae::Scene& scene, Vec2 loc)
{
	auto go = std::make_shared<dae::GameObject>();
	auto rc = go->AddComponent<dae::RenderComponent>();
	rc->SetTexture("\\Sprites\\World\\Tile.png");
	rc->SetDimensions(32, 32);

	auto col = go->AddComponent<CollisionComponent>();
	col->SetSize(32, 32);
	col->SetOffset(0, 0);

	//go->AddComponent<PlatformComponent>();

	go->GetTransform()->SetLocalPosition(loc.x, loc.y, 0);


	go->SetTag("PLATFORM");
	scene.Add(go);

}
