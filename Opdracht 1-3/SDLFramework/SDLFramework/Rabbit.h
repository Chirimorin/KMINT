#pragma once
#include "IGameObject.h"
#include "Entity.h"
#include "Waypoint.h"

class Rabbit : public Entity
{
public:
	Rabbit(Graph* graph, Waypoint* waypoint);
	~Rabbit();

	void Update(float deltaTime) override;

	void Move(Graph* graph) override;
	void MoveTo(Waypoint* waypoint) override;

	void reset(Graph* graph) override;
	bool getAttacked(Graph* graph) override;

	void hasPill(bool hasPill) { hasPill_ = hasPill; }
	bool hasPill() { return hasPill_; }
protected:
	bool hasPill_ = false;

};

