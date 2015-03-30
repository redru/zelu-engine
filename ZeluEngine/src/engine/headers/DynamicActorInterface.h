#pragma once

class DynamicActorInterface {

public:
	virtual void updateDynamics() = 0;

	virtual void move() = 0;

};