#pragma once
#include <stdio.h>
#include <vector>
#include <SFML\Window.hpp>

#include "../../engine/headers/ZeluEngine.h"
#include "../../engine/headers/EngineConsts.h"
#include "../../engine/headers/Actor.h"
#include "../../engine/headers/Model.h"
#include "../../engine/headers/Texture.h"
#include "../../engine/headers/RenderHandlerInterface.h"
#include "../../engine/headers/DynamicActorInterface.h"
#include "../../engine/headers/CollisionActorInterface.h"

class Spirit : public Actor, public DynamicActorInterface, public CollisionActorInterface {

public:
	Spirit();
	Spirit(Model& model, Texture& texture, RenderHandlerInterface& render_handler, std::string id, bool active);

	/* DynamicActorInterface methods declaration */
	void updateDynamics();
	void move();

	/* CollisionActorInterface methods declaration */
	bool checkCollision(CollisionActorInterface& actor, std::vector<float>& collision_info_sec);
	void onCollision(CollisionActorInterface& actor);

private:
	ZeluEngine* engine;

};