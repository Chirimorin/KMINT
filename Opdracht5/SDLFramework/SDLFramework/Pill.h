#pragma once
#include "IGameObject.h"

class Pill : public IGameObject
{
public:
	Pill(Uint8 r, Uint8 g, Uint8 b);
	~Pill();

	void Update(float deltaTime);
};

