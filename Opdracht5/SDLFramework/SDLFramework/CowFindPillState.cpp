#include "CowFindPillState.h"
#include "Cow.h"
#include "CowWanderingState.h"

CowFindPillState::CowFindPillState() : CowState()
{
}

void CowFindPillState::Update(Entity* obj)
{
	/*Vector2 toCow = obj->GetTarget()->GetPosition() + obj->GetTarget()->GetVelocity() - obj->GetPosition();
	if (MagnitudeWrapped(toCow) > 300.f)
	{
		obj->SetState(new CowWanderingState());
	}*/


	// TODO: Zodra pil gepakt: Pil spawned ergens in het veld. Koe blijft vanaf nu staan en is deze hele run voor 
	// altijd onkwetsbaar.Haas krijgt geen punten meer.Koe krijgt 1 punt als haas haar raakt.
	// Beesten worden nog wél gerespawned na raken.)
}

Vector2 CowFindPillState::CalculateForce(Entity* obj)
{
	// loop zo recht mogelijk weg van de haas
	Vector2 toRabbit = obj->GetTarget()->GetPosition() - obj->GetPosition();
	return WrappedDistance(toRabbit) * -1;

	// TODO: koe naast vluchten ook naar de pil toe gaan ??
}
