#include "Graph.h"
#include "Edge.h"
#include "Waypoint.h"
#include "FWApplication.h"
#include <algorithm>


Graph::Graph()
{
	waypoints.push_back(new Waypoint(125.0f, 115.0f));
	waypoints.push_back(new Waypoint(423.0f, 88.0f));
	waypoints.push_back(new Waypoint(203.0f, 199.0f));
	waypoints.push_back(new Waypoint(725.0f, 306.0f));
	waypoints.push_back(new Waypoint(337.0f, 306.0f));
	waypoints.push_back(new Waypoint(550.0f, 500.0f));
	waypoints.push_back(new Waypoint(150.0f, 400.0f));
	
	edges.push_back(new Edge(waypoints.at(0), waypoints.at(2)));
	edges.push_back(new Edge(waypoints.at(0), waypoints.at(6)));
	edges.push_back(new Edge(waypoints.at(1), waypoints.at(2)));
	edges.push_back(new Edge(waypoints.at(1), waypoints.at(5)));
	edges.push_back(new Edge(waypoints.at(2), waypoints.at(4)));
	edges.push_back(new Edge(waypoints.at(3), waypoints.at(5)));
	edges.push_back(new Edge(waypoints.at(4), waypoints.at(6)));
	edges.push_back(new Edge(waypoints.at(4), waypoints.at(5)));
}


Graph::~Graph()
{
	std::for_each(edges.begin(), edges.end(), [](Edge* e)
	{
		delete e;
	});

	std::for_each(waypoints.begin(), waypoints.end(), [](Waypoint* w)
	{
		delete w;
	});
}

void Graph::DrawGraph(FWApplication* application)
{
	application->SetColor(Color(0, 0, 128, 255));
	std::for_each(edges.begin(), edges.end(), [application](Edge* e)
	{
		Vector2 pos1 = e->getWaypoint1()->getPosition();
		Vector2 pos2 = e->getWaypoint2()->getPosition();

		application->DrawLine(
			static_cast<int>(pos1.x), 
			static_cast<int>(pos1.y), 
			static_cast<int>(pos2.x), 
			static_cast<int>(pos2.y)
			);
	});

	application->SetColor(Color(0, 0, 0, 255));

	std::for_each(waypoints.begin(), waypoints.end(), [application](Waypoint* w) 
	{
		Vector2 pos = w->getPosition();
		application->DrawRect(
			static_cast<int>(pos.x) - 5, 
			static_cast<int>(pos.y) - 5,
			10, 
			10, 
			true
			);
	});
}