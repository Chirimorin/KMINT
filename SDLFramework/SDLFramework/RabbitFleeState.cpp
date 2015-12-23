#include "RabbitFleeState.h"
#include "RabbitFindWeaponState.h"
#include "RabbitFindPillState.h"

RabbitFleeState::RabbitFleeState() : RabbitState(0, 255, 0) // TODO: misschien kleur aanpassen in verband met veel states
{
}

void RabbitFleeState::Move(Entity* obj, Graph* graph)
{
	//TODO: als de haas het wapen ziet

	/*if ()
	{
	obj->setState(new RabbitFindWeaponState());
	}*/

	//TODO: als de haas de slaappil ziet

	/*if ()
	{
	obj->setState(new RabbitFindPillState());
	}*/
}

