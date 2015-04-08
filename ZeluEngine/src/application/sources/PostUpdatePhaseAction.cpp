#include "../headers/PostUpdatePhaseAction.h"

PostUpdatePhaseAction::PostUpdatePhaseAction(bool active) {
	this->active = active;

	engine = &ZeluEngine::getInstance();
}

void PostUpdatePhaseAction::execute() {

	// Update Camera before rendering
	engine->getCamera().updateCamera();

}