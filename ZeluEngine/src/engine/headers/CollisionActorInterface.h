#pragma once

class CollisionActorInterface {

public:
	virtual bool checkCollision(CollisionActorInterface& actor) = 0;

	virtual void onCollision(CollisionActorInterface& actor) = 0;

};