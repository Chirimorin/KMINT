#pragma once
#include "IGameObject.h"
#include "Waypoint.h"
#include "Entity.h"

class Graph;

class Cow : public Entity
{
public:
	Cow(Waypoint* waypoint);
	~Cow();

	void Update(float deltaTime) override;

	void Move(Graph* graph) override;
};

