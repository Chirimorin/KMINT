#include "CowHideState.h"
#include "Cow.h"

CowHideState::CowHideState() : CowState()
{
}

void CowHideState::Update(Entity* obj)
{
	// TODO: (Koe blijft stilstaan. Koe en haas krijgen geen punten als haas haar raakt.
}

Vector2 CowHideState::CalculateForce(Entity* obj)
{

	return Vector2(0, 0);
}