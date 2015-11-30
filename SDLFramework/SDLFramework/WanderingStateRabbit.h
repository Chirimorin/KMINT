#pragma once
#include "State.h"

class WanderingStateRabbit : public State
{
public:
	WanderingStateRabbit();
	~WanderingStateRabbit();

	void Move(IGameObject* obj) override;
};

