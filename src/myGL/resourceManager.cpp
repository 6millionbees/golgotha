#include <iostream>
#include <sstream>
#include <fstream>

#include "resourceManager.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


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
Texture2D ResourceManager::LoadTexture(const char *file, bool alpha, std::string name)
{
	Textures[name] = loadTextureFromFile(file, alpha);
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


Texture2D ResourceManager::loadTextureFromFile(const char *file, bool alpha)
{
    Texture2D texture;
    if (alpha)
    {
        texture.Internal_Format = GL_RGBA;
        texture.Image_Format = GL_RGBA;
    }
    // load data with stbi
    int width, height, nrChannels;
    unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
    if (!data)
    {
        std::cout << "Error::Failure to load texture: " << file;
    }
    // put the texture in the bag
    texture.Generate(width, height, data);
    // free the data from it's mortal coil
    stbi_image_free(data);
    return texture;
}
