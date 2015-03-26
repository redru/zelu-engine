#pragma once

#include "RenderHandler.h"

class Actor {

public:
	// Constructor
	Actor();

	// Destructor
	~Actor();

	// Call to this function uploads basic information to the renderHandler
	void renderHandlerSetup();

	// Upload render data function
	void uploadRenderData();

	// Render function
	void render();

	// Getters / Setters --------------------------------
	void setRenderHandler(RenderHandler& renderHandler);
	RenderHandler& getRenderHandler();

	void setActive(bool active);
	bool isActive();
	// --------------------------------------------------

private:
	bool active;

	RenderHandler* renderHandler;

};