#pragma once
#include <vector>
#include <queue>
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

	std::queue<Waypoint*> shortestPath_;
};


