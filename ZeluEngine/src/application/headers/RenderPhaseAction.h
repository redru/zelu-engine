#pragma once
#include <iostream>
#include "../../engine/headers/EngineAction.h"
#include "Triangle.h"
#include "OriginLines.h"
#include "GridLines.h"

class RenderPhaseAction : public EngineAction {

public:
	RenderPhaseAction(bool active = false);

	virtual void execute();

private:
	Triangle* tri;
	OriginLines* originLines;
	GridLines* gridLines;

};