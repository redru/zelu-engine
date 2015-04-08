#include "../headers/Spirit.h"

Spirit::Spirit() : Actor{} {

}

Spirit::Spirit(Model& model, RenderHandlerInterface& render_handler, bool active) : Actor{ model, render_handler, active } {
	std::cout << "Spirit - Creation complete." << std::endl;
}

/* DynamicActorInterface methods declaration */
void Spirit::updateDynamics() {

}

void Spirit::move() {
	
}