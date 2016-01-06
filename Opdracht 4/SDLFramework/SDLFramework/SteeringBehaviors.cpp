#include "SteeringBehaviors.h"

SteeringBehaviors::SteeringBehaviors()
{
}

SteeringBehaviors::~SteeringBehaviors()
{
}

// Blz 103
Vector2 SteeringBehaviors::Calculate()
{
	/*
	//reset the force.
	m_vSteeringForce.Zero();

	SVector2D force;
	*/


	return Vector2();
}

// Blz 94
// Slim naar target
Vector2 SteeringBehaviors::Persuit(Vector2 v)
{
	return v;
}

// Blz 97
// Beetje ronddwalen
Vector2 SteeringBehaviors::Wander(Vector2 v)
{
	//first, add a small random vector to the target’s position (RandomClamped
	//returns a value between -1 and 1)
	/*m_vWanderTarget += SVector2D(RandomClamped() * m_dWanderJitter,
		RandomClamped() * m_dWanderJitter);

	//reproject this new vector back onto a unit circle
	m_vWanderTarget.Normalize();

	//increase the length of the vector to the same as the radius
	//of the wander circle
	m_vWanderTarget *= m_dWanderRadius;

	//move the target into a position WanderDist in front of the agent
	SVector2D targetLocal = m_vWanderTarget + SVector2D(m_dWanderDistance, 0);
	//project the target into world space
	SVector2D targetWorld = PointToWorldSpace(targetLocal,
		m_pVehicle->Heading(),
		m_pVehicle->Side(),
		m_pVehicle->Pos());
	//and steer toward it
	return targetWorld - m_pVehicle->Pos();*/

	return v;
}

// Boek blz 92
// Dom weg van target
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


