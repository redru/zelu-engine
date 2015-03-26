#include "../../engine/headers/FileUtils.h"

string FileUtils::readFile(const string path) {
	fstream input;
	string tmp;
	string file{};

	input.open(path);
	while (getline(input, tmp)) {
		file.append(tmp + "\n");
	}

	cout << "------- Loaded file: " + path + " -------" + "\n";
	cout << file << "\n";
	cout << "----------------------------------------------------------\n";
	input.close();

	return file;
}