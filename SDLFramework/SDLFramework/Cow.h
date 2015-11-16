#pragma once
#include "IGameObject.h"
#include "Waypoint.h"

class Cow : public IGameObject
{
public:
	Cow(Waypoint* waypoint);
	~Cow();

	void Update(float deltaTime);

	void Move(Waypoint* waypoint);
	Waypoint* getWaypoint();

private:
	Waypoint* waypoint_ = nullptr;
};

