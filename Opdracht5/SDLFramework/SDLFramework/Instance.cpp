#include "Instance.h"

Instance::Instance(FWApplication* application, Uint8 r, Uint8 g, Uint8 b)
{
	rabbit_ = new Rabbit(r, g, b);
	cow_ = new Cow(r, g, b);
	pill_ = new Pill(r, g, b);
	weapon_ = new Weapon(r, g, b);

	rabbit_->SetTarget(cow_);
	cow_->SetTarget(rabbit_);

	application->AddRenderable(rabbit_);
	application->AddRenderable(cow_);
	application->AddRenderable(pill_);
	application->AddRenderable(weapon_);
}

Instance::~Instance()
{
	delete rabbit_;
	rabbit_ = nullptr;

	delete cow_;
	cow_ = nullptr;

	delete pill_;
	pill_ = nullptr;

	delete weapon_;
	weapon_ = nullptr;
}
