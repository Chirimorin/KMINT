#include "Waypoint.h"

Waypoint::Waypoint()
{
	distance_ = INT_MAX;
	isDone_ = false;
}

Waypoint::Waypoint(float x, float y)
{
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

bool Waypoint::getIsDone()
{
	return isDone_;
}

void Waypoint::setIsDone(bool isDone)
{
	isDone_ = isDone;
}
