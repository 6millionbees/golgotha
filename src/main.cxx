// Arden Boettcher
// Started: 3/23/26
// Version: 0.0.0
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
#include "myGL/spriteRenderer.h"
#include "logic/game.h"

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void processInput(GLFWwindow *window);

SpriteRenderer *Renderer;

const int WIND_WIDTH  = 250;
const int WIND_HEIGHT = 250;

int main(int argc, char **argv)
{
    // Initialization
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

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

	Shader spriteProgram = ResourceManager::LoadShader("shaders/spriteVertex.glsl", "shaders/spriteFragment.glsl", nullptr, "spriteProgram");

	glm::mat4 projection = glm::ortho(0.0f, WIND_WIDTH*1.0f, WIND_HEIGHT*1.0f, 0.0f, 1.0f, -1.0f);

	spriteProgram.Use().SetInteger("image", 0);
	spriteProgram.SetMatrix4("projection", projection, false);

	Renderer = new SpriteRenderer(spriteProgram);

	Texture2D lancaImage = ResourceManager::LoadTexture("images/img.png", true, "lanca");

	while(!glfwWindowShouldClose(window))
	{
		processInput(window);
		
		glClear(GL_COLOR_BUFFER_BIT);

		Renderer->DrawSprite(lancaImage, glm::vec2(0.0f), glm::vec2(200.0f), glfwGetTime(), glm::vec3(1.0f));
		
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


