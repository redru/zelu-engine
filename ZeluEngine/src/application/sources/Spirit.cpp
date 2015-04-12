#include "../headers/Spirit.h"

Spirit::Spirit() : Actor{} {
	engine = &ZeluEngine::getInstance();
}

Spirit::Spirit(Model& model, Texture& texture, RenderHandlerInterface& render_handler, std::string id, bool active) : Actor{ model, texture, render_handler, id, active } {
	engine = &ZeluEngine::getInstance();
}

/* DynamicActorInterface methods declaration */
void Spirit::updateDynamics() {
	Camera& camera{ engine->getCamera() };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		if ((z_vel += 0.25f) > 1.0f) {
			z_vel = 1.0f;
			
		}

		camera.move(0.0f, 0.0f, z_vel);
		camera.moveLook(0.0f, 0.0f, z_vel);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		if ((z_vel -= 0.25f) < -1.0f) {
			z_vel = -1.0f;
		}

		camera.move(0.0f, 0.0f, z_vel);
		camera.moveLook(0.0f, 0.0f, z_vel);

	} else {
		z_vel = 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) || sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		if ((x_vel += 0.25f) > 1.0f) {
			x_vel = 1.0f;
		}

		camera.move(x_vel, 0.0f, 0.0f);
		camera.moveLook(x_vel, 0.0f, 0.0f);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) || sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		if ((x_vel -= 0.25f) < -1.0f) {
			x_vel = -1.0f;
		}

		camera.move(x_vel, 0.0f, 0.0f);
		camera.moveLook(x_vel, 0.0f, 0.0f);

	} else {
		x_vel = 0.0f;
	}
}

void Spirit::move() {
	translate(x_vel, y_vel, z_vel);
	updateTransformations();
}

bool Spirit::checkCollision(CollisionActorInterface& actor, std::vector<float>& collision_info_sec) {
	std::vector<float>& col_info{ *collision_info };

	if (
		(col_info[ENGINE_CONSTANTS::MIN_X] >= collision_info_sec[ENGINE_CONSTANTS::MIN_X] && col_info[ENGINE_CONSTANTS::MIN_X] <= collision_info_sec[ENGINE_CONSTANTS::MAX_X] ||
		col_info[ENGINE_CONSTANTS::MAX_X] >= collision_info_sec[ENGINE_CONSTANTS::MIN_X] && col_info[ENGINE_CONSTANTS::MAX_X] <= collision_info_sec[ENGINE_CONSTANTS::MAX_X]) &&
		(col_info[ENGINE_CONSTANTS::MIN_Y] >= collision_info_sec[ENGINE_CONSTANTS::MIN_Y] && col_info[ENGINE_CONSTANTS::MIN_Y] <= collision_info_sec[ENGINE_CONSTANTS::MAX_Y] ||
		col_info[ENGINE_CONSTANTS::MAX_Y] >= collision_info_sec[ENGINE_CONSTANTS::MIN_Y] && col_info[ENGINE_CONSTANTS::MAX_Y] <= collision_info_sec[ENGINE_CONSTANTS::MAX_Y]) &&
		(col_info[ENGINE_CONSTANTS::MIN_Z] >= collision_info_sec[ENGINE_CONSTANTS::MIN_Z] && col_info[ENGINE_CONSTANTS::MIN_Z] <= collision_info_sec[ENGINE_CONSTANTS::MAX_Z] ||
		col_info[ENGINE_CONSTANTS::MAX_Z] >= collision_info_sec[ENGINE_CONSTANTS::MIN_Z] && col_info[ENGINE_CONSTANTS::MAX_Z] <= collision_info_sec[ENGINE_CONSTANTS::MAX_Z])
		) {
			onCollision(actor); // Execute onCollision each object, passing the other as argument
			actor.onCollision(*this);
		return true;
	}

	return false;
}

void Spirit::onCollision(CollisionActorInterface& actor) {
	std::cout << "Collision" << std::endl;
}