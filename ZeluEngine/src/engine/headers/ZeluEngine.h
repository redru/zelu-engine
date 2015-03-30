#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <GL\glew.h>

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
	// Engine startup function
	void startup();

	// Phase actions invocation
	void executePhases();

	void setPhaseAction(EngineAction& engineAction, Phase phase);
	void putShaderProgram(string name, ShaderProgram& shader);
	ShaderProgram& getShaderProgram(string name);
	std::map< string, ShaderProgram >& getShaderProgramList();
	std::vector< Actor >& getSceneActors();
	Camera& getCamera();
	ModelFactory& getModelFactory();

private:
	std::vector< Actor >* sceneActors;
	std::map<string, ShaderProgram>* shaderProgramList;

	EngineAction* preUpdatePhase;
	EngineAction* updatePhase;
	EngineAction* collisionPhase;
	EngineAction* postUpdatePhase;
	EngineAction* renderPhase;

	Camera* camera;
	ModelFactory* modelFactory;

// ---------------- SINGLETON --------------------
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
// -----------------------------------------------

};

inline vector< Actor >& ZeluEngine::getSceneActors() {
	return *sceneActors;
}

inline void ZeluEngine::putShaderProgram(string name, ShaderProgram& shaderProgram) {
	shaderProgramList->insert(std::pair< string, ShaderProgram >(name, shaderProgram));
}

inline ShaderProgram& ZeluEngine::getShaderProgram(string name) {
	return shaderProgramList->find(name)->second;
}

inline map< string, ShaderProgram >& ZeluEngine::getShaderProgramList() {
	return *shaderProgramList;
}

inline Camera& ZeluEngine::getCamera() {
	return *camera;
}

inline ModelFactory& ZeluEngine::getModelFactory() {
	return *modelFactory;
}