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

private:
	Waypoint* waypoint_ = nullptr;
};

