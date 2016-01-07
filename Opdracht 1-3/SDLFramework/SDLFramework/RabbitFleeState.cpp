#include "RabbitFleeState.h"
#include "RabbitFindWeaponState.h"
#include "RabbitFindPillState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Pill.h"
#include "Weapon.h"
#include "Random.h"

#include <algorithm>

RabbitFleeState::RabbitFleeState(Rabbit* rabbit) : RabbitState(rabbit, 127, 0, 255) // TODO: misschien kleur aanpassen in verband met veel states
{
	isAttacking_ = false;
}

void RabbitFleeState::Move(Entity* obj, Graph* graph)
{
	timer_++;
	// TODO: goede waarden instellen
	if (timer_ == 2 && chanceToFleeState_ <= 85) {
		chanceToFleeState_ += 5;
		printf("chanceToFleeState + 5 \n");
	}

	Waypoint* waypoint = obj->getWaypoint();
	std::vector<Edge*> edges = waypoint->getEdges();
	Edge* edge = edges.at(Random::getRandomNumber(0, edges.size() - 1));

	// TODO: haas van de koe vandaan verplaatsen

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

	// TODO: bij het zien van het wapen / pil rekening houden met of de koe daar is of niet (is de koe daar, dan er niet heen gaan)
	// TODO: kans op bepaalde keuze aanpassen afhankelijk van succes
	if (seesPill && seesWeapon) {
		if (Random::getRandomNumber(0, 1)) {
			obj->setState(new RabbitFindPillState(rabbit_)); // Hier moet denk ik ook een kans komen of hij naar de pil wil gaan of blijft vluchten
		}
		else {
			obj->setState(new RabbitFindWeaponState(rabbit_)); // Hier moet denk ik ook een kans komen of hij naar het wapen wil gaan of blijft vluchten
		}
	}
	else if (seesPill) {
		obj->setState(new RabbitFindPillState(rabbit_)); // Hier moet denk ik ook een kans komen of hij naar de pil wil gaan of blijft vluchten
	}
	else if (seesWeapon) {
		obj->setState(new RabbitFindWeaponState(rabbit_)); // Hier moet denk ik ook een kans komen of hij naar het wapen wil gaan of blijft vluchten
	}

}

