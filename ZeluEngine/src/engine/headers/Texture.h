#pragma once
#include <iostream>
#include <vector>

class Texture {

public:
	Texture();

	Texture(std::vector<unsigned char>& data, unsigned width, unsigned height);

	inline std::vector<unsigned char>& getData() { return *data; };

	inline unsigned getWidth() { return width; };

	inline unsigned getHeight() { return height; };

private:
	std::vector<unsigned char>* data;
	unsigned width, height;
	
};