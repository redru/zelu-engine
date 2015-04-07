#include "../../application/headers/RenderPhaseAction.h"

RenderPhaseAction::RenderPhaseAction(bool active) {
	this->active = active;
	tri = new Triangle{};
	originLines = new OriginLines{};
	gridLines = new GridLines{};

	ZeluEngine& engine{ ZeluEngine::getInstance() };

	TexturedRenderHandler* tmp = new TexturedRenderHandler{};
	spirit = new Actor{ engine.getModelFactory().getModel(CONSTANTS::SPIRIT_MODEL_NAME), *tmp, true };
	spirit->renderHandlerSetup();
	spirit->updateTransformations();

	Actor& tmpAc1{ engine.getFirstUnusedActor() };
	TexturedRenderHandler* tmp2 = new TexturedRenderHandler{};
	tmpAc1.setActive(true);
	tmpAc1.setRenderHandler(*tmp2);
	tmpAc1.setModel(engine.getModelFactory().getModel(CONSTANTS::SPIRIT_MODEL_NAME));
	tmpAc1.renderHandlerSetup();
	tmpAc1.translateToPosition(4.0f, 0.0f, 0.0f);
	tmpAc1.updateTransformations();

	Actor& tmpAc2{ engine.getFirstUnusedActor() };
	TexturedRenderHandler* tmp3 = new TexturedRenderHandler{};
	tmpAc2.setActive(true);
	tmpAc2.setRenderHandler(*tmp3);
	tmpAc2.setModel(engine.getModelFactory().getModel(CONSTANTS::SPIRIT_MODEL_NAME));
	tmpAc2.renderHandlerSetup();
	tmpAc2.translateToPosition(8.0f, 0.0f, 0.0f);
	tmpAc2.updateTransformations();

	Actor& tmpAc3{ engine.getFirstUnusedActor() };
	TexturedRenderHandler* tmp4 = new TexturedRenderHandler{};
	tmpAc3.setActive(true);
	tmpAc3.setRenderHandler(*tmp4);
	tmpAc3.setModel(engine.getModelFactory().getModel(CONSTANTS::SPIRIT_MODEL_NAME));
	tmpAc3.renderHandlerSetup();
	tmpAc3.translateToPosition(12.0f, 0.0f, 0.0f);
	tmpAc3.updateTransformations();
}

void RenderPhaseAction::execute() {
	//tri->draw();
	originLines->draw();
	//gridLines->draw();

	spirit->render();

	ZeluEngine& engine{ ZeluEngine::getInstance() };

	for (auto& actor : engine.getSceneActors()) {
		// Return selected actor if inactive
		if (actor.isActive()) {
			actor.render();
		}
	}
}