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

	Model& getModel(std::string name);

private:
	void wrapModel(std::string modelName, std::vector<std::string>& model);
	
private:
	std::map<std::string, Model>* modelStock;

};