#pragma once
#include <iostream>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/EngineAction.h"
#include "../headers/Context.h"

class CollisionPhaseAction : public EngineAction {

public:
	CollisionPhaseAction(bool active = false);

	virtual void execute();

private:
	ZeluEngine* engine;

};