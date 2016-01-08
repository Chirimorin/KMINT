#include "RabbitFleeState.h"
#include "Rabbit.h"
#include "RabbitWanderingState.h"
#include <iostream>

RabbitFleeState::RabbitFleeState() : RabbitState(255, 128, 128)
{
}

void RabbitFleeState::Update(Entity* obj)
{
	Vector2 toCow = obj->GetTarget()->GetPosition() + obj->GetTarget()->GetVelocity() - obj->GetPosition();
	if (MagnitudeWrapped(toCow) > 200.f)
	{
		obj->SetState(new RabbitWanderingState());
	}
}

Vector2 RabbitFleeState::CalculateForce(Entity* obj)
{
	// loop zo recht mogelijk weg van de koe
	Vector2 toCow = obj->GetTarget()->GetPosition() - obj->GetPosition();
	return WrappedDistance(toCow) * -1;
}
