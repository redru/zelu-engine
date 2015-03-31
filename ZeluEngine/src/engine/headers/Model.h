#pragma once
#include <stdio.h>
#include <vector>

class Model {

public:
	Model();
	Model(std::vector<std::vector<float>>& positions, std::vector<std::vector<float>>& textures, std::vector<std::vector<float>>& normals, std::vector<float>& unified_data);

	std::vector<float>& getUnifiedData();

private:
	std::vector<std::vector<float>>* positions;
	std::vector<std::vector<float>>* textures;
	std::vector<std::vector<float>>* normals;
	std::vector<float>* unified_data;

};