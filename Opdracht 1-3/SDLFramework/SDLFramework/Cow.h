#pragma once
#include "IGameObject.h"
#include "Entity.h"
#include "Waypoint.h"

class Cow : public Entity
{
public:
	Cow(Graph* graph, Waypoint* waypoint);
	~Cow();

	void Update(float deltaTime) override;

	void Move(Graph* graph) override;
	void MoveTo(Waypoint* waypoint) override;

	void reset(Graph* graph) override;
	bool getAttacked(Graph* graph) override;
};

