#include "RabbitWanderingWithPillState.h"
#include "RabbitWanderingState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Random.h"

RabbitWanderingWithPillState::RabbitWanderingWithPillState() : RabbitState(0, 0, 255) // TODO: misschien kleur aanpassen in verband met veel states
{
	isAttacking_ = false;
	getAttacked_ = false;
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

	//TODO: als de koe de pil heeft gepakt en slaapt, dan WanderingState

	//*if () {
	obj->setState(new RabbitWanderingState());
	//}
}
