#pragma once
#include "FWApplication.h"
#include "Rabbit.h"
#include "Cow.h"
#include "Pill.h"
#include "Weapon.h"

class Instance
{
public:
	Instance(FWApplication* application, Uint8 r, Uint8 g, Uint8 b);
	~Instance();
private:
	Rabbit* rabbit_ = nullptr;
	Cow* cow_ = nullptr;
	Pill* pill_ = nullptr;
	Weapon* weapon_ = nullptr;
};

