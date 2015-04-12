#include <iostream>
#include <string>

#if !defined(CONSTANTS)
#define CONSTANTS

const int APPL_FRAMERATE = 40;

const std::string SHADER_STRUCT = "shader_vert_struct";
const std::string SHADER_TEXTURED = "shader_vert_textured";
const std::string SHADER_PATH = "build/Debug/resources/glsl/";
const std::string RELEASE_SHADER_PATH = "resources/glsl/";

const std::string MODEL_SPIRIT_PATH = "build/Debug/resources/models/";
const std::string RELEASE_MODEL_SPIRIT_PATH = "resources/models/";

const std::string TEXTURE_SPIRIT_PATH = "build/Debug/resources/models/";
const std::string RELEASE_TEXTURE_SPIRIT_PATH = "resources/models/";

const std::string SPIRIT_MODEL_NAME = "B2SPIRIT";

/* COLLISION */
const int MIN_X = 0;
const int MAX_X = 1;
const int MIN_Y = 2;
const int MAX_Y = 3;
const int MIN_Z = 4;
const int MAX_Z = 5;

#endif