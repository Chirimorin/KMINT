#include "CowFleeState.h"
#include "Cow.h"
#include "CowWanderingState.h"

CowFleeState::CowFleeState() : CowState()
{
}

void CowFleeState::Update(Entity* obj)
{
	/*Vector2 toCow = obj->GetTarget()->GetPosition() + obj->GetTarget()->GetVelocity() - obj->GetPosition();
	if (MagnitudeWrapped(toCow) > 200.f)
	{
		obj->SetState(new CowWanderingState());
	}*/


	// TODO:Als de haas de koe heeft gevangen, krijgt de haas 10 punten en worden de koe en de haas gerespawned.
}

Vector2 CowFleeState::CalculateForce(Entity* obj)
{
	// loop zo recht mogelijk weg van de haas
	Vector2 toRabbit = obj->GetTarget()->GetPosition() - obj->GetPosition();
	return WrappedDistance(toRabbit) * -1;
}