#include "../headers/EnmSpirit.h"

EnmSpirit::EnmSpirit() : Actor{} {
	engine = &ZeluEngine::getInstance();
}

EnmSpirit::EnmSpirit(Model& model, Texture& texture, RenderHandlerInterface& render_handler, std::string id, bool active) : Actor{ model, texture, render_handler, id, active } {
	engine = &ZeluEngine::getInstance();
}

/* DynamicActorInterface methods declaration */
void EnmSpirit::updateDynamics() {
	z_vel = -0.75f;
}

void EnmSpirit::move() {
	if (z_pos + z_vel > -15) {
		translate(x_vel, y_vel, z_vel);
	} else {
		translateToPosition(x_start, y_start, z_start);
	}

	updateTransformations();
}

bool EnmSpirit::checkCollision(CollisionActorInterface& actor, std::vector<float>& collision_info_sec) {
	std::vector<float>& collision_info{ this->getCollisionInfo() };

	if (
		(collision_info[ENGINE_CONSTANTS::MIN_X] >= collision_info_sec[ENGINE_CONSTANTS::MIN_X] && collision_info[ENGINE_CONSTANTS::MIN_X] <= collision_info_sec[ENGINE_CONSTANTS::MAX_X] ||
		collision_info[ENGINE_CONSTANTS::MAX_X] >= collision_info_sec[ENGINE_CONSTANTS::MIN_X] && collision_info[ENGINE_CONSTANTS::MAX_X] <= collision_info_sec[ENGINE_CONSTANTS::MAX_X]) &&
		(collision_info[ENGINE_CONSTANTS::MIN_Y] >= collision_info_sec[ENGINE_CONSTANTS::MIN_Y] && collision_info[ENGINE_CONSTANTS::MIN_Y] <= collision_info_sec[ENGINE_CONSTANTS::MAX_Y] ||
		collision_info[ENGINE_CONSTANTS::MAX_Y] >= collision_info_sec[ENGINE_CONSTANTS::MIN_Y] && collision_info[ENGINE_CONSTANTS::MAX_Y] <= collision_info_sec[ENGINE_CONSTANTS::MAX_Y]) &&
		(collision_info[ENGINE_CONSTANTS::MIN_Z] >= collision_info_sec[ENGINE_CONSTANTS::MIN_Z] && collision_info[ENGINE_CONSTANTS::MIN_Z] <= collision_info_sec[ENGINE_CONSTANTS::MAX_Z] ||
		collision_info[ENGINE_CONSTANTS::MAX_Z] >= collision_info_sec[ENGINE_CONSTANTS::MIN_Z] && collision_info[ENGINE_CONSTANTS::MAX_Z] <= collision_info_sec[ENGINE_CONSTANTS::MAX_Z])
		) {
		onCollision(actor); // Execute onCollision each object, passing the other as argument
		actor.onCollision(*this);
		return true;
	}

	return false;
}

void EnmSpirit::onCollision(CollisionActorInterface& actor) {
	std::cout << "Collision" << std::endl;
}