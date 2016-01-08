#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
	delete state_;
}

void Entity::Update(float deltaTime)
{
	state_->Update(this);

	Vector2 steeringForce = Truncate(state_->CalculateForce(this), maxForce_);

	//Acceleration = Force/Mass
	Vector2 acceleration = steeringForce / mass_;

	//update velocity
	velocity_ += acceleration * deltaTime;

	//make sure vehicle does not exceed maximum velocity
	velocity_ = Truncate(velocity_, maxSpeed_);

	//update the position
	position_ += velocity_ * deltaTime;

	//update the heading if the vehicle has a velocity greater than a very small value
	if (MagnitudeSquared(velocity_) > 0.00000001) {
		heading_ = Normal(velocity_);
		side_ = Perp(heading_);
	}

	//treat the screen as a toroid
	WrapAround(position_);

	mX = static_cast<uint32_t>(position_.x);
	mY = static_cast<uint32_t>(position_.y);
}

void Entity::Draw()
{
	IGameObject::Draw(Angle(heading_));
}

void Entity::SetState(BaseState* state)
{
	delete state_;
	state_ = state;
	state_->setColor(mTexture);
}