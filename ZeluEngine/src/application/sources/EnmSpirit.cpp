#include "../headers/EnmSpirit.h"

EnmSpirit::EnmSpirit() : Actor{} {
	engine = &ZeluEngine::getInstance();
}

EnmSpirit::EnmSpirit(Model& model, Texture& texture, RenderHandlerInterface& render_handler, bool active) : Actor{ model, texture, render_handler, active } {
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