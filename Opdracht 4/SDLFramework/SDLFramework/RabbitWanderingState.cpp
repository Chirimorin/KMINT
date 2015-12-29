#include "RabbitWanderingState.h"
#include "Rabbit.h"

RabbitWanderingState::RabbitWanderingState() : RabbitState(255, 255, 255)
{
}

void RabbitWanderingState::Move(Entity* obj)
{
	// TODO: de haas beweegt zich volgens wander

	// TODO: als de haas de koe ziet, dan veranderd de state naar flee

}