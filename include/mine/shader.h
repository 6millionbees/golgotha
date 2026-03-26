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
