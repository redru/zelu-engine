#pragma once
#include <stdio.h>
#include <vector>
#include <map>

#include "Actor.h"
#include "ShaderProgram.h"
#include "ModelFactory.h"
#include "Model.h"
#include "Camera.h"

class ZeluEngineContext {

public:
/************* ENGINE *******************/

	Camera* camera;
	ModelFactory* modelFactory;

/*********** MISCELANEOUS ***************/

	std::vector< Actor >* scene_actors;
	Actor* void_actor;

	std::map<string, ShaderProgram>* shader_program_list;

/************* SINGLETON ****************/

private:
	ZeluEngineContext();

	static ZeluEngineContext* instance;

public:
	static ZeluEngineContext& getInstance() {
		if (instance == NULL) {
			instance = new ZeluEngineContext{};
		}

		return *instance;
	};

/****************************************/

};