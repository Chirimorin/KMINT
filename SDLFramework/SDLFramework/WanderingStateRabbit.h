#pragma once
#include "BaseState.h"

class WanderingStateRabbit : public BaseState
{
public:
	WanderingStateRabbit();
	~WanderingStateRabbit();

	void Move(IGameObject* obj) override;
};

