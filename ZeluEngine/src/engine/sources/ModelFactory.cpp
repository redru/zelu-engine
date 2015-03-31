#include "../headers/ModelFactory.h"

ModelFactory::ModelFactory() {
	modelStock = new std::map < std::string, Model > {};

	std::cout << "ModelFactory - Creation complete." << std::endl;
}

void ModelFactory::loadModel(std::string modelName, std::string modelPath) {
	std::cout << "ModelFactory - Loading model: " + modelPath << std::endl;

	std::vector <std::string> model{ FileUtils::readFileToVector(modelPath) };
	wrapModel(modelName, model);
}

void ModelFactory::wrapModel(std::string model_name, std::vector<std::string>& model) {
	std::vector<std::vector<float>> positions{};
	std::vector<std::vector<float>> textures{};
	std::vector<std::vector<float>> normals{};
	std::vector<float> unified_data{};

	for (unsigned index = 0; index < model.size(); index++) {
		std::vector<std::string> dataPart{};

		if (model[index].compare(0, 2, "v ") == 0) { // Check if the line is a position data
			model[index] = model[index].substr(2);
			dataPart = FileUtils::split(model[index], ' ', dataPart);
			std::vector<float> tmp{};

			for (unsigned i = 0; i < 3; i++) {
				float tmpFloat = std::stof(dataPart[i].c_str());
				tmp.push_back(tmpFloat);

				//this.evaluateMinMax(collisionInfo, tmp, i); // Set into the collision info the min and max values for this coordinate
			}

			positions.push_back(tmp);

		} else if (model[index].compare(0, 3, "vt ") == 0) { // Check if the line is a position data
			model[index] = model[index].substr(3);
			dataPart = FileUtils::split(model[index], ' ', dataPart);
			std::vector<float> tmp{};

			for (unsigned i = 0; i < 2; i++) {
				float tmpFloat = std::atof(dataPart[i].c_str());
				tmp.push_back(tmpFloat);
			}

			textures.push_back(tmp);

		} else if (model[index].compare(0, 3, "vn ") == 0) { // Check if the line is a position data
			model[index] = model[index].substr(3);
			dataPart = FileUtils::split(model[index], ' ', dataPart);
			std::vector<float> tmp{};

			for (unsigned i = 0; i < 3; i++) {
				float tmpFloat = std::atof(dataPart[i].c_str());
				tmp.push_back(tmpFloat);
			}

			normals.push_back(tmp);

		} else if (model[index].compare(0, 2, "f ") == 0) { // Check if the line is a position data
			model[index] = model[index].substr(2);
			dataPart = FileUtils::split(model[index], ' ', dataPart); //f 28/18/10 29/19/10 30/20/10

			for (unsigned x = 0; x < 3; x++) {
				std::vector<std::string> supp_data_part{}; //f 28/18/10
				supp_data_part = FileUtils::split(dataPart[x], '/', supp_data_part);

				for (unsigned i = 0; i < 3; i++) { // {28, 18, 10}
					int tmp_int = std::atof(supp_data_part[i].c_str()) - 1;

					switch (i) {
					case 0:
						unified_data.push_back(positions[tmp_int][0]);
						unified_data.push_back(positions[tmp_int][1]);
						unified_data.push_back(positions[tmp_int][2]);
						break;
					case 1:
						unified_data.push_back(textures[tmp_int][0]);
						unified_data.push_back(textures[tmp_int][1]);
						break;
					case 2:
						unified_data.push_back(normals[tmp_int][0]);
						unified_data.push_back(normals[tmp_int][1]);
						unified_data.push_back(normals[tmp_int][2]);
						break;
					default:
						break;
					}
				}
			}
		}

	}

	Model tmp_model{positions, textures, normals, unified_data};
	modelStock->insert(std::pair< std::string, Model >(model_name, tmp_model));

}

Model& ModelFactory::getModel(std::string name) {
	return modelStock->find(name)->second;
}