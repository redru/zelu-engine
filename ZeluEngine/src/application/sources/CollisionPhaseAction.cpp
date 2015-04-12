#include "../headers/CollisionPhaseAction.h"

CollisionPhaseAction::CollisionPhaseAction(bool active) {
	this->active = active;

	engine = &ZeluEngine::getInstance();
}

void CollisionPhaseAction::execute() {

	Context& context{ Context::getInstance() };
	Spirit& main_char{ context.getMainCharacter() };

	for (auto& enm_spirit : context.getSpiritList()) {
		main_char.checkCollision(enm_spirit, enm_spirit.getCollisionInfo());
	}

}