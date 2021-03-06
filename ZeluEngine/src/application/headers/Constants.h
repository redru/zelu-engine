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

#endif