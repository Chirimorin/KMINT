#include "Waypoint.h"

Waypoint::Waypoint()
{
}

Waypoint::Waypoint(float x, float y)
{
	position = Vector2(x, y);
}

Waypoint::~Waypoint()
{
}

Vector2 Waypoint::getPosition()
{
	return position;
}

void Waypoint::addEdge(Edge* edge)
{
	edges.push_back(edge);
}