#include "../../engine/headers/FileUtils.h"

std::string FileUtils::readFile(const std::string path) {
	std::fstream input;
	std::string tmp;
	std::string file{};

	input.open(path);
	while (getline(input, tmp)) {
		file.append(tmp + "\n");
	}

	std::cout << "------- Loaded file: " + path + " -------" + "\n";
	std::cout << file << "\n";
	std::cout << "----------------------------------------------------------\n";
	input.close();

	return file;
}

std::vector<std::string> FileUtils::readFileToVector(const std::string path) {
	std::fstream input;
	std::string tmp;
	std::vector<std::string> lines{};

	input.open(path);
	while (getline(input, tmp)) {
		lines.push_back(tmp);
	}

	std::cout << "FileUtils - readFileToVector -> Loaded file: " + path << std::endl;
	input.close();

	return lines;
}

std::vector<std::string>& FileUtils::split(const std::string &s, char delim, std::vector<std::string> &elems) {
	std::stringstream ss(s);
	std::string item;
	while (std::getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


std::vector<std::string> FileUtils::split(const std::string &s, char delim) {
	std::vector<std::string> elems;
	split(s, delim, elems);
	return elems;
}