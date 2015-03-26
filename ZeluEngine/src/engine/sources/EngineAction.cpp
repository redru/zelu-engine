#include "../../engine/headers/EngineAction.h"

EngineAction::EngineAction(bool active) {
	this->active = active;
}

void EngineAction::setActive(bool active) {
	this->active = active;
}

bool EngineAction::isActive() {
	return active;
}