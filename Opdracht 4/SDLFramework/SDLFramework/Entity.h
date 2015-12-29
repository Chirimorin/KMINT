#pragma once
#include "IGameObject.h"
#include "BaseState.h"
#include "SteeringBehaviors.h"
#include "vector2.h"

class Entity : public IGameObject
{
public:
	Entity();
	~Entity();
protected:
	Vector2 velocity_;
	//a normalized vector pointing in the direction the entity is heading.
	Vector2 heading_;
	//a vector perpendicular to the heading vector
	Vector2 side_;

	float mass_;
	//the maximum speed at which this entity may travel.
	float maxSpeed_;
	//the maximum force this entity can produce to power itself
	//(think rockets and thrust)
	float maxForce_;
	//the maximum rate (radians per second) at which this vehicle can rotate
	float maxTurnRate_;

	SteeringBehaviors steering_;
	
	BaseState* state_;
};

