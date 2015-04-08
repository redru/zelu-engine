#pragma once
#include <iostream>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/EngineAction.h"

#include "Context.h"
#include "TexturedRenderHandler.h"
#include "Triangle.h"
#include "OriginLines.h"
#include "GridLines.h"

class RenderPhaseAction : public EngineAction {

public:
	RenderPhaseAction(bool active = false);

	virtual void execute();

private:
	ZeluEngine* engine;

	OriginLines* originLines;
	GridLines* gridLines;
	Actor* spirit;

};