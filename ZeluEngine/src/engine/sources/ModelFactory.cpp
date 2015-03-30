#include "../headers/ModelFactory.h"

ModelFactory::ModelFactory() {
	modelStock = new std::map < std::string, Model > {};

	std::cout << "ModelFactory - Creation complete." << std::endl;
}

void ModelFactory::loadModel(std::string modelName, std::string modelPath) {
	std::cout << "ModelFactory - Loading model: " + modelPath << std::endl;

	std::vector <std::string> model{ FileUtils::readFileToVector(modelPath) };
	wrapModel(model);
}

void ModelFactory::wrapModel(std::vector<std::string>& model) {
	std::vector<std::string> dataPart{};
	std::vector<float> positions{};

	for (unsigned index = 0; index < model.size(); index++) {

		if (model[index].compare(0, 2, "v ") == 0) { // Check if the line is a position data
			model[index] = model[index].substr(2);
			dataPart = FileUtils::split(model[index], ' ', dataPart);

			for (unsigned i = 0; i < 3; i++) {
				float tmp = std::atof(dataPart[i].c_str());
				positions.push_back(tmp);

				//this.evaluateMinMax(collisionInfo, tmp, i); // Set into the collision info the min and max values for this coordinate
			}

		}

	}
}

Model& ModelFactory::getModel(std::string name) {
	return modelStock->find(name)->second;
}