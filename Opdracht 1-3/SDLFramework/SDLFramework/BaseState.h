#pragma once
#include "cow.h"
#include "rabbit.h"
#include <SDL_hints.h>
struct SDL_Texture;
class Entity;
class Graph;

class BaseState
{
public:
	BaseState(Uint8 r, Uint8 g, Uint8 b);
	virtual ~BaseState() {}

	virtual void Move(Entity* obj, Graph* graph) = 0;
	void setColor(SDL_Texture* texture);
	virtual bool isAttacking() { return isAttacking_; }
	virtual bool getAttacked() = 0;
protected:
	Uint8 r_;
	Uint8 g_;
	Uint8 b_;
	bool isAttacking_;
};

class CowState : public BaseState
{
public:
	CowState(Cow* cow, Uint8 r, Uint8 g, Uint8 b) : BaseState(r, g, b) { cow_ = cow;  }
	~CowState() {}

	bool getAttacked() override;
protected:
	Cow* cow_ = nullptr;
};

class RabbitState : public BaseState
{
public:
	int timer_ = 0;
	int chanceToFleeState_ = 50;
	int chanceToFindPillState_ = 30;
	int chanceToFindWeaponState_ = 20;

	RabbitState(Rabbit* rabbit, Uint8 r, Uint8 g, Uint8 b) : BaseState(r, g, b) { rabbit_ = rabbit; }
	virtual ~RabbitState() {}

	bool getAttacked() override;
protected:
	Rabbit* rabbit_ = nullptr;
};
