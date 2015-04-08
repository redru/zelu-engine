#pragma once
#include <iostream>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/EngineAction.h"

class PreUpdatePhaseAction : public EngineAction {

public:
	PreUpdatePhaseAction(bool active = false);

	virtual void execute();

private:
	ZeluEngine* engine;

};
