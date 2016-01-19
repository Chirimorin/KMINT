#pragma once
#include <SDL_hints.h>
struct Vector2;
struct SDL_Texture;
class Entity;

class BaseState
{
public:
	BaseState();
	virtual ~BaseState() {}

	virtual void Update(Entity* obj) = 0;
	virtual Vector2 CalculateForce(Entity* obj) = 0;
	virtual bool getAttacked() = 0;
};

class CowState : public BaseState
{
public:
	CowState() : BaseState() {}
	~CowState() {}

	bool getAttacked() override;
};

class RabbitState : public BaseState
{
public:
	RabbitState() : BaseState() {}
	~RabbitState() {}
};
