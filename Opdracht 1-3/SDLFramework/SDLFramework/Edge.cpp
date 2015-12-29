#include "Edge.h"
#include "Waypoint.h"

Edge::Edge(Waypoint* waypoint1, Waypoint* waypoint2) : 
	w1(waypoint1), 
	w2(waypoint2)
{
	weight = Magnitude(waypoint1->getPosition() - waypoint2->getPosition());
	waypoint1->addEdge(this);
	waypoint2->addEdge(this);
}

Waypoint* Edge::getWaypoint1()
{
	return w1;
}

Waypoint* Edge::getWaypoint2()
{
	return w2;
}

float Edge::getWeight()
{
	return weight;
}