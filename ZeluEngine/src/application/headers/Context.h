#pragma once
#include <stdio.h>
#include <vector>

#include "../../engine/headers/ZeluEngine.h"
#include "../headers/Spirit.h"
#include "../headers/EnmSpirit.h"

class Context {

public:
	inline Spirit& getMainCharacter() { return *main_character; }

	inline vector< EnmSpirit >& Context::getSpiritList() { return *spirit_list; }
	EnmSpirit& getFirstUnusedSpirit();

private:
	Spirit* main_character;

	std::vector< EnmSpirit >* spirit_list;
	EnmSpirit* void_actor;

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

inline EnmSpirit& Context::getFirstUnusedSpirit() {
	for (auto& spirit : *spirit_list) {
		if (!spirit.isActive()) {
			return spirit;
		}
	}

	return *void_actor;
}