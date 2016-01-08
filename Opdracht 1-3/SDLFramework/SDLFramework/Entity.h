#pragma once
#include "IGameObject.h"
#include "BaseState.h"

//class BaseState;
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
	virtual void reset(Graph* graph) = 0;
	virtual bool getAttacked(Graph* graph) = 0;
	bool isAttacking();
protected:
	Waypoint* waypoint_ = nullptr;
	BaseState* state_;
};

