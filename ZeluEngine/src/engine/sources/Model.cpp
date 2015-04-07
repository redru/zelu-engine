#include "../headers/Model.h"

Model::Model() {

}

Model::Model(std::vector<std::vector<float>>& positions,
			 std::vector<std::vector<float>>& textures,
			 std::vector<std::vector<float>>& normals,
			 std::vector<float>& unified_data,
			 int faces_count) {
	this->positions = new std::vector < std::vector<float> > { positions };
	this->textures = new std::vector < std::vector<float> >{ textures };
	this->normals = new std::vector < std::vector<float> >{ normals };
	this->unified_data = new  std::vector < float >{ unified_data };

	this->vertices_count = faces_count;
}

std::vector<float>& Model::getUnifiedData() {
	return *unified_data;
}

int Model::getVerticesCount() {
	return vertices_count;
}