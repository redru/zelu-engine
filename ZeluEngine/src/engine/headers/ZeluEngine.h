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

	std::vector< Actor >& getSceneActors();
	Actor& getFirstUnusedActor();
	void renderSceneActors();

	/*********************** CAMERA **************************/

	Camera& getCamera();
	ModelFactory& getModelFactory();

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
inline vector< Actor >& ZeluEngine::getSceneActors() {
	return *engine_context->scene_actors;
}

inline Actor& ZeluEngine::getFirstUnusedActor() {
	// Look in the actors list
	for (auto& actor : *engine_context->scene_actors) {
		// Return selected actor if inactive
		if (!actor.isActive()) {
			return actor;
		}
	}

	return *engine_context->void_actor;
}

inline void ZeluEngine::renderSceneActors() {
	for (auto& actor : *engine_context->scene_actors) {
		if (actor.isActive()) {
			actor.render();
		}
	}
}

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