#include "../headers/Context.h"

Context* Context::instance;

Context::Context() {

	spirit_list = new std::vector < Spirit >{ 40 };
	void_actor = new Spirit{};

}