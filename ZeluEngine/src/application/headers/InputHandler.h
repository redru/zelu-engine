#pragma once
#include <SFML\Window.hpp>

#include "../../engine/headers/ZeluEngine.h"

class InputHandler {

public:
	static void handleInput(sf::Event event);

private:
	static ZeluEngine* engine;

	static int last_position_x;
	static int last_position_y;


};