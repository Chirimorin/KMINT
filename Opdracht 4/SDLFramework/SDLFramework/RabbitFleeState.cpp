#include "RabbitFleeState.h"
#include "Rabbit.h"

RabbitFleeState::RabbitFleeState() : RabbitState(0, 255, 0)
{
}

void RabbitFleeState::Move(Entity* obj)
{
	// TODO: de haas beweegt zich volgens flee

	// TODO: als de haas zich veilig voelt, dan veranderd de state naar wandering
	
}

