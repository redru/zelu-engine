#include "../headers/InputHandler.h"

ZeluEngine* InputHandler::engine = &ZeluEngine::getInstance();
int InputHandler::last_position_x = 0;
int InputHandler::last_position_y = 0;

void InputHandler::handleInput(sf::Event event) {
	if (event.type == sf::Event::KeyPressed) {

	}
	else if (event.type == sf::Event::KeyReleased) {

	}
	else if (event.type == sf::Event::MouseWheelMoved) {
		engine->getCamera().move(0.0f, 0.0f, (float)(event.mouseWheel.delta * 2));
	}
	else if (event.type == sf::Event::MouseMoved) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			engine->getCamera().rotate((float)-(last_position_y - event.mouseMove.y), (float)-(last_position_x - event.mouseMove.x), 0.0f);
		}

		last_position_x = event.mouseMove.x;
		last_position_y = event.mouseMove.y;
	}
}