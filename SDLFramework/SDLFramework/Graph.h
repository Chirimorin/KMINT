#pragma once
#include <vector>
#include <stack>
class Cow;
class Rabbit;
class Weapon;
class Pill;
class FWApplication;
class Edge;
class Waypoint;

class Graph
{
public:
	Graph(FWApplication* application);
	~Graph();

	void DrawGraph();

	void setShortestPath(Waypoint* start, Waypoint* end);
	
	Waypoint* getRandomWaypoint(std::vector<Waypoint*> occupiedWaypoints);
	Waypoint* getFirstWaypointShortestPath();

	void setPill(Pill* pill) { pill_ = pill; }
	Pill* getPill() { return pill_; }
	void movePill();

	void setWeapon(Weapon* weapon) { weapon_ = weapon; }
	Weapon* getWeapon() { return weapon_; }
	void moveWeapon();

	void setCow(Cow* cow) { cow_ = cow; }
	Cow* getCow() { return cow_; }

	void setRabbit(Rabbit* rabbit) { rabbit_ = rabbit; }
	Rabbit* getRabbit() { return rabbit_; }
private:
	FWApplication* application_;

	std::vector<Edge*> edges;
	std::vector<Waypoint*> waypoints;
	std::stack<Waypoint*> shortestPath_;

	Pill* pill_ = nullptr;
	Weapon* weapon_ = nullptr;
	Cow* cow_ = nullptr;
	Rabbit* rabbit_ = nullptr;
};


