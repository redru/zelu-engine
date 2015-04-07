#pragma once
#include <stdio.h>
#include <vector>

class Model {

public:
	Model();
	Model(std::vector<std::vector<float>>& positions, std::vector<std::vector<float>>& textures, std::vector<std::vector<float>>& normals, std::vector<float>& unified_data, int vertices_count);

	std::vector<float>& getUnifiedData();
	int getVerticesCount();

private:
	std::vector<std::vector<float>>* positions;
	std::vector<std::vector<float>>* textures;
	std::vector<std::vector<float>>* normals;
	std::vector<float>* unified_data;

	int vertices_count;

};