#include "SteeringBehaviors.h"
#include "Random.h"

SteeringBehaviors::SteeringBehaviors()
{
	// TODO: Goede waardes
	wanderRadius_ = 50; 
	wanderDistance_ = 50;
	wanderJitter_ = 10;
}

SteeringBehaviors::~SteeringBehaviors()
{
}

// Blz 103 (blz 122 ?)
Vector2 SteeringBehaviors::Calculate()
{
	/*
	//reset the force.
	m_vSteeringForce.Zero();

	SVector2D force;
	if (On(persuit)) { 
		//...
		return m_vSteeringForce;
	}
	if (On(wander)) {
		//...
		return m_vSteeringForce;
	}
	if (On(flee)) {
		//...
		return m_vSteeringForce;
	}
	*/

	return Vector2(10, 10);
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
	/*//first, add a small random vector to the target’s position (RandomClamped
	//returns a value between -1 and 1)
	wanderTarget_ += Vector2(Random::getRandomNumber(-1, 1) * wanderJitter_, Random::getRandomNumber(-1, 1) * wanderJitter_);

	//reproject this new vector back onto a unit circle
	m_vWanderTarget.Normalize();

	//increase the length of the vector to the same as the radius
	//of the wander circle
	m_vWanderTarget *= wanderRadius_;

	//move the target into a position WanderDist in front of the agent
	Vector2 targetLocal = m_vWanderTarget + Vector2(wanderDistance_, 0);
	//project the target into world space
	Vector2 targetWorld = PointToWorldSpace(targetLocal,
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


