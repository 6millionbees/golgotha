#ifndef SHADER_H
#define SHADER_H

#include <string>

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader
{
public:
	unsigned int ID;
	
	Shader() {}
	
	void Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr);

    void checkErrors(unsigned int object, std::string type);
    
    Shader &Use();
};

#endif
