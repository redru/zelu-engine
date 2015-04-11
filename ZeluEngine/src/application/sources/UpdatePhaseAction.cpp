#include "../headers/UpdatePhaseAction.h"

UpdatePhaseAction::UpdatePhaseAction(bool active) {
	this->active = active;

	engine = &ZeluEngine::getInstance();
}

void UpdatePhaseAction::execute() {
	Context& context{ Context::getInstance() };

	context.getMainCharacter().updateDynamics();
	context.getMainCharacter().move();

	/* Update dynamics */
	for (auto& spirit : context.getSpiritList()) {
		if (spirit.isActive()) {
			spirit.updateDynamics();
			spirit.move();
		}
	}

	/* Clear user input vectors from the engine */
	engine->clearKeyLists();

}