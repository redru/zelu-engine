#include "../headers/TextureFactory.h"

TextureFactory::TextureFactory() {
	texture_stock = new std::map < std::string, std::string > {};

	std::cout << "TextureFactory - Creation complete." << std::endl;
}

void TextureFactory::loadTexture(std::string name, std::string path) {

}

std::string TextureFactory::getTexture(std::string name) {
	return std::string{"aaaa"};
}