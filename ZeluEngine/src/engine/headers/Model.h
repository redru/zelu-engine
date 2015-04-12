#pragma once
#include <stdio.h>
#include <vector>

class Model {

public:
	Model();
	Model(std::vector<std::vector<float>>& positions,
		std::vector<std::vector<float>>& textures,
		std::vector<std::vector<float>>& normals,
		std::vector<float>& unified_data,
		std::vector<float>& collision_info,
		int vertices_count);

	inline std::vector<float>& getUnifiedData() { return *unified_data; };
	inline int getVerticesCount() { return vertices_count; };
	inline std::vector<float>& getCollisionInfo() { return *collision_info; };

private:
	std::vector<std::vector<float>>* positions;
	std::vector<std::vector<float>>* textures;
	std::vector<std::vector<float>>* normals;
	std::vector<float>* unified_data;

	std::vector<float>* collision_info;

	int vertices_count;

};