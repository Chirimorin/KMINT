#include "FindWeaponState.h"
#include "AttackCowState.h"
#include "Graph.h"
#include "Entity.h"
#include "Weapon.h"
#include <iostream>

FindWeaponState::FindWeaponState() : BaseState(0, 0, 255)
{
}

FindWeaponState::~FindWeaponState()
{
}

void FindWeaponState::Move(Entity* obj, Graph* graph)
{
	if (graph->setShortestPath(obj->getWaypoint(), graph->getWeapon()->getWaypoint()))
	{
		obj->MoveTo(graph->getFirstWaypointShortestPath());
	}

	if (obj->getWaypoint() == graph->getWeapon()->getWaypoint()) {
		graph->moveWeapon();
		std::cout << "Rabbit: Found weapon!\n";
		//obj->setState(new AttackCowState());
	}
}

