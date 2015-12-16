#pragma once
#include "IGameObject.h"
#include "Entity.h"
#include "Waypoint.h"

class Rabbit : public Entity
{
public:
	Rabbit(Waypoint* waypoint);
	~Rabbit();

	void Update(float deltaTime) override;

	void Move(Graph* graph) override;
	void MoveTo(Waypoint* waypoint) override;

	void resetState() override;
};

