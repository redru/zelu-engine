#pragma once
#include <iostream>
#include <string>
#include <map>

class TextureFactory {

public:
	TextureFactory();

	void loadTexture(std::string name, std::string path);

	std::string getTexture(std::string name);

private:
	std::map<std::string, std::string>* texture_stock;

};