#include "../headers/Spirit.h"

Spirit::Spirit() : Actor{} {
	engine = &ZeluEngine::getInstance();
}

Spirit::Spirit(Model& model, RenderHandlerInterface& render_handler, bool active) : Actor{ model, render_handler, active } {
	engine = &ZeluEngine::getInstance();
}

/* DynamicActorInterface methods declaration */
void Spirit::updateDynamics() {

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		if ((z_vel += 0.25f) > 1.0f) {
			z_vel = 1.0f;
			
		}

		engine->getCamera().move(0.0f, 0.0f, z_vel);

	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		if ((z_vel -= 0.25f) < -1.0f) {
			z_vel = -1.0f;
		}

		engine->getCamera().move(0.0f, 0.0f, z_vel);

	} else {
		z_vel = 0.0f;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
		if ((x_vel += 0.25f) > 1.0f) {
			x_vel = 1.0f;
		}

		engine->getCamera().move(x_vel, 0.0f, 0.0f);

	} else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
		if ((x_vel -= 0.25f) < -1.0f) {
			x_vel = -1.0f;
		}

		engine->getCamera().move(x_vel, 0.0f, 0.0f);

	} else {
		x_vel = 0.0f;
	}
}

void Spirit::move() {
	translate(x_vel, y_vel, z_vel);
	updateTransformations();
}