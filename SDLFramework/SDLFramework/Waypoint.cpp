#include "Waypoint.h"
#include <limits>

Waypoint::Waypoint()
{
}

Waypoint::Waypoint(float x, float y)
{
	distance_ = std::numeric_limits<float>::infinity();
	position = Vector2(x, y);
}

Waypoint::~Waypoint()
{
	previousWaypoint_ = nullptr;
}

Vector2 Waypoint::getPosition()
{
	return position;
}

void Waypoint::addEdge(Edge* edge)
{
	edges.push_back(edge);
}

std::vector<Edge*> Waypoint::getEdges()
{
	return edges;
}

float Waypoint::getDistance()
{
	return distance_;
}

void Waypoint::setDistance(Waypoint* endPoint)
{
	distance_ = Magnitude(position - endPoint->getPosition());
	previousWaypoint_ = nullptr;
}

Waypoint* Waypoint::getPreviousWaypoint()
{
	return previousWaypoint_;
}

void Waypoint::setPreviousWaypoint(Waypoint* waypoint)
{
	previousWaypoint_ = waypoint;
}
