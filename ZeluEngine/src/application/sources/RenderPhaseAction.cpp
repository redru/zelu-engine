#include "../../application/headers/RenderPhaseAction.h"

RenderPhaseAction::RenderPhaseAction(bool active) {
	this->active = active;
	engine = &ZeluEngine::getInstance();

	originLines = new OriginLines{};
	gridLines = new GridLines{};
}

void RenderPhaseAction::execute() {
	originLines->draw();
	//gridLines->draw();

	Context& context{ Context::getInstance() };

	context.getMainCharacter().render();

	for (auto& spirit : context.getSpiritList()) {
		if (spirit.isActive()) {
			spirit.render();
		}
	}
}