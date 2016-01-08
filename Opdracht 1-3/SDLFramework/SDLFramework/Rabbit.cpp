#include "Rabbit.h"
#include "RabbitWanderingState.h"
#include "Graph.h"

#include <iostream>

Rabbit::Rabbit(Graph* graph, Waypoint* waypoint) : Entity()
{
	mTexture = mApplication->LoadTexture("rabbit.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	MoveTo(waypoint);

	reset(graph);
}

Rabbit::~Rabbit()
{
}

void Rabbit::Update(float deltaTime)
{

}

void Rabbit::Move(Graph* graph)
{
	state_->Move(this, graph);
}

void Rabbit::MoveTo(Waypoint* waypoint)
{
	Entity::MoveTo(waypoint);
	mX += mWidth/2;
}

void Rabbit::reset(Graph* graph)
{
	waypoint_ = graph->getRandomWaypoint(std::vector<Waypoint*>()); // TODO: ver van  koe vandaan
	setState(new RabbitWanderingState(this));
}

bool Rabbit::getAttacked(Graph* graph) {
	return state_->getAttacked(graph);
}