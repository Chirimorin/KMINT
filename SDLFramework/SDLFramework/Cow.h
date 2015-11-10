#pragma once
#include "IGameObject.h"

class Cow : public IGameObject
{
public:
	Cow();
	~Cow();

	void Update(float deltaTime);
};

