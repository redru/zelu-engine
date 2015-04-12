#pragma once
#include <stdio.h>
#include <vector>
#include <SFML\Window.hpp>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/Actor.h"
#include "../../engine/headers/Model.h"
#include "../../engine/headers/Texture.h"
#include "../../engine/headers/RenderHandlerInterface.h"
#include "../../engine/headers/DynamicActorInterface.h"

class EnmSpirit : public Actor, public DynamicActorInterface {

public:
	EnmSpirit();
	EnmSpirit(Model& model, Texture& texture, RenderHandlerInterface& render_handler, std::string id, bool active);

	/* DynamicActorInterface methods declaration */
	void updateDynamics();
	void move();

private:
	ZeluEngine* engine;

};