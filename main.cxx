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
#include "myGL/shader.h"
#include "myGL/resource_manager.h"


int main()
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
    
    
}
