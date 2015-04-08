#pragma once
#include <iostream>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/EngineAction.h"

#include "Context.h"

class UpdatePhaseAction : public EngineAction {

public:
	UpdatePhaseAction(bool active = false);

	virtual void execute();

private:
	ZeluEngine* engine;

};