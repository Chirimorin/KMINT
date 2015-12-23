#include "RabbitAttackState.h"
#include "RabbitWanderingState.h"

RabbitAttackState::RabbitAttackState() : RabbitState(255, 0, 0)
{
}

void RabbitAttackState::Move(Entity* obj, Graph* graph)
{
	// TODO: koe aanvallen als deze in een bepaalde range is

	// TODO: als de haas de koe heeft aangevallen, dan state aanpassen

	/*if ()
	{
	obj->setState(new RabbitWanderingState());
	}*/
}