#ifndef RESOURCE_MANAGER_H 
#define RESOURCE_MANAGER_H

#include <map>
#include <string> 


#include <glad/glad.h>

#include "shader.hpp"

class ResourceManager
{
public:
	// Attribs
	static std::map<std::string, Shader> 	Shaders;
	static std::map<std::string, Texture2D> Textures;
	
	// Shader Functions
	static Shader LoadShader(
		const char *vShaderFile,
		const char *fShaderFile,
		const char *gShaderFile,
		std::string name);
	static Shader GetShader(std::string name);
	
	// Texture Functions
    static Texture2D LoadTexture(const char file, bool alpha, std::string name);
    static Texture2D GetTexture(std::string name);

	// Util
	static void Clear();
private:
	// Loaders
	static Shader loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile = nullptr);
	static Texture2D loadTextureFromFile(const char file, bool alpha);
}
