#include "RabbitWanderingWithPillState.h"
#include "RabbitWanderingState.h"

RabbitWanderingWithPillState::RabbitWanderingWithPillState() : RabbitState(0, 0, 255) // TODO: misschien kleur aanpassen in verband met veel states
{
}

void RabbitWanderingWithPillState::Move(Entity* obj, Graph* graph)
{
	//TODO: als de koe de pil heeft gepakt en slaapt, dan ga de haas wandelen

	/*if ()
	{
	obj->setState(new RabbitWanderinState());
	}*/
}
