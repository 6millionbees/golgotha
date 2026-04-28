#include <iostream>
#include <sstream>
#include <fstream>

#include "resourceManager.h"

// I'm actually just going to die
std::map<std::string, Texture2D>    ResourceManager::Textures;
std::map<std::string, Shader>       ResourceManager::Shaders;

// Shader Functions
// =================================================================
Shader ResourceManager::LoadShader(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile, std::string name)
{
	Shaders[name] = loadShaderFromFile(vShaderFile, fShaderFile, gShaderFile);
	return Shaders[name];
}

Shader ResourceManager::GetShader(std::string name)
{
	return Shaders[name];
}


// Texture Functions
// =================================================================
Texture2D ResourceManager::LoadTexture(const char file, bool alpha, std::string name)
{
	//~ Textures[name] = loadTextureFromFile(file, alpha);
	return Textures[name];
}

Texture2D ResourceManager::GetTexture(std::string name)
{
	return Textures[name];
}


void ResourceManager::Clear()
{
	for (auto iter : Shaders)
		glDeleteProgram(iter.second.ID);
	for (auto iter : Textures)
		glDeleteTextures(1, &iter.second.ID);
}


// Shader Loader
// =================================================================
Shader ResourceManager::loadShaderFromFile(const char *vShaderFile, const char *fShaderFile, const char *gShaderFile)
{
	std::string vCode, fCode, gCode;
	try
    {
        std::ifstream vertexShaderFile(vShaderFile);
        std::ifstream fragmentShaderFile(fShaderFile);
        std::stringstream vShaderStream, fShaderStream;
        
        vShaderStream << vertexShaderFile.rdbuf();
        fShaderStream << fragmentShaderFile.rdbuf();
        
        vertexShaderFile.close();
        fragmentShaderFile.close();
        
        vCode = vShaderStream.str();
        fCode = fShaderStream.str();
        
        if (gShaderFile != nullptr)
        {
            std::ifstream geometryShaderFile(gShaderFile);
            std::stringstream gShaderStream;
            
            gShaderStream << geometryShaderFile.rdbuf();
            geometryShaderFile.close();
            
            std::string gCode = gShaderStream.str();
            
        }
    }
    catch (std::ifstream::failure& e)
    {
        std::cout << "FATAL ERROR::SHADER::FILE_NOT_SUCCESSFULLY_READ: " << e.what() << std::endl;
    }

	const char *vertexCode = vCode.c_str();
	const char *fragmentCode = fCode.c_str();
	const char *geometryCode = gCode.c_str();
    
    Shader shader;
    shader.Compile(vertexCode, fragmentCode, gShaderFile != nullptr ? geometryCode : nullptr);
    return shader;
}


//~ Texture2D ResourceManager::loadTextureFromFile(const char *file, bool alpha)
//~ {
    //~ Texture2d texture;
    //~ return texture;
//~ }
