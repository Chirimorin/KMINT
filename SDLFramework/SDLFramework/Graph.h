#pragma once
#include <vector>
class FWApplication;
class Edge;
class Waypoint;

class Graph
{
public:
	Graph();
	~Graph();

	void DrawGraph(FWApplication* application);
private:
	std::vector<Edge*> edges;
	std::vector<Waypoint*> waypoints;
};

