#pragma once
class Waypoint;

struct Edge
{
	Edge(Waypoint* waypoint1, Waypoint* waypoint2);

	Waypoint* getWaypoint1();
	Waypoint* getWaypoint2();
	int getWeight();

private:
	Waypoint* w1;
	Waypoint* w2;
	int weight;
};

