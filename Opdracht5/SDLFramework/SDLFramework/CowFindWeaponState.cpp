#include "CowFindWeaponState.h"
#include "Cow.h"
#include "CowWanderingState.h"

CowFindWeaponState::CowFindWeaponState() : CowState()
{
}

void CowFindWeaponState::Update(Entity* obj)
{
	/*Vector2 toCow = obj->GetTarget()->GetPosition() + obj->GetTarget()->GetVelocity() - obj->GetPosition();
	if (MagnitudeWrapped(toCow) > 300.f)
	{
		obj->SetState(new CowWanderingState());
	}*/


	// TODO: Zodra wapen gepakt: Wapen spawned ergens in het veld. Zie verder verstoppen.
}

Vector2 CowFindWeaponState::CalculateForce(Entity* obj)
{
	// loop zo recht mogelijk weg van de haas
	Vector2 toRabbit = obj->GetTarget()->GetPosition() - obj->GetPosition();
	return WrappedDistance(toRabbit) * -1;

	// TODO: koe naast vluchten ook naar het wapen toe gaan ??
}
