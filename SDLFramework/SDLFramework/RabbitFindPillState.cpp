#include "RabbitFindPillState.h"
#include "RabbitWanderingWithPillState.h"

RabbitFindPillState::RabbitFindPillState() : RabbitState(0, 0, 255) // TODO: misschien kleur aanpassen in verband met veel states
{
}

void RabbitFindPillState::Move(Entity* obj, Graph* graph)
{
	//TODO: als de haas de pil heeft gevonden, dan state aanpassen

	/*if ()
	{
	obj->setState(new RabbitWanderingWithPillState());
	}*/
}
