#include "../headers/UpdatePhaseAction.h"

UpdatePhaseAction::UpdatePhaseAction(bool active) {
	this->active = active;

	engine = &ZeluEngine::getInstance();
}

void UpdatePhaseAction::execute() {

	/* Update dynamics */
	for (auto& spirit : Context::getInstance().getSpiritList()) {
		if (spirit.isActive()) {
			spirit.updateDynamics();
			spirit.move();
		}
	}

	/* Clear user input vectors from the engine */
	engine->clearKeyLists();

}