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

bool Spirit::checkCollision(CollisionActorInterface& actor) {
	return true;
}

void Spirit::onCollision(CollisionActorInterface& actor) {
	//if (
	//	(super.collisionInfo[MIN_X] >= actor.collisionInfo[MIN_X] && super.collisionInfo[MIN_X] <= actor.collisionInfo[MAX_X] ||
	//	super.collisionInfo[MAX_X] >= actor.collisionInfo[MIN_X] && super.collisionInfo[MAX_X] <= actor.collisionInfo[MAX_X]) &&
	//	(super.collisionInfo[MIN_Y] >= actor.collisionInfo[MIN_Y] && super.collisionInfo[MIN_Y] <= actor.collisionInfo[MAX_Y] ||
	//	super.collisionInfo[MAX_Y] >= actor.collisionInfo[MIN_Y] && super.collisionInfo[MAX_Y] <= actor.collisionInfo[MAX_Y]) &&
	//	(super.collisionInfo[MIN_Z] >= actor.collisionInfo[MIN_Z] && super.collisionInfo[MIN_Z] <= actor.collisionInfo[MAX_Z] ||
	//	super.collisionInfo[MAX_Z] >= actor.collisionInfo[MIN_Z] && super.collisionInfo[MAX_Z] <= actor.collisionInfo[MAX_Z])
	//	) {
	//	this.onCollision(actor); // Execute onCollision each object, passing the other as argument
	//	actor.onCollision(this);
	//	return true;
	//}

	//return false;
}