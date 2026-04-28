// Arden Boettcher
// Started: 3/23/26
// Version: 0.0.1
// Golgotha

// OpenGL loaders
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// Math <3
#include <glm/glm.hpp>
																																														
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <cmath>

// Iostream
#include <iostream>

// My Stuff :)
#include "myGL/resourceManager.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

const int WIND_WIDTH  = 720;
const int WIND_HEIGHT = 576;

int main(int argc, char **argv)
{
    // Initialization
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

#ifdef __APPLE__
    // For MacOS
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
    
    GLFWwindow* window = glfwCreateWindow(
		WIND_WIDTH, WIND_HEIGHT, "Golgotha 0.0.0", 0, 0);
	if (!window)
	{
		std::cout << "Failed to create window" << std::endl;
		glfwTerminate();
		return 1;
	}
	
	glfwMakeContextCurrent(window);
	// Register Framebuffer
	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

	// Load Glad
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return 1;
	}

	// Set viewport to window size
	glViewport(0, 0, WIND_WIDTH, WIND_HEIGHT);

	float vertices[] = {
		 0.5f,  0.5f, 0.0f,
		 0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f,  0.5f, 0.0f
	};

	int indices[] = {
		0, 1, 2,
		0, 2, 3
	};
	
	Shader baseShader = ResourceManager::LoadShader("shaders/vertex.glsl", "shaders/fragment.glsl", nullptr, "base");
	
	// OoooooOOooOoooOooo
	// Buffers and Array
	unsigned int VAO, VBO, EBO;
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);
	
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	
	glGenBuffers(1, &EBO);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
	
	
	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	
	while(!glfwWindowShouldClose(window))
	{
		processInput(window);
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		baseShader.Use();
		
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
}

void processInput(GLFWwindow *window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}



void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	glViewport(0, 0, width, height);
	//~ std::cout << width << ", " << height << std::endl;
}

