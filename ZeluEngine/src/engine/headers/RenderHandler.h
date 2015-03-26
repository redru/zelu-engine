#pragma once

class RenderHandler {

public:
	// Setup function
	virtual void setup() = 0;

	// Updater function
	virtual void uploadRenderData() = 0;

	// Render function
	virtual void render() = 0;

};