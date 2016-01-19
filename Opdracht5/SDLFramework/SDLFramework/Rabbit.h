#pragma once
#include "IGameObject.h"
#include "Entity.h"

class Rabbit : public Entity
{
public:
	Rabbit(Uint8 r, Uint8 g, Uint8 b);
	~Rabbit();
private:
	int chanceToFleeState_ = 0;
	int chanceToFindPillState_ = 0;
	int chanceToHideState_ = 0;
	int chanceToFindWeaponState_ = 0;

};

