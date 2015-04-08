#include "../headers/ZeluEngineContext.h"

ZeluEngineContext* ZeluEngineContext::instance;
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //
ZeluEngineContext::ZeluEngineContext() {
	camera = new Camera();
	modelFactory = new ModelFactory();

	shader_program_list = new map < string, ShaderProgram >{};

	key_press_list = new vector < sf::Keyboard::Key >{};
	key_release_list = new vector < sf::Keyboard::Key >{};
}
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //