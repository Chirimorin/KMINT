#include "RabbitWanderingState.h"
#include "Rabbit.h"
#include <iostream>
#include "RabbitFleeState.h"
#include "Random.h"

RabbitWanderingState::RabbitWanderingState() : RabbitState(255, 255, 255)
{
	SetRandomDestination();
}

void RabbitWanderingState::Update(Entity* obj)
{
	Vector2 toCow = obj->GetTarget()->GetPosition() - obj->GetPosition();
	if (MagnitudeWrapped(toCow) < 150.f)
	{
		obj->SetState(new RabbitFleeState());
	}
}

Vector2 RabbitWanderingState::CalculateForce(Entity* obj)
{
	// Loop richting de destination
	Vector2 result = destination_ - obj->GetPosition();
	result = WrappedDistance(result);

	// Kies een nieuwe destination als de rabbit er is
	while (Magnitude(result) < 50)
	{
		SetRandomDestination();
		result = destination_ - obj->GetPosition();
		result = WrappedDistance(result);
	}

	// Niet te snel rennen
	result = Normal(result) * 30;

	// Als de rabbit snel loopt, rem af
	if (Magnitude(obj->GetVelocity()) > 50)
	{
		result += (obj->GetVelocity() * -0.25f);
	}
	// Als de rabbit langzaam loopt, ga iets sneller
	else if (Magnitude(obj->GetVelocity()) < 25)
	{
		result += (obj->GetVelocity() * 0.25f);
	}

	return result;
}

void RabbitWanderingState::SetRandomDestination()
{
	destination_ = { 0.f,0.f };
	destination_.x += Random::getRandomNumber(0, 800);
	destination_.y += Random::getRandomNumber(0, 600);
}