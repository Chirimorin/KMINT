#pragma once
#include "Vector2.h"
#include "Edge.h"
#include <vector>

class Waypoint
{
public:
	Waypoint();
	Waypoint(float x, float y);
	~Waypoint();

	Vector2 getPosition();
	void addEdge(Edge* edge);

	std::vector<Edge*> getEdges();

	float getDistance();
	void setDistance(Waypoint* endPoint);

	Waypoint* getPreviousWaypoint();
	void setPreviousWaypoint(Waypoint* waypoint);

private:
	Vector2 position;

	std::vector<Edge*> edges;

	// Voor het bepalen van het kortste pad
	float distance_;
	Waypoint* previousWaypoint_ = nullptr;
};

