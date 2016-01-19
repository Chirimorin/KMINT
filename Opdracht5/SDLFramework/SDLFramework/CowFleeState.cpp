#include "CowFleeState.h"
#include "Cow.h"
#include "CowWanderingState.h"

CowFleeState::CowFleeState() : CowState()
{
}

void CowFleeState::Update(Entity* obj)
{
	Vector2 toCow = obj->GetTarget()->GetPosition() + obj->GetTarget()->GetVelocity() - obj->GetPosition();
	if (MagnitudeWrapped(toCow) > 200.f)
	{
		obj->SetState(new CowWanderingState());
	}
}

Vector2 CowFleeState::CalculateForce(Entity* obj)
{
	// loop zo recht mogelijk weg van de koe
	Vector2 toCow = obj->GetTarget()->GetPosition() - obj->GetPosition();
	return WrappedDistance(toCow) * -1;
}
