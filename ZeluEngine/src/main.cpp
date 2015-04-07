#include <iostream>
#include <stdio.h>
#include <SFML\Window.hpp>
#include <GL\glew.h>

#include "application\headers\Constants.h"
#include "engine\headers\ZeluEngine.h"
#include "engine\headers\ShaderFactory.h"
#include "engine\headers\ShaderProgram.h"
#include "application\headers\RenderPhaseAction.h"

RenderPhaseAction* renderPhase;
ShaderProgram* shaderProgram;

int last_position_x = 0;
int last_position_y = 0;

void applicationInitialize(ZeluEngine& engine);

int main() {
	// create the window
	sf::Window window(sf::VideoMode(800, 600), "ZeluEngine TEST", sf::Style::Default, sf::ContextSettings(32));
	window.setFramerateLimit(CONSTANTS::APPL_FRAMERATE);
	window.setVerticalSyncEnabled(true);

	ZeluEngine* engine = &ZeluEngine::getInstance();

	applicationInitialize(*engine);
	
	bool running = true;
	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event)) {

			if (event.type == sf::Event::Closed) {
				running = false;
			} else if (event.type == sf::Event::Resized) {
				glViewport(0, 0, event.size.width, event.size.height);

				// Camera aspect ratio adjustment
				std::cout << "Window - Width: " << event.size.width << " - Height: " << event.size.height << std::endl;
				std::cout << "Window - Aspect Ratio: " << (float)event.size.width / (float)event.size.height << std::endl;
				engine->getCamera().setAspectRatio((float)event.size.width / (float)event.size.height);
			} else if (event.type == sf::Event::KeyPressed) {

			} else if (event.type == sf::Event::KeyReleased) {

			} else if (event.type == sf::Event::MouseWheelMoved) {
				engine->getCamera().move(0.0f, 0.0f, (float) (event.mouseWheel.delta * 2));
			} else if (event.type == sf::Event::MouseMoved) {
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
					engine->getCamera().rotate((float) (last_position_y - event.mouseMove.y), (float) -(last_position_x - event.mouseMove.x), 0.0f);
				}
					
				last_position_x = event.mouseMove.x;
				last_position_y = event.mouseMove.y;
			}
		}

		engine->getCamera().updateCamera();

		// Update, Collision Check and Render phases
		engine->executePhases();

		// end the current frame (internally swaps the front and back buffers)
		window.display();
	}

	// release resources...

	return 0;
}

void applicationInitialize(ZeluEngine& engine) {
	// Opengl and Glew initialize
	GLenum GlewInitResult{};
	if (GLEW_OK != GlewInitResult) {
		std::cout << "Error during glew startup: " << GlewInitResult << std::endl;
		exit(EXIT_FAILURE);
	}

	std::cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << std::endl;

	glewExperimental = GL_TRUE;
	GlewInitResult = glewInit();

	// Zelu engine -----------------------------------------------------------------------------------------
	engine.startup();

	// Shaders
	ShaderFactory shaderFac{};
	shaderProgram = new ShaderProgram{ shaderFac.createShader(CONSTANTS::SHADER_PATH + "shader_vert_struct.glsl", CONSTANTS::SHADER_PATH + "shader_frag_struct.glsl") };
	engine.putShaderProgram(CONSTANTS::SHADER_STRUCT, *shaderProgram);

	// Models
	engine.getModelFactory().loadModel(CONSTANTS::SPIRIT_MODEL_NAME, CONSTANTS::MODEL_PATH + "obj_b2spirit.obj");

	// Camera
	engine.getCamera().move(0.0f, 0.0f, -8.0f);
	engine.getCamera().rotate(-30.0f, 180.0f, 0.0f);
	engine.getCamera().setAspectRatio(800.0f / 600.0f);
	engine.getCamera().updateCamera();
	
	// Engine phases
	renderPhase = new RenderPhaseAction{ true };
	engine.setPhaseAction(*renderPhase, ZeluEngine::Phase::RENDER);
	// ------------------------------------------------------------------------------------------------------
}