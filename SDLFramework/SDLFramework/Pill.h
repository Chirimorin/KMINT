#pragma once
#include "IGameObject.h"
#include "Waypoint.h"

class Pill : public IGameObject
{
public:
	Pill(Waypoint* waypoint);
	~Pill();

	void Update(float deltaTime);

	Waypoint* getWaypoint();

private:
	Waypoint* waypoint_ = nullptr;
};

