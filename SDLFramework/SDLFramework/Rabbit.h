#pragma once
#include "IGameObject.h"
#include "Waypoint.h"

class Rabbit : public IGameObject
{
public:
	Rabbit();
	~Rabbit();

	void Update(float deltaTime);

private:
	Waypoint* waypoint_ = nullptr;
};

