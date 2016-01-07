#pragma once
#include "BaseState.h"

class CowChasingState : public CowState
{
public:
	CowChasingState(Cow* cow);
	~CowChasingState() {}

	void Move(Entity* obj, Graph* graph) override;
};

