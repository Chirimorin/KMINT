#pragma once
#include "IGameObject.h"

class Pill : public IGameObject
{
public:
	Pill();
	~Pill();

	void Update(float deltaTime);
};

