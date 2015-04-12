#include "../headers/Context.h"

Context* Context::instance;

Context::Context() {
	main_character = new Spirit{};

	spirit_list = new std::vector < EnmSpirit >{ 40 };

	void_actor = new EnmSpirit{};
	void_actor->setId("NULL");

}