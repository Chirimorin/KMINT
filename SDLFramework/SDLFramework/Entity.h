#pragma once
#include "IGameObject.h"
#include "BaseState.h"

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
	virtual void resetState() = 0;

	bool isAttacking() { return state_->isAttacking(); }
protected:
	Waypoint* waypoint_ = nullptr;
	BaseState* state_;
};

