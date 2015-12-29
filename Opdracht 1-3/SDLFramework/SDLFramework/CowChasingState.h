#pragma once
#include "BaseState.h"

class CowChasingState : public CowState
{
public:
	CowChasingState();
	~CowChasingState() {}

	void Move(Entity* obj, Graph* graph) override;
};

