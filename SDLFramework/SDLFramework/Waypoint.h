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

	int getDistance();
	void setDistance(int distance);

	Waypoint* getPreviousWaypoint();
	void setPreviousWaypoint(Waypoint* waypoint);

	bool isDone();
	void isDone(bool isDone);

private:
	Vector2 position;

	std::vector<Edge*> edges;

	// Voor het bepalen van het kortste pad
	int distance_;
	Waypoint* previousWaypoint_ = nullptr;
	bool isDone_;
};

