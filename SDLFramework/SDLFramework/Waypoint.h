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
private:
	Vector2 position;

	std::vector<Edge*> edges;
};

