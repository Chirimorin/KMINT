#pragma once
#include <SDL_hints.h>
struct SDL_Texture;
class Entity;

class BaseState
{
public:
	BaseState(Uint8 r, Uint8 g, Uint8 b);
	virtual ~BaseState() {}

	virtual void Move(Entity* obj) = 0;
	void setColor(SDL_Texture* texture);
protected:
	Uint8 r_;
	Uint8 g_;
	Uint8 b_;
};

class CowState : public BaseState
{
public:
	CowState(Uint8 r, Uint8 g, Uint8 b) : BaseState(r, g, b) {}
	~CowState() {}
};

class RabbitState : public BaseState
{
public:
	RabbitState(Uint8 r, Uint8 g, Uint8 b) : BaseState(r, g, b) {}
	virtual ~RabbitState() {}
};
