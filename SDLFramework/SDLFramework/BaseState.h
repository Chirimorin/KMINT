#pragma once

#include "IGameObject.h"

class BaseState
{
public:
	BaseState();
	virtual ~BaseState();

	virtual void Move(IGameObject* obj);
};

