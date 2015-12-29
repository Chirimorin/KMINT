#include "SteeringBehaviors.h"

SteeringBehaviors::SteeringBehaviors()
{
}

SteeringBehaviors::~SteeringBehaviors()
{
}

Vector2 SteeringBehaviors::Calculate()
{
	/*
	//reset the force.
	m_vSteeringForce.Zero();

	SVector2D force;
	*/


	return Vector2();
}

Vector2 SteeringBehaviors::Persuit(Vector2 v)
{
	return v;
}

Vector2 SteeringBehaviors::Wander(Vector2 v)
{
	return v;
}

// Boek blz 92
Vector2 SteeringBehaviors::Flee(Vector2 targetPos)
{
	/*
	//only flee if the target is within 'panic distance'. Work in distance
	//squared space.
	const double PanicDistanceSq = 100.0 * 100.0;
	if (Vec2DDistanceSq(m_pVehicle->Pos(), target) > PanicDistanceSq)
	{
		return Vector2(0, 0);
	}

	Vector2 DesiredVelocity = Vec2DNormalize(m_pVehicle->Pos() - targetPos) * m_pVehicle->MaxSpeed();

	return (DesiredVelocity - m_pVehicle->Velocity());
	*/

	return Vector2(0, 0);
}


