#include "../headers/Actor.h"

Actor::Actor() : active { false } {

}

Actor::~Actor() {

}

void Actor::renderHandlerSetup() {
	renderHandler->setup();
}

void Actor::uploadRenderData() {
	renderHandler->uploadRenderData();
}

void Actor::render() {
	renderHandler->render();
}

// Getters / Setters
void Actor::setRenderHandler(RenderHandler& renderHandler) {
	this->renderHandler = &renderHandler;
}

RenderHandler& Actor::getRenderHandler() {
	return *renderHandler;
}

void Actor::setActive(bool active) {
	this->active = active;
}

bool Actor::isActive() {
	return active;
}