#include "Graph.h"
#include "Edge.h"
#include "Waypoint.h"
#include "FWApplication.h"
#include "Random.h"
#include <algorithm>
#include <queue>

#include <iostream>
#include <unordered_map>

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

void Graph::setShortestPath(Waypoint* start, Waypoint* end)
{
	std::unordered_map<Waypoint*, float> distances;
	distances[start] = 0.0f;

	struct GreaterThanByDistance {
		bool operator()(Waypoint* w1,Waypoint* w2) const {
			return w1->getDistance() > w2->getDistance();
		}
	};

	std::priority_queue<Waypoint*, std::vector<Waypoint*>, GreaterThanByDistance> queue;

	std::for_each(waypoints.begin(), waypoints.end(), [end](Waypoint* w) {
		w->setDistance(end);
	});

	queue.push(start);

	while (!queue.empty())
	{
		Waypoint* current = queue.top();
		queue.pop();

		if (current == end)
			break;

		std::vector<Edge*> edges = current->getEdges();
		std::for_each(edges.begin(), edges.end(), [&distances, &queue, current](Edge* e)
		{
			Waypoint* newPoint = e->getWaypoint1();
			if (newPoint == current)
				newPoint = e->getWaypoint2();

			if (!distances.count(newPoint))
				queue.push(newPoint);

			float distanceFromStart = e->getWeight() + distances[current];
			std::cout << current << ": " << distanceFromStart << std::endl;

			if ((distances.count(newPoint) && 
				 distanceFromStart < distances[newPoint]) ||
				 !distances.count(newPoint))
			{
				distances[newPoint] = distanceFromStart;
				newPoint->setPreviousWaypoint(current);
			}
		});
	}

	std::cout << " ---------------------------------- \n";

	shortestPath_.empty();
	Waypoint* current = end;

	while (current != start) {
		std::cout << current << ": " << current->getDistance() << std::endl;
		shortestPath_.push(current);
		current = current->getPreviousWaypoint();
	}
}

Waypoint* Graph::getRandomWaypoint(std::vector<Waypoint*> occupiedWaypoints)
{
	Waypoint* randomWaypoint = waypoints.at(Random::getRandomNumber(0, waypoints.size() - 1));
	while (std::find(occupiedWaypoints.begin(), occupiedWaypoints.end(), randomWaypoint) != occupiedWaypoints.end()) {
		randomWaypoint = waypoints.at(Random::getRandomNumber(0, waypoints.size() - 1));
	}
	return randomWaypoint;
}

Waypoint* Graph::getFirstWaypointShortestPath()
{
	Waypoint* firstWaypoint = shortestPath_.top();
	shortestPath_.pop();
	return firstWaypoint;
}
