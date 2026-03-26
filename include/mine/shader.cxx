#include "shader_s.h"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>


Shader &Shader::Use()
{
	glUseProgram(this->ID);
	return *this;
}

Shader::Compile(const char *vertexSource, const char *fragmentSource, const char *geometrySource = nullptr)
{
	unsigned int vShader, fShader, gShader;
	int success;
	char infoLog[512];
	
	// Vertex
	vShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vShader, 1, &vertexSource, 0);
	glCompileShader(vShader);
	checkErrors(vShader, "VERTEX");
	
	// Fragment
	fShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fShader, 1, &fragmentSource, 0);
	glCompileShader(fShader);
	checkErrors(fShader, "FRAGMENT");
	
	// Geometry
	if (geometrySource != nullptr)
	{
		gShader = glCreateShader(GL_GEOMETRY_SHADER);
		glShaderSource(gShader, 1, &geometrySource, 0);
		glCompileShader(gShader);
		checkErrors(gShader, "GEOMETRY");
	}
	
	// Program
	this->ID = glCreateProgram();
	glAttachShader(this->ID, vShader);
	glAttachShader(this->ID, fShader);
	if (geometrySource != nullptr)
		glAttachShader(this->ID, gShader);
	glLinkProgram(this->ID);
	checkErrors(this->ID, "PROGRAM");
	
	// Kill EVERYTHING
	glDeleteShader(vShader);
    glDeleteShader(fShader);
    if (geometrySource != nullptr)
        glDeleteShader(gShader);
}


void Shader::checkErrors(unsigned int object, std::string type) 
{
	int success;
	char infoLog[1024];
	if (type != "PROGRAM")
	{
		glGetShaderiv(object, GL_COMPILE_STATUS, &success);
		if (!success)
		{
			glGetShaderInfoLog(object, 1024, NULL, infoLog);
			std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
					<< infoLog << "\n -- --------------------------------------------------- -- "
					<< std::endl;
		}
	}
	else
    {
        glGetProgramiv(object, GL_LINK_STATUS, &success);
        if (!success)
        {
            glGetProgramInfoLog(object, 1024, NULL, infoLog);
            std::cout << "| ERROR::Shader: Link-time error: Type: " << type << "\n"
                << infoLog << "\n -- --------------------------------------------------- -- "
                << std::endl;
        }
    }
}
