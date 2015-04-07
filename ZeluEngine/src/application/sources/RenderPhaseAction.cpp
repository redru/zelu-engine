#include "../../application/headers/RenderPhaseAction.h"

RenderPhaseAction::RenderPhaseAction(bool active) {
	this->active = active;
	engine = &ZeluEngine::getInstance();

	originLines = new OriginLines{};
	gridLines = new GridLines{};
}

void RenderPhaseAction::execute() {
	originLines->draw();
	gridLines->draw();

	engine->renderSceneActors();
}