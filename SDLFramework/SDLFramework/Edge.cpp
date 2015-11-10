#include "Edge.h"
#include "Waypoint.h"

Edge::Edge(Waypoint* waypoint1, Waypoint* waypoint2) : 
	w1(waypoint1), 
	w2(waypoint2)
{
	// TODO: weight berekenen
}

Waypoint* Edge::getWaypoint1()
{
	return w1;
}

Waypoint* Edge::getWaypoint2()
{
	return w2;
}

int Edge::getWeight()
{
	return weight;
}