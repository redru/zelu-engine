#pragma once
#include <iostream>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/EngineAction.h"

class PostUpdatePhaseAction : public EngineAction {

public:
	PostUpdatePhaseAction(bool active = false);

	virtual void execute();

private:
	ZeluEngine* engine;

};