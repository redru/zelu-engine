#include "../headers/TextureFactory.h"

TextureFactory::TextureFactory() {
	texture_stock = new std::map < std::string, Texture > {};

	std::cout << "TextureFactory - Creation complete." << std::endl;
}

void TextureFactory::loadTexture(std::string name, std::string path) {
	std::vector<unsigned char>* image = new std::vector<unsigned char>();
	unsigned width, height;
	unsigned error = lodepng::decode(*image, width, height, path);

	if (error != 0) {
		std::cout << "error " << error << ": " << lodepng_error_text(error) << std::endl;
		exit(error);
	}

	Texture* tex = new Texture{ *image, width, height };

	texture_stock->insert(std::pair< std::string, Texture >(name, *tex));
}

Texture& TextureFactory::getTexture(std::string name) {
	return texture_stock->find(name)->second;
}