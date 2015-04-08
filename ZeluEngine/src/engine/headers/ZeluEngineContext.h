#pragma once
#include <stdio.h>
#include <vector>
#include <map>

#include <SFML\Window.hpp>

#include "TextureFactory.h"
#include "Actor.h"
#include "ShaderProgram.h"
#include "ModelFactory.h"
#include "Model.h"
#include "Camera.h"

class ZeluEngineContext {

public:
/************* ENGINE *******************/

	Camera* camera;
	ModelFactory* model_factory;
	//TextureFactory* texture_factory;

/*********** MISCELANEOUS ***************/

	std::map<string, ShaderProgram>* shader_program_list;
	std::vector<sf::Keyboard::Key>* key_press_list;
	std::vector<sf::Keyboard::Key>* key_release_list;

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