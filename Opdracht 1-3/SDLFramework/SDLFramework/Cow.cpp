#include "Cow.h"

#include <iostream>
#include <SDL.h>
#include "CowChasingState.h"
#include "Graph.h"

Cow::Cow(Graph* graph, Waypoint* waypoint) : Entity()
{
	mTexture = mApplication->LoadTexture("cow.bmp");

	// TODO: moet size van de texture zijn
	mWidth = 48;
	mHeight = 48;

	MoveTo(waypoint);
	
	reset(graph);
}

Cow::~Cow()
{
}

void Cow::Update(float deltaTime)
{

}

void Cow::Move(Graph* graph)
{
	state_->Move(this, graph);
}

void Cow::MoveTo(Waypoint* waypoint)
{
	Entity::MoveTo(waypoint);
	mX -= mWidth/2;
}

void Cow::reset(Graph* graph)
{
	waypoint_ = graph->getRandomWaypoint(std::vector<Waypoint*>()); // TODO: ver van  haas vandaan
	setState(new CowChasingState(this));
}

bool Cow::getAttacked(Graph* graph) {
	return state_->getAttacked(graph);
}