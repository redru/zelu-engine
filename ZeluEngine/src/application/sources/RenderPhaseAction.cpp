#include "../../application/headers/RenderPhaseAction.h"

RenderPhaseAction::RenderPhaseAction(bool active) {
	this->active = active;
	tri = new Triangle{};
	originLines = new OriginLines{};
	gridLines = new GridLines{};
}

void RenderPhaseAction::execute() {
	tri->draw();
	originLines->draw();
	gridLines->draw();
}