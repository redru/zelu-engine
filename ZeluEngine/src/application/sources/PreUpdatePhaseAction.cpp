#include "../headers/PreUpdatePhaseAction.h"

PreUpdatePhaseAction::PreUpdatePhaseAction(bool active) {
	this->active = active;

	engine = &ZeluEngine::getInstance();
}

void PreUpdatePhaseAction::execute() {
	
}
