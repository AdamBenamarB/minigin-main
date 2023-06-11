#include "Wall.h"

#include "CollisionComponent.h"
#include "RenderComponent.h"
#include "GameObject.h"
#include "Input.h"
#include "Scene.h"

dae::Wall::Wall(dae::Scene& scene, Vec2 loc)
{
	Initialize(scene, loc);
}

void dae::Wall::Initialize(dae::Scene& scene, Vec2 loc)
{
	auto go = std::make_shared<dae::GameObject>();

	auto col = go->AddComponent<CollisionComponent>();
	col->SetSize(32, 32);
	col->SetOffset(0, 0);
	auto rc = go->AddComponent<dae::RenderComponent>();
	rc->SetTexture("\\Sprites\\World\\Tile.png");
	rc->SetDimensions(32, 32);
	go->SetTag("WALL");
	go->GetTransform()->SetLocalPosition(loc.x, loc.y, 0);
	scene.Add(go);


}
