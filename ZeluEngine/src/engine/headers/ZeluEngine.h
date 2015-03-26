#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <GL\glew.h>

#include "Camera.h"
#include "EngineAction.h"
#include "Actor.h"
#include "ShaderProgram.h"

using namespace std;

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
	map< string, ShaderProgram >& getShaderProgramList();
	vector< Actor >& getSceneActors();
	Camera& getCamera();

private:
	vector< Actor >* sceneActors;
	map<string, ShaderProgram>* shaderProgramList;

	EngineAction* preUpdatePhase;
	EngineAction* updatePhase;
	EngineAction* collisionPhase;
	EngineAction* postUpdatePhase;
	EngineAction* renderPhase;

	Camera* camera;

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