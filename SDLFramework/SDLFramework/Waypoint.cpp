#include "Waypoint.h"

Waypoint::Waypoint()
{
}

Waypoint::Waypoint(float x, float y)
{
	distance_ = INT_MAX;
	isDone_ = false;
	position = Vector2(x, y);
}

Waypoint::~Waypoint()
{
	delete previousWaypoint_;
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

int Waypoint::getDistance()
{
	return distance_;
}

void Waypoint::setDistance(int distance)
{
	distance_ = distance;
}

Waypoint* Waypoint::getPreviousWaypoint()
{
	return previousWaypoint_;
}

void Waypoint::setPreviousWaypoint(Waypoint* waypoint)
{
	previousWaypoint_ = waypoint;
}

bool Waypoint::isDone()
{
	return isDone_;
}

void Waypoint::isDone(bool isDone)
{
	isDone_ = isDone;
}
