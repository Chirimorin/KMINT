#pragma once
#include "IGameObject.h"
#include "Entity.h"

class Cow : public Entity
{
public:
	Cow();
	~Cow();

	void Draw() override;
};

