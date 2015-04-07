#include "../headers/ZeluEngineContext.h"

ZeluEngineContext* ZeluEngineContext::instance;
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //
ZeluEngineContext::ZeluEngineContext() {
	camera = new Camera();
	modelFactory = new ModelFactory();

	scene_actors = new vector < Actor >{ 40 };
	void_actor = new Actor{};

	shader_program_list = new map < string, ShaderProgram >{};
}
// ------------------------------------------------------------------------------------ //
// ------------------------------------------------------------------------------------ //