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
#include "myGL/shader.hpp"
#include "myGL/resource_manager.hpp"

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
		WIND_WIDTH, WIND_HEIGHT, "Golgotha 0.0.1", 0, 0);
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

	
}

