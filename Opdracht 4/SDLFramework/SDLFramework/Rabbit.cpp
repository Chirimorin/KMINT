#include "Rabbit.h"
#include "RabbitWanderingState.h"

Rabbit::Rabbit() : Entity()
{
	mTexture = mApplication->LoadTexture("rabbit.bmp");

	mWidth = 48;
	mHeight = 48;

	mX = 250;
	mY = 250;

	state_ = new RabbitWanderingState();

	// TODO: goede waardes 
	velocity_ = Vector2(1, 1);
	heading_ = Vector2(1, 1);
	side_ = Vector2(1, 1);

	mass_ = 1;
	maxSpeed_ = 10;
	maxForce_ = 5;
	maxTurnRate_ = 1;
}

Rabbit::~Rabbit()
{
}

// Boek blz 89 en 90
void Rabbit::Update(float deltaTime)
{
	state_->Move(this);


	// Vector2 stForce = steering_.Calculate();
	// Calc new position, Check p 90.

	
	//calculate the combined force from each steering behavior in the vehicle’s list
	/*Vector2 steeringForce = steering_.Calculate();

	//Acceleration = Force/Mass
	Vector2 acceleration = steeringForce / mass_;

	//update velocity
	velocity_ += acceleration * deltaTime;

	//make sure vehicle does not exceed maximum velocity
	velocity_.Truncate(maxSpeed_);

	//update the position
	m_vPos += velocity_ * deltaTime;

	
	//update the heading if the vehicle has a velocity greater than a very small value
	if (velocity_.LengthSq() > 0.00000001)
	{
	heading_ = Vec2DNormalize(velocity_);
	side_ = heading_.Perp();
	}

	//treat the screen as a toroid
	WrapAround(m_vPos, m_pWorld->cxClient(), m_pWorld->cyClient());
	*/
}
