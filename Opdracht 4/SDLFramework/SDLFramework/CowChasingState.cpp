#include "CowChasingState.h"
#include "Cow.h"
#include <iostream>

CowChasingState::CowChasingState() : CowState(255, 255, 255)
{
}

Vector2 CowChasingState::CalculateForce(Entity* obj)
{
	Vector2 result = { 0.f,0.f };

	// Vector directly towards the rabbit
	Vector2 goal = obj->GetTarget()->GetPosition() - obj->GetPosition();
	goal += obj->GetTarget()->GetHeading() * Magnitude(goal) / 5;
	WrapAround(goal);
	goal = WrappedDistance(goal);

	float dotPerp = DotPerp(obj->GetVelocity(), goal);

	if (dotPerp < 0)
	{
		// turn left
		result += -1 * obj->GetSide() * obj->GetMaxTurnRate();
	}
	else if (dotPerp > 0)
	{
		// turn right
		result += obj->GetSide() * obj->GetMaxTurnRate();
	}

	if (DotProduct(obj->GetVelocity(), goal) > 0)
	{
		// speed up
		result += obj->GetHeading() * obj->GetMaxForce();
	}
	else
	{
		// slow down
		result += -1 * obj->GetHeading() * obj->GetMaxForce();
	}

	return result;
}