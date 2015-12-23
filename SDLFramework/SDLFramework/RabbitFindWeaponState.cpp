#include "RabbitFindWeaponState.h"
#include "RabbitAttackState.h"

RabbitFindWeaponState::RabbitFindWeaponState() : RabbitState(0, 0, 255) // TODO: misschien kleur aanpassen in verband met veel states
{
}

void RabbitFindWeaponState::Move(Entity* obj, Graph* graph)
{
	//TODO: als de haas het wapen heeft gevonden, dan gaat ie aanvallen

	/*if ()
	{
	obj->setState(new RabbitAttackState());
	}*/
}
