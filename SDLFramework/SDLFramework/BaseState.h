#pragma once
#include <SDL_hints.h>
struct SDL_Texture;
class Entity;
class Graph;

class BaseState
{
public:
	BaseState(Uint8 r, Uint8 g, Uint8 b);
	virtual ~BaseState();

	virtual void Move(Entity* obj, Graph* graph);
	void setColor(SDL_Texture* texture);
protected:
	Uint8 r_;
	Uint8 g_;
	Uint8 b_;
};

