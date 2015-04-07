#include "../headers/ZeluEngine.h"

ZeluEngine* ZeluEngine::instance;
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //
ZeluEngine::ZeluEngine() {
	sceneActors = new vector < Actor > { 40 };
	shaderProgramList = new map < string, ShaderProgram > {};
}

ZeluEngine::~ZeluEngine() {

}
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //
void ZeluEngine::startup() {
	std::cout << "Zelu Engine - Starting." << std::endl;
	// Engine modules loading
	camera = new Camera();
	modelFactory = new ModelFactory();

	std::cout << "Zelu Engine - Correctly started." << std::endl;
}
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //
void ZeluEngine::executePhases() {
	if (preUpdatePhase != NULL && preUpdatePhase->isActive()) {
		preUpdatePhase->execute();
	}

	if (updatePhase != NULL && updatePhase->isActive()) {
		updatePhase->execute();
	}

	if (collisionPhase != NULL && collisionPhase->isActive()) {
		collisionPhase->execute();
	}

	if (postUpdatePhase != NULL && postUpdatePhase->isActive()) {
		postUpdatePhase->execute();
	}

	if (renderPhase != NULL && renderPhase->isActive()) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		renderPhase->execute();
	}
}
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //
void ZeluEngine::setPhaseAction(EngineAction& engineAction, Phase phase) {
	switch (phase) {
		case ZeluEngine::PRE_UPDATE:
			preUpdatePhase = &engineAction;
			break;
		case ZeluEngine::UPDATE:
			updatePhase = &engineAction;
			break;
		case ZeluEngine::COLLISION:
			collisionPhase = &engineAction;
			break;
		case ZeluEngine::POST_UPDATE:
			postUpdatePhase = &engineAction;
			break;
		case ZeluEngine::RENDER:
			renderPhase = &engineAction;
			break;
		default:
			break;
	}
}
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //