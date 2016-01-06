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
private:
	double wanderRadius_; // This is the radius of the constraining circle.
	double wanderDistance_; // This is the distance the wander circle is projected in front of the agent.
	double wanderJitter_; // The maximum amount of random displacement that can be added to the target each second.
};

