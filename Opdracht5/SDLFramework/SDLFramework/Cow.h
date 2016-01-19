#pragma once
#include "IGameObject.h"
#include "Entity.h"

class Cow : public Entity
{
public:
	Cow(Uint8 r, Uint8 g, Uint8 b);
	~Cow();

	//void Draw() override;
};

