#pragma once
#include "IGameObject.h"
#include "Entity.h"
#include "Waypoint.h"

class Cow : public Entity
{
public:
	Cow(Waypoint* waypoint);
	~Cow();

	void Update(float deltaTime) override;

	void Move(Graph* graph) override;
	void MoveTo(Waypoint* waypoint) override;

	void resetState() override;
	bool getAttacked() override { return false; }; // TODO: nog goed maken
};

