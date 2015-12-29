#pragma once
class Waypoint;

class Edge
{
public:
	Edge(Waypoint* waypoint1, Waypoint* waypoint2);

	Waypoint* getWaypoint1();
	Waypoint* getWaypoint2();
	float getWeight();

private:
	Waypoint* w1;
	Waypoint* w2;
	float weight;
};

