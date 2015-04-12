#pragma once
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <string>

#include "Model.h"
#include "FileUtils.h"

class ModelFactory {

public:
	ModelFactory();

	void loadModel(std::string name, std::string path);

	inline Model& getModel(std::string name) { return modelStock->find(name)->second; }

private:
	void wrapModel(std::string modelName, std::vector<std::string>& model);

	void evaluateMinMax(std::vector<float>& target, float value, int coord_type);
	
private:
	std::map<std::string, Model>* modelStock;

};