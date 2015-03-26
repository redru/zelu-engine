#pragma once

class EngineAction {

public:
	EngineAction(bool active=false);

	virtual void execute() { };

	void setActive(bool active);
	bool isActive();

protected:
	bool active;

};