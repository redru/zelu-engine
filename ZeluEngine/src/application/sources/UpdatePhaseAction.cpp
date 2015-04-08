#include "../headers/UpdatePhaseAction.h"

UpdatePhaseAction::UpdatePhaseAction(bool active) {
	this->active = active;

	engine = &ZeluEngine::getInstance();
}

void UpdatePhaseAction::execute() {


}