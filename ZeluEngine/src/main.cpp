#include <iostream>
#include <stdio.h>
#include <SFML\Window.hpp>
#include <GL\glew.h>

#include "engine\headers\ZeluEngine.h"
#include "engine\headers\ShaderFactory.h"
#include "engine\headers\ShaderProgram.h"
#include "application\headers\RenderPhaseAction.h"

using namespace std;

RenderPhaseAction* renderPhase;
ShaderProgram* shaderProgram;

void applicationInitialize(ZeluEngine& engine);

int main() {
	// create the window
	sf::Window window(sf::VideoMode(800, 600), "ZeluEngine TEST", sf::Style::Default, sf::ContextSettings(32));
	window.setVerticalSyncEnabled(true);

	ZeluEngine* engine = &ZeluEngine::getInstance();

	applicationInitialize(*engine);
	
	bool running = true;
	while (running)
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				running = false;
			}
			else if (event.type == sf::Event::Resized)
			{
				glViewport(0, 0, event.size.width, event.size.height);

				// Camera aspect ratio adjustment
				cout << "Window - Width: " << event.size.width << " - Height: " << event.size.height << endl;
				cout << "Window - Aspect Ratio: " << (float)event.size.width / (float)event.size.height << endl;
				engine->getCamera().setAspectRatio((float)event.size.width / (float)event.size.height);
				engine->getCamera().updateCamera();
			}
		}

		// Update, Collision Check and Render phases
		engine->executePhases();
		
		engine->getCamera().rotate(0.0f, 1.0f, 0.0f);
		engine->getCamera().updateCamera();

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
		cout << "Error during glew startup: " << GlewInitResult << endl;
		exit(EXIT_FAILURE);
	}

	cout << "INFO: OpenGL Version: " << glGetString(GL_VERSION) << endl;

	glewExperimental = GL_TRUE;
	GlewInitResult = glewInit();

	// Zelu engine -----------------------------------------------------------------------------------------
	engine.startup();

	ShaderFactory shaderFac{};
	shaderProgram = new ShaderProgram{ shaderFac.createShader("build/Debug/glsl/shader_vert_struct.glsl", "build/Debug/glsl/shader_frag_struct.glsl") };
	engine.putShaderProgram("shader_vert_struct", *shaderProgram);

	engine.getCamera().move(0.0f, 0.0f, -16.0f);
	engine.getCamera().rotate(-30.0f, 180.0f, 0.0f);
	engine.getCamera().setAspectRatio(800.0f / 600.0f);
	engine.getCamera().updateCamera();
	
	renderPhase = new RenderPhaseAction{ true };
	engine.setPhaseAction(*renderPhase, ZeluEngine::Phase::RENDER);
	// ------------------------------------------------------------------------------------------------------
}