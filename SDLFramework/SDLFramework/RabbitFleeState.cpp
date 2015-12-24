#include "RabbitFleeState.h"
#include "RabbitFindWeaponState.h"
#include "RabbitFindPillState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Pill.h"
#include "Weapon.h"
#include "Random.h"

#include <algorithm>

RabbitFleeState::RabbitFleeState() : RabbitState(127, 0, 255) // TODO: misschien kleur aanpassen in verband met veel states
{
}

void RabbitFleeState::Move(Entity* obj, Graph* graph)
{
	Waypoint* waypoint = obj->getWaypoint();
	std::vector<Edge*> edges = waypoint->getEdges();
	Edge* edge = edges.at(Random::getRandomNumber(0, edges.size() - 1));

	if (Random::getRandomNumber(0, 1)) {
		obj->MoveTo(edge->getWaypoint1());
	}
	else {
		obj->MoveTo(edge->getWaypoint2());
	}

	bool seesPill = false;
	bool seesWeapon = false;

	std::for_each(edges.begin(), edges.end(), [&seesPill, &seesWeapon, waypoint, graph](Edge* e) {
		Waypoint* currentWaypoint = e->getWaypoint1();
		if (currentWaypoint == waypoint) {
			currentWaypoint = e->getWaypoint2();
		}

		if (graph->getPill()->getWaypoint() == currentWaypoint) {
			seesPill = true;
		}
		if (graph->getWeapon()->getWaypoint() == currentWaypoint) {
			seesWeapon = true;
		}
	});

	// TODO: kans op bepaalde keuze aanpassen afhankelijk van succes
	if (seesPill && seesWeapon) {
		if (Random::getRandomNumber(0, 1)) {
			obj->setState(new RabbitFindPillState()); // Hier moet denk ik ook een kans komen dat hij de pil gaat zoeken
		}
		else {
			obj->setState(new RabbitFindWeaponState()); // Hier moet denk ik ook een kans komen dat hij het wapen gaat zoeken
		}
	}
	else if (seesPill) {
		obj->setState(new RabbitFindPillState()); // Hier moet denk ik ook een kans komen dat hij de pil gaat zoeken
	}
	else if (seesWeapon) {
		obj->setState(new RabbitFindWeaponState()); // Hier moet denk ik ook een kans komen dat hij het wapen gaat zoeken
	}

}

