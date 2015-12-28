#include "RabbitFindWeaponState.h"
#include "RabbitAttackState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Weapon.h"

RabbitFindWeaponState::RabbitFindWeaponState() : RabbitState(255, 75, 0) // TODO: misschien kleur aanpassen in verband met veel states
{
	isAttacking_ = false;
}

void RabbitFindWeaponState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getWeapon()->getWaypoint())) {
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getWeapon()->getWaypoint()) {
		
		// TODO: de haas gaat aanvallen en kan niet aangevallen worden door de koe
		
		obj->setState(new RabbitAttackState());
	}
}
