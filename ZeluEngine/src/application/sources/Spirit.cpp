#include "../headers/Spirit.h"

Spirit::Spirit() : Actor{} {
	engine = &ZeluEngine::getInstance();
}

Spirit::Spirit(Model& model, Texture& texture, RenderHandlerInterface& render_handler, bool active) : Actor{ model, texture, render_handler, active } {
	engine = &ZeluEngine::getInstance();
}

/* DynamicActorInterface methods declaration */
void Spirit::updateDynamics() {
	Camera& camera{ engine->getCamera() };

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if ((z_vel += 0.25f) > 1.0f) {
			z_vel = 1.0f;
			
		}

		camera.move(0.0f, 0.0f, z_vel);
		camera.moveLook(0.0f, 0.0f, z_vel);

	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if ((z_vel -= 0.25f) < -1.0f) {
			z_vel = -1.0f;
		}

		camera.move(0.0f, 0.0f, z_vel);
		camera.moveLook(0.0f, 0.0f, z_vel);

	} else {
		z_vel = 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if ((x_vel += 0.25f) > 1.0f) {
			x_vel = 1.0f;
		}

		camera.move(x_vel, 0.0f, 0.0f);
		camera.moveLook(x_vel, 0.0f, 0.0f);

	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if ((x_vel -= 0.25f) < -1.0f) {
			x_vel = -1.0f;
		}

		camera.move(x_vel, 0.0f, 0.0f);
		camera.moveLook(x_vel, 0.0f, 0.0f);

	} else {
		x_vel = 0.0f;
	}

	//camera.setLook(x_pos, y_pos, z_pos);
}

void Spirit::move() {
	translate(x_vel, y_vel, z_vel);
	updateTransformations();
}