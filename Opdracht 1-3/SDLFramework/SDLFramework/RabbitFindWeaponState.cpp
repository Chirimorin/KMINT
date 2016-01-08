#include "RabbitFindWeaponState.h"
#include "RabbitAttackState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Weapon.h"

#include <iostream>

RabbitFindWeaponState::RabbitFindWeaponState(Rabbit* rabbit) : RabbitState(rabbit, 255, 75, 0) // TODO: misschien kleur aanpassen in verband met veel states
{
	isAttacking_ = false;
	std::cout << "Haas: find weapon \n";
}

void RabbitFindWeaponState::Move(Entity* obj, Graph* graph)
{
	timer_++;
	// TODO: goede waarden instellen
	if (timer_ == 2 && chanceToFindWeaponState_ <= 85) {
		chanceToFindWeaponState_ += 5;;
		printf("chanceToFindWeaponState + 5 \n");
	}

	if (graph->setShortestPath(obj->getWaypoint(), graph->getWeapon()->getWaypoint())) {
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getWeapon()->getWaypoint()) {
		
		// TODO: de haas gaat aanvallen en kan niet aangevallen worden door de koe
		// TODO: wapen ergens plaatsen (ver weg van haas)

		obj->setState(new RabbitAttackState(rabbit_));
		graph->moveWeapon();
	}
}
