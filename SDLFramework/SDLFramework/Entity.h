#pragma once
#include "IGameObject.h"

class Graph;
class Waypoint;

class Entity : public IGameObject
{
public:
	Entity();
	~Entity();

	virtual void Move(Graph* graph) {};
	virtual void MoveTo(Waypoint* waypoint);
	Waypoint* getWaypoint() { return waypoint_; }

	virtual void setState(BaseState* state);
protected:
	Waypoint* waypoint_ = nullptr;
	BaseState* state_;
};

