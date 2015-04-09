#include "../headers/Texture.h"

Texture::Texture() {

}

Texture::Texture(std::vector<unsigned char>& data, unsigned width, unsigned height) {
	this->data = &data;
	this->width = width;
	this->height = height;
}