#include "Graph.h"
#include "Edge.h"
#include "Waypoint.h"
#include "FWApplication.h"
#include "Random.h"
#include <algorithm>
#include <queue>

#include <iostream>

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

	/*waypoints.at(0)->setDistance(4);
	waypoints.at(1)->setDistance(2);
	waypoints.at(2)->setDistance(6);
	waypoints.at(3)->setDistance(3);
	waypoints.at(4)->setDistance(5);
	waypoints.at(5)->setDistance(0);
	waypoints.at(6)->setDistance(1);*/

	//setShortestPath(waypoints.at(0), waypoints.at(4));
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
	std::queue<Waypoint*> shortestPath;

	struct GreaterThanByDistance {
		bool operator()(Waypoint* w1,Waypoint* w2) const {
			return w1->getDistance() > w2->getDistance();
		}
	};

	std::priority_queue<Waypoint*, std::vector<Waypoint*>, GreaterThanByDistance> queue;

	/*std::for_each(waypoints.begin(), waypoints.end(), [&queue](Waypoint* w)
	{
		std::cout << w << "d: " << w->getDistance() << std::endl;
		queue.push(w);
	});*/

	/*std::cout << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < waypoints.size(); i++) {
		std::cout << queue.top() << "d: " << queue.top()->getDistance() << std::endl;
		queue.pop();
	}*/

	// Zet de afstand van het eerste waypoint op 0 en zet het waypoint in de queue
	start->setDistance(0);
	queue.push(start);

	while (!queue.empty()) {
		Waypoint* waypoint = queue.top();
		queue.pop();

		std::vector<Edge*> edges = waypoint->getEdges();
		std::for_each(edges.begin(), edges.end(), [waypoint, &queue](Edge* e) 
		{
			// Bepaal buur waypoint
			Waypoint* waypoint2 = e->getWaypoint1();
			if (waypoint == waypoint2) {
				waypoint2 = e->getWaypoint2();
			}

			// TODO:: MOET NOG MET VECTOR2 ???
			// Geschatte afstand van deze waypoint naar doel
			int deltaX = abs(waypoint->getPosition().x - waypoint2->getPosition().x);
			int deltaY = abs(waypoint->getPosition().y - waypoint2->getPosition().y);
			int estimatedDistance = sqrt((deltaX * deltaX) + (deltaY * deltaY));

			int distance = waypoint->getDistance() + estimatedDistance; 
			//std::cout << "Distance: " << distance << "\n";

			// Bepaalt de kleinste afstand
			if (distance < waypoint2->getDistance()) {
				waypoint2->setDistance(distance);
				waypoint2->setPreviousWaypoint(waypoint);
			}

			// Voegt eventueel waypoint toe aan de queue
			if (!waypoint2->isDone()) {
				queue.push(waypoint2);
			}
		});

		waypoint->isDone(true);
	}

	std::vector<Waypoint*> route;

	// Bepaalt kortste route
	Waypoint* currentWaypoint = end;
	while (currentWaypoint != nullptr) {
		route.push_back(currentWaypoint);
		currentWaypoint = currentWaypoint->getPreviousWaypoint();
	}

	// Zet de waypoints in de goede volgorde
	std::reverse(route.begin(), route.end());


	//std::cout << "KORTSTE PAD: \n";

	std::for_each(waypoints.begin(), waypoints.end(), [&shortestPath](Waypoint* w) {
		// Zet waypoints in queue
		shortestPath.push(w);

		//std::cout << "x: " << w->getPosition().x << " y: " << w->getPosition().y << "\n";
		
		// Reset waypoint data
		w->setDistance(INT_MAX);
		w->setPreviousWaypoint(nullptr);
		w->isDone(false);
	});
	shortestPath_ = shortestPath;

}

Waypoint* Graph::getRandomWaypoint()
{
	//TODO:: Rekening houden dat koe en haas niet meteen op hetzelfde waypoint komen
	return waypoints.at(Random::getRandomNumber(0, waypoints.size() - 1));
}

Waypoint* Graph::getFirstWaypointShortestPath()
{
	Waypoint* firstWaypoint = shortestPath_.front();
	shortestPath_.pop();
	return firstWaypoint;
}
