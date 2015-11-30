#pragma once

#include "IGameObject.h"

class State
{
public:
	State();
	~State();

	virtual void Move(IGameObject* obj);
};

