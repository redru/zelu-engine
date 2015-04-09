#pragma once
#include <iostream>
#include <vector>

#include <GL\glew.h>

#include "TextureFactory.h"
#include "ZeluEngineContext.h"
#include "ModelFactory.h"
#include "Model.h"
#include "Camera.h"
#include "EngineAction.h"
#include "Actor.h"
#include "ShaderProgram.h"

const class ZeluEngine {

public:
	enum Phase {
		PRE_UPDATE,
		UPDATE,
		COLLISION,
		POST_UPDATE,
		RENDER
	};

public:
	void startup();
	void executePhases();
	void setPhaseAction(EngineAction& engineAction, Phase phase);

	/*********************** SHADERS *************************/

	void putShaderProgram(string name, ShaderProgram& shader);
	ShaderProgram& getShaderProgram(string name);

	/************************ SCENE **************************/

	inline ModelFactory& getModelFactory() { return *engine_context->model_factory; }
	inline TextureFactory& getTextureFactory() { return *engine_context->texture_factory; }

	/*********************** CAMERA **************************/

	inline Camera& getCamera() { return *engine_context->camera; }

	/************************ MISC ***************************/

	void addKeyPressed(sf::Keyboard::Key key);
	void addKeyReleased(sf::Keyboard::Key key);
	void clearKeyLists();

	inline std::vector<sf::Keyboard::Key>& getKeysPressed() { return *engine_context->key_press_list; }
	inline std::vector<sf::Keyboard::Key>& getKeysReleased() { return *engine_context->key_release_list; }

private:
	ZeluEngineContext* engine_context;

	EngineAction* preUpdatePhase;
	EngineAction* updatePhase;
	EngineAction* collisionPhase;
	EngineAction* postUpdatePhase;
	EngineAction* renderPhase;

/********************** SINGLETON ***************************/
private:
	// Constructor
	ZeluEngine();

	// Destructor
	~ZeluEngine();

	// Engine instance
	static ZeluEngine* instance;

public:
	// Engine instance getter function
	static inline ZeluEngine& getInstance() {
		if (instance == NULL) {
			instance = new ZeluEngine();
		}

		return *instance;
	}
/************************************************************/

};

/************************ INLINE ****************************/
inline void ZeluEngine::putShaderProgram(string name, ShaderProgram& shaderProgram) {
	engine_context->shader_program_list->insert(std::pair< string, ShaderProgram >(name, shaderProgram));
}

inline ShaderProgram& ZeluEngine::getShaderProgram(string name) {
	return engine_context->shader_program_list->find(name)->second;
}

inline void ZeluEngine::addKeyPressed(sf::Keyboard::Key key) {
	engine_context->key_press_list->push_back(key);
}

inline void ZeluEngine::addKeyReleased(sf::Keyboard::Key key) {
	engine_context->key_release_list->push_back(key);
}

inline void ZeluEngine::clearKeyLists() {
	engine_context->key_press_list->clear();
	engine_context->key_release_list->clear();
}