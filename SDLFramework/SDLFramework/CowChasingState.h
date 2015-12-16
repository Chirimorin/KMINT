#pragma once
#include "BaseState.h"

class CowChasingState : public BaseState
{
public:
	CowChasingState();
	~CowChasingState();

	void Move(Entity* obj, Graph* graph) override;
};

