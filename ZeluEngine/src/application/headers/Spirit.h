#pragma once
#include <stdio.h>
#include <vector>
#include <SFML\Window.hpp>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/Actor.h"
#include "../../engine/headers/Model.h"
#include "../../engine/headers/RenderHandlerInterface.h"
#include "../../engine/headers/DynamicActorInterface.h"

class Spirit : public Actor, public DynamicActorInterface {

public:
	Spirit();
	Spirit(Model& model, RenderHandlerInterface& render_handler, bool active);

	/* DynamicActorInterface methods declaration */
	void updateDynamics();
	void move();

private:
	ZeluEngine* engine;

};