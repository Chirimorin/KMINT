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

	std::vector<Waypoint*> getShortestPath(Waypoint* start, Waypoint* end);

private:
	std::vector<Edge*> edges;
	std::vector<Waypoint*> waypoints;
};


