#include "../../application/headers/RenderPhaseAction.h"

RenderPhaseAction::RenderPhaseAction(bool active) {
	this->active = active;
	tri = new Triangle{};
	originLines = new OriginLines{};
	gridLines = new GridLines{};

	TexturedRenderHandler* tmp = new TexturedRenderHandler{};
	spirit = new Actor{ ZeluEngine::getInstance().getModelFactory().getModel(CONSTANTS::SPIRIT_MODEL_NAME), *tmp, true };
	spirit->renderHandlerSetup();
	spirit->updateTransformations();
}

void RenderPhaseAction::execute() {
	//tri->draw();
	originLines->draw();
	//gridLines->draw();

	spirit->render();
}