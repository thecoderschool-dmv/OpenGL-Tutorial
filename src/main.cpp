#include <iostream>
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "settings/settings.hpp"
#include <fstream>
#include <string>

int BackgroundColorR = 0;
int BackgroundColorG = 0;
int BackgroundColorB = 0;
int BackgroundColorA = 255;

bool BackgroundColorCycleDirection = true; //true means that the value is increasing, false vice versa

unsigned int VAO, shaderProgram;

float vertices[] = {
  -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f,  0.5f, 0.0f
};

const char* vShader = R"(#version 330 core
layout(location = 0) in vec3 aPos;
out vec2 VertexPosition;
void main()
{
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
    VertexPosition = vec2(aPos.x,aPos.y);
}
)";

const char* fShader = R"(#version 330 core
out vec4 FragColor;
in vec2 VertexPosition;

void main()
{
    FragColor = vec4(VertexPosition.x, 0.0f, VertexPosition.y, 1.0f);
}
)";

void genTriangleData() {

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int vertexShader;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);

    glShaderSource(vertexShader, 1, &vShader, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader;
    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

    glShaderSource(fragmentShader, 1, &fShader, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

}

void render(GLFWwindow* window) {

    /*
    if (BackgroundColorCycleDirection == true) {
        BackgroundColorR += 2;
        BackgroundColorG += 2;
        BackgroundColorB += 2;
        if (BackgroundColorR > 133) {
            BackgroundColorCycleDirection = false;
        }
    }
    else if (BackgroundColorCycleDirection == false) {
        BackgroundColorR -= 2;
        BackgroundColorG -= 2;
        BackgroundColorB -= 2;
        if (BackgroundColorR < 0) {
            BackgroundColorCycleDirection = true;
        }
    }
    */

    glClearColor((float)BackgroundColorR / 255, (float)BackgroundColorG / 255, (float)BackgroundColorB / 255, BackgroundColorA / 255);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);
    glBindVertexArray(VAO);




    glDrawArrays(GL_TRIANGLES, 0, 3);

}

int main()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    //glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

    GLFWwindow* window = glfwCreateWindow(640, 360, "down the rockefeller street", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "GLFW window didn't want to exist (failed to initialize)" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "GLAD ceased to exist (failed to initialize)" << std::endl;
        return -1;
    }

    glViewport(0, 0, 640, 360);


    // settings i guess

    //vsync
    if (VSYNC_ENABLED == true) {
        std::cout << "VSync Enabled" << std::endl;
        glfwSwapInterval(1);
    } else if (VSYNC_ENABLED == false) {
        std::cout << "VSync Disabled" << std::endl;
        glfwSwapInterval(0);
    }

    //anti-aliasing (seems to be completely broken, but prob bc the only thing being rendered is 2D)
    if (ANTI_ALIASING_SAMPLES > 0) {
        std::cout << "Anti-Aliasing Enabled" << std::endl;
        glfwWindowHint(GLFW_SAMPLES, ANTI_ALIASING_SAMPLES);
        glEnable(GL_MULTISAMPLE);
    }
    else {
        std::cout << "Anti-Aliasing Disabled" << std::endl;
    }

    genTriangleData();

    while (!glfwWindowShouldClose(window))
    {
        render(window);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}