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
	
	void Compile(const char *vertexSource, const char *fragmentSource, const char geometrySource = nullptr);
		// 1. Get the source code from the path
		std::string vertexCode;
		std::string fragmentCode;
		std::ifstream vShaderFile;
		std::ifstream fShaderFile;
		// ensure ifstream objects can throw exceptions:
		vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
		fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
		try
		{
			vShaderFile.open(vertexPath);
			fShaderFile.open(fragmentPath);
			std::stringstream vShaderStream, fShaderStream;
			// read the buffer contents into streams
			vShaderStream << vShaderFile.rdbuf();
			fShaderStream << fShaderFile.rdbuf();
			// KILL THE HANDLERS
			vShaderFile.close();
			fShaderFile.close();
			// Make it a string
			vertexCode 	 = vShaderStream.str();
			fragmentCode = fShaderStream.str();
		}
		catch (std::ifstream::failure e)
		{
			std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ" << std::endl;
		}
		const char* vShaderCode = vertexCode.c_str();
		const char* fShaderCode = fragmentCode.c_str();
		
		// 2. Compile
		
	
	Shader &use() {}
	
	void setBool(const std::string &name, bool value) const
	{         
		glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); 
	}
	void setInt(const std::string &name, int value) const
	{ 
		glUniform1i(glGetUniformLocation(ID, name.c_str()), value); 
	}
	void setFloat(const std::string &name, float value) const
	{ 
		glUniform1f(glGetUniformLocation(ID, name.c_str()), value); 
	}
	void setTransform(const std::string &name, glm::mat4 value) const
	{
		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(value));
	}
	
	void checkErrors(unsigned int object, std::string type);
	
};

#endif
