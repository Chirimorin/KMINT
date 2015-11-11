#pragma once
#include "IGameObject.h"
#include "Waypoint.h"

class Rabbit : public IGameObject
{
public:
	Rabbit(Waypoint* waypoint);
	~Rabbit();

	void Update(float deltaTime);

private:
	Waypoint* waypoint_ = nullptr;
};

