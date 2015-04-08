#pragma once
#include <iostream>
#include <vector>
#include <map>

#include <GL\glew.h>

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

/************************ ENGINE *************************/

	void startup();
	void executePhases();
	void setPhaseAction(EngineAction& engineAction, Phase phase);

	/*********************** SHADERS *************************/

	void putShaderProgram(string name, ShaderProgram& shader);
	ShaderProgram& getShaderProgram(string name);

	/************************ SCENE **************************/

	/*********************** CAMERA **************************/

	Camera& getCamera();
	ModelFactory& getModelFactory();

	/************************ MISC ***************************/

	void addKeyPressed(sf::Keyboard::Key key);
	void addKeyReleased(sf::Keyboard::Key key);
	void emptyKeyList();

/********************************************************/

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

inline Camera& ZeluEngine::getCamera() {
	return *engine_context->camera;
}

inline ModelFactory& ZeluEngine::getModelFactory() {
	return *engine_context->modelFactory;
}

inline void ZeluEngine::addKeyPressed(sf::Keyboard::Key key) {
	engine_context->key_press_list->push_back(key);
}

inline void ZeluEngine::addKeyReleased(sf::Keyboard::Key key) {
	engine_context->key_release_list->push_back(key);
}

inline void ZeluEngine::emptyKeyList() {
	engine_context->key_press_list->clear();
	engine_context->key_release_list->clear();
}