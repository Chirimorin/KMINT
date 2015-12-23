#include "RabbitWanderingState.h"
#include "RabbitFleeState.h"
#include "RabbitFindPillState.h"
#include "RabbitFindWeaponState.h"

RabbitWanderingState::RabbitWanderingState() : RabbitState(255, 255, 255)
{
}

void RabbitWanderingState::Move(Entity* obj, Graph* graph)
{
	//TODO: als de haas de koe door heeft, dan een van de onder staande opties
	
	/*if ()
	{
	obj->setState(new RabbitFleeState());
	}*/

	/*if ()
	{
	obj->setState(new RabbitFindPillState());
	}*/

	/*if ()
	{
	obj->setState(new RabbitFindWeaponState());
	}*/
}