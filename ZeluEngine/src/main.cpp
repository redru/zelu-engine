#include <iostream>
#include <stdio.h>
#include <SFML\Window.hpp>
#include <GL\glew.h>

#include "engine\headers\ZeluEngine.h"
#include "engine\headers\ShaderFactory.h"
#include "engine\headers\TextureFactory.h"
#include "engine\headers\Texture.h"

#include "application\headers\Context.h"
#include "application\headers\Constants.h"
#include "application\headers\PreUpdatePhaseAction.h"
#include "application\headers\UpdatePhaseAction.h"
#include "application\headers\PostUpdatePhaseAction.h"
#include "application\headers\RenderPhaseAction.h"
#include "application\headers\InputHandler.h"
#include "application\headers\Spirit.h"
#include "application\headers\EnmSpirit.h"

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
			}

			// Handle user input events
			InputHandler::handleInput(event);

		}

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

	glEnable(GL_DEPTH_TEST);

// Zelu engine -----------------------------------------------------------------------------------------
	engine.startup();

	// Shaders
	ShaderFactory shader_fac{};
	shader_fac.createShader(CONSTANTS::SHADER_PATH + "shader_vert_struct.glsl", CONSTANTS::SHADER_PATH + "shader_frag_struct.glsl", CONSTANTS::SHADER_STRUCT);
	shader_fac.createShader(CONSTANTS::SHADER_PATH + "shader_vert_textured.glsl", CONSTANTS::SHADER_PATH + "shader_frag_textured.glsl", CONSTANTS::SHADER_TEXTURED);

	// Models and Textures
	ModelFactory& model_fac{ engine.getModelFactory() };
	model_fac.loadModel(CONSTANTS::SPIRIT_MODEL_NAME, CONSTANTS::MODEL_SPIRIT_PATH + "obj_b2spirit.obj");

	TextureFactory& tex_fac{ engine.getTextureFactory() };
	tex_fac.loadTexture(CONSTANTS::SPIRIT_MODEL_NAME, CONSTANTS::MODEL_SPIRIT_PATH + "tex_b2spirit.png");

	// Camera
	Camera& camera{ engine.getCamera() };
	camera.move(0.0f, 10.0f, -18.0f);
	camera.moveLook(0.0f, 2.0f, -4.0f);
	camera.setAspectRatio(800.0f / 600.0f);
	camera.updateCamera();
	
	// Engine phases
	PreUpdatePhaseAction* pre_update_phase = new PreUpdatePhaseAction{ true };
	engine.setPhaseAction(*pre_update_phase, ZeluEngine::Phase::PRE_UPDATE);

	UpdatePhaseAction* update_phase = new UpdatePhaseAction{ true };
	engine.setPhaseAction(*update_phase, ZeluEngine::Phase::UPDATE);

	PostUpdatePhaseAction* post_update_phase = new PostUpdatePhaseAction{ true };
	engine.setPhaseAction(*post_update_phase, ZeluEngine::Phase::POST_UPDATE);

	RenderPhaseAction* render_phase = new RenderPhaseAction{ true };
	engine.setPhaseAction(*render_phase, ZeluEngine::Phase::RENDER);

	// Adding main character
	TexturedRenderHandler* tmp_mchar = new TexturedRenderHandler{};
	Spirit& spirit{ Context::getInstance().getMainCharacter() };
	spirit.initialize(model_fac.getModel(CONSTANTS::SPIRIT_MODEL_NAME), tex_fac.getTexture(CONSTANTS::SPIRIT_MODEL_NAME), *tmp_mchar, "CHAR", true);
	spirit.renderHandlerSetup();
	spirit.scale(0.75f, 0.75f, 0.75f);
	spirit.translateToPosition(0.0f, 2.0f, -4.0f);
	spirit.updateTransformations();

	// Adding NPCs
	TexturedRenderHandler* tmp = new TexturedRenderHandler{};
	EnmSpirit& enm_spirit{ Context::getInstance().getFirstUnusedSpirit() };
	enm_spirit.initialize(model_fac.getModel(CONSTANTS::SPIRIT_MODEL_NAME), tex_fac.getTexture(CONSTANTS::SPIRIT_MODEL_NAME), *tmp, "NPC", true);
	enm_spirit.renderHandlerSetup();
	enm_spirit.translateToPosition(0.0f, 2.0f, 120.0f);
	enm_spirit.setStart(0.0f, 2.0f, 120.0f);
	enm_spirit.rotate(0.0f, 180.0f, 0.0f);
	enm_spirit.updateTransformations();

	TexturedRenderHandler* tmp2 = new TexturedRenderHandler{};
	EnmSpirit& enm_spirit2{ Context::getInstance().getFirstUnusedSpirit() };
	enm_spirit2.initialize(model_fac.getModel(CONSTANTS::SPIRIT_MODEL_NAME), tex_fac.getTexture(CONSTANTS::SPIRIT_MODEL_NAME), *tmp2, "NPC", true);
	enm_spirit2.renderHandlerSetup();
	enm_spirit2.translateToPosition(-4.0f, 2.0f, 80.0f);
	enm_spirit2.setStart(-4.0f, 2.0f, 80.0f);
	enm_spirit2.rotate(0.0f, 180.0f, 0.0f);
	enm_spirit2.updateTransformations();

	TexturedRenderHandler* tmp3 = new TexturedRenderHandler{};
	EnmSpirit& enm_spirit3{ Context::getInstance().getFirstUnusedSpirit() };
	enm_spirit3.initialize(model_fac.getModel(CONSTANTS::SPIRIT_MODEL_NAME), tex_fac.getTexture(CONSTANTS::SPIRIT_MODEL_NAME), *tmp3, "NPC", true);
	enm_spirit3.renderHandlerSetup();
	enm_spirit3.translateToPosition(10.0f, 2.0f, 180.0f);
	enm_spirit3.setStart(10.0f, 2.0f, 180.0f);
	enm_spirit3.rotate(0.0f, 180.0f, 0.0f);
	enm_spirit3.updateTransformations();
// ------------------------------------------------------------------------------------------------------
}