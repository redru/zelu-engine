#pragma once
#include <iostream>
#include <stdio.h>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>

class FileUtils {

public:
	static std::string readFile(const std::string path);

	static std::vector<std::string> readFileToVector(const std::string path);

	static std::vector<std::string>& FileUtils::split(const std::string &s, char delim, std::vector<std::string> &elems);

	static std::vector<std::string> FileUtils::split(const std::string &s, char delim);

};