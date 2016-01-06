#include "RabbitFindPillState.h"
#include "RabbitWanderingWithPillState.h"
#include "Rabbit.h"
#include "Graph.h"
#include "Pill.h"

RabbitFindPillState::RabbitFindPillState() : RabbitState(225, 255, 0) // TODO: misschien kleur aanpassen in verband met veel states
{
	isAttacking_ = false;
}

void RabbitFindPillState::Move(Entity* obj, Graph* graph)
{
	timer_++;
	// TODO: goede waarden instellen
	if (timer_ == 2 && chanceToFindPillState_ <= 85) {
		chanceToFindPillState_ += 5;
		printf("chanceToFindPillState + 5 \n");
	}

	if (graph->setShortestPath(obj->getWaypoint(), graph->getPill()->getWaypoint())) {
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getPill()->getWaypoint()) {
		
		// TODO: haas kan niet meer worden aangevallen zo lang hij de slaap pil heeft
		// TODO: de pil ergens anders plaatsen (ver weg van haas)

		obj->setState(new RabbitWanderingWithPillState());
		graph->movePill();
	}
}