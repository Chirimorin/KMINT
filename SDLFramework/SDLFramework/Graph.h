#pragma once
#include <vector>
#include <stack>
class FWApplication;
class Edge;
class Waypoint;

class Graph
{
public:
	Graph();
	~Graph();

	void DrawGraph(FWApplication* application);

	void setShortestPath(Waypoint* start, Waypoint* end);

	Waypoint* getRandomWaypoint();
	Waypoint* getFirstWaypointShortestPath();

private:
	std::vector<Edge*> edges;
	std::vector<Waypoint*> waypoints;
	std::stack<Waypoint*> shortestPath_;
};


