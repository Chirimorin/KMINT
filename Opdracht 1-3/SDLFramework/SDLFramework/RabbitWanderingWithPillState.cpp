#include "RabbitWanderingWithPillState.h"
#include "RabbitWanderingState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Cow.h"
#include "Random.h"

RabbitWanderingWithPillState::RabbitWanderingWithPillState(Rabbit* rabbit) : RabbitState(rabbit, 0, 0, 255) // TODO: misschien kleur aanpassen in verband met veel states
{
	isAttacking_ = false;
}

void RabbitWanderingWithPillState::Move(Entity* obj, Graph* graph)
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

	// ALS DE KOE DE PIL HEEFT GEPAKT EN SLAAPT
	// TODO: haas heeft geen slaap pil meer, want die is gebruikt
	// TODO: haas gaat weer wandelen
	if (obj->getWaypoint() == graph->getCow()->getWaypoint()) {
		obj->setState(new RabbitWanderingState(rabbit_));
	}
}
