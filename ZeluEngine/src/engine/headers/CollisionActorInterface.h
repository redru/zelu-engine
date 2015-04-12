#pragma once

class CollisionActorInterface {

public:
	virtual bool checkCollision(CollisionActorInterface& actor, std::vector<float>& collision_info_sec) = 0;

	virtual void onCollision(CollisionActorInterface& actor) = 0;

};