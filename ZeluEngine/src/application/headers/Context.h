#pragma once
#include <stdio.h>
#include <vector>

#include "../../engine/headers/ZeluEngine.h"
#include "../headers/Spirit.h"

class Context {

public:
	std::vector< Spirit >& getSpiritList();
	Spirit& getFirstUnusedSpirit();
	void renderSceneActors();

public:
	std::vector< Spirit >* spirit_list;
	Spirit* void_actor;

private:
	ZeluEngine* engine;

/*********** Singleton ***********/

private:
	Context();
	static Context* instance;

public:
	static Context& getInstance() {
		if (instance == NULL) {
			instance = new Context();
		}

		return *instance;
	};
	
/*********************************/
};

inline vector< Spirit >& Context::getSpiritList() {
	return *spirit_list;
}

inline Spirit& Context::getFirstUnusedSpirit() {
	for (auto& spirit : *spirit_list) {
		if (!spirit.isActive()) {
			return spirit;
		}
	}

	return *void_actor;
}