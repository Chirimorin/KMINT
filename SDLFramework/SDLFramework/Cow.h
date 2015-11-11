#pragma once
#include "IGameObject.h"
#include "Waypoint.h"

class Cow : public IGameObject
{
public:
	Cow();
	~Cow();

	void Update(float deltaTime);

private:
	Waypoint* waypoint_ = nullptr;
};

