#pragma once
#include "IGameObject.h"
#include "Waypoint.h"

class Weapon : public IGameObject
{
public:
	Weapon(Waypoint* waypoint);
	~Weapon();

	void Update(float deltaTime);

	Waypoint* getWaypoint();
	void setWaypoint(Waypoint* waypoint);

private:
	Waypoint* waypoint_ = nullptr;
};

