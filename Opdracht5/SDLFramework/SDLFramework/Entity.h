#pragma once
#include "IGameObject.h"
#include "BaseState.h"
#include "vector2.h"

class Entity : public IGameObject
{
public:
	Entity();
	virtual ~Entity();

	void Update(float deltaTime) override;
	void Draw() override;
	void SetTarget(Entity* target) { target_ = target; }
	Entity* GetTarget() const { return target_; }
	Vector2 GetPosition() const { return position_; }
	Vector2 GetVelocity() const { return velocity_; }
	Vector2 GetHeading() const { return heading_; }
	Vector2 GetSide() const { return side_; }
	float GetMaxTurnRate() const { return maxTurnRate_; }
	float GetMaxForce() const { return maxForce_; }

	void SetState(BaseState* state);

	void addPoints(int points) { points_ += points; }

protected:
	Vector2 position_;
	Vector2 velocity_; 
	Vector2 heading_; // a normalized vector pointing in the direction the entity is heading.
	Vector2 side_; // a vector perpendicular to the heading vector

	float mass_;
	float maxSpeed_; //the maximum speed at which this entity may travel.
	float maxForce_; //the maximum force this entity can produce to power itself (think rockets and thrust)
	float maxTurnRate_; //the maximum rate at which this vehicle can rotate

	BaseState* state_;

	Entity* target_ = nullptr;

private:
	int points_ = 0;
};

