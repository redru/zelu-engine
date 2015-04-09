#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "lodepng.h"
#include "Texture.h"

class TextureFactory {

public:
	TextureFactory();

	void loadTexture(std::string name, std::string path);

	Texture& getTexture(std::string name);

private:
	std::map<std::string, Texture>* texture_stock;

};