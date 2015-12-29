#pragma once
#include "vector2.h"

class SteeringBehaviors
{
public:
	SteeringBehaviors();
	~SteeringBehaviors();

	Vector2 Calculate();

	Vector2 Persuit(Vector2 v);
	Vector2 Wander(Vector2 v);
	Vector2 Flee(Vector2 v);
};

