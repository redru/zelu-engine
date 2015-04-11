#include "../headers/InputHandler.h"

ZeluEngine* InputHandler::engine = &ZeluEngine::getInstance();
int InputHandler::last_position_x = 0;
int InputHandler::last_position_y = 0;

void InputHandler::handleInput(sf::Event event) {

	if (event.type == sf::Event::Resized) {

		glViewport(0, 0, event.size.width, event.size.height);

		// Camera aspect ratio adjustment
		std::cout << "Window - Width: " << event.size.width << " - Height: " << event.size.height << std::endl;
		std::cout << "Window - Aspect Ratio: " << (float)event.size.width / (float)event.size.height << std::endl;
		engine->getCamera().setAspectRatio((float)event.size.width / (float)event.size.height);

	} else if (event.type == sf::Event::KeyPressed) {

		if (event.key.code == sf::Keyboard::W) {
			engine->addKeyPressed(sf::Keyboard::W);
		} else if (event.key.code == sf::Keyboard::A) {
			engine->addKeyPressed(sf::Keyboard::A);
		} else if (event.key.code == sf::Keyboard::S) {
			engine->addKeyPressed(sf::Keyboard::S);
		} else if (event.key.code == sf::Keyboard::D) {
			engine->addKeyPressed(sf::Keyboard::D);
		}

	}
	else if (event.type == sf::Event::KeyReleased) {

		if (event.key.code == sf::Keyboard::W) {
			engine->addKeyReleased(sf::Keyboard::W);
		} else if (event.key.code == sf::Keyboard::A) {
			engine->addKeyReleased(sf::Keyboard::A);
		} else if (event.key.code == sf::Keyboard::S) {
			engine->addKeyReleased(sf::Keyboard::S);
		} else if (event.key.code == sf::Keyboard::D) {
			engine->addKeyReleased(sf::Keyboard::D);
		}

	} else if (event.type == sf::Event::MouseWheelMoved) {

		engine->getCamera().move(0.0f, 0.0f, (float)(event.mouseWheel.delta * 2));

	} else if (event.type == sf::Event::MouseMoved) {

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
			engine->getCamera().move((float) (last_position_x - event.mouseMove.x) / 10.0f, 0.0f, (float) (last_position_y - event.mouseMove.y) / 10.0f);
		}

		last_position_x = event.mouseMove.x;
		last_position_y = event.mouseMove.y;
	}
}