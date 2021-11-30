#include <iostream>
#include "glad/glad.h"
#include "glfw/glfw3.h"
#include "settings/settings.hpp"
#include "shader.hpp"
#include <fstream>
#include <string>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

int BackgroundColorR = 0;
int BackgroundColorG = 0;
int BackgroundColorB = 0;
int BackgroundColorA = 255;

bool BackgroundColorCycleDirection = true; //true means that the value is increasing, false vice versa

unsigned int VAO;
Shader* deezshaders;
Shader* skibidabopmmdada;


float vertices[] = {
  -0.5f, -0.5f, 0.5f,
    0.5f, -0.5f, 0.5f,
    0.5f,  0.5f, 0.5f,
    -0.5f, 0.5f, 0.5f,

    -0.5f, -0.5f, -0.5f,
    0.5f, -0.5f, -0.5f,
    0.5f,  0.5f, -0.5f,
    -0.5f, 0.5f, -0.5f
};

unsigned int EBO[] = {
    0,1,2,
    0,2,3,
    4,5,6,
    4,6,7,
    0,4,7,
    0,7,3,
    1,5,6,
    1,6,2,
    0,1,5,
    0,5,4,
    3,6,7,
    3,6,2
};

void genTriangleData() {

    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);


    unsigned int VBO;
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    unsigned int ebo;
    glGenBuffers(1, &ebo);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(EBO), EBO, GL_STATIC_DRAW);

    deezshaders = new Shader("triangle/vShader.glsl", "triangle/fShader.glsl");
    skibidabopmmdada = new Shader("triangle/vshader.glsl", "triangle/skibidabopmmdada.glsl");

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
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (PASS_COLOR_CYCLE_TO_GPU_AS_TIME == true) {
        skibidabopmmdada->use();

        glm::mat4 rotation = glm::mat4(1.0f);
        rotation = glm::rotate(rotation, glm::radians((float)glfwGetTime() * 64.0f), glm::vec3(0.0f, 1.0f, 1.0f));

        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, -0.2f, -3.0f));

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);

        glm::mat4 beesechurger = projection * view * rotation;
        skibidabopmmdada->setMat4("cheeseburger",beesechurger);
    }
    else {
        deezshaders->use();

        glm::mat4 view = glm::mat4(1.0f);
        view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));

        glm::mat4 projection;
        projection = glm::perspective(glm::radians(45.0f), 800.0f / 600.0f, 0.1f, 100.0f);
    };

    float TimeValue = glfwGetTime();
    //float Frequency = ((sin(TimeValue)) * 4) + 4; // exponential seizure owo
    //float Frequency = 2;
    if (COLOR_CYCLE_EXPONENTIAL_SEIZURE == true && PASS_COLOR_CYCLE_TO_GPU_AS_TIME == false) {
        float Frequency = ((sin(TimeValue)) * 4) + 4;
        float RValue = (sin(TimeValue * Frequency) / 2.0f) + 0.5f;
        float GValue = (sin(TimeValue * Frequency) / 4.0f) + 0.25f;
        float BValue = (sin(TimeValue * Frequency) / 10.0f) + 0.1f;
        //int vertexColorLocation = glGetUniformLocation(shaderProgram, "CurrentColor");
        //glUniform3f(vertexColorLocation, RValue, GValue, BValue);
    }
    else if (COLOR_CYCLE_EXPONENTIAL_SEIZURE == false && PASS_COLOR_CYCLE_TO_GPU_AS_TIME == false) {
        float Frequency = COLOR_CYCLE_FREQUENCY;
        float RValue = (sin(TimeValue * Frequency) / 2.0f) + 0.5f;
        float GValue = (sin(TimeValue * Frequency) / 4.0f) + 0.25f;
        float BValue = (sin(TimeValue * Frequency) / 10.0f) + 0.1f;
        deezshaders->setVec3("CurrentColor", RValue, GValue, BValue);
        //glUniform3f(vertexColorLocation, RValue, GValue, BValue);
    }
    else {
        //int vertexColorLocation = glGetUniformLocation(skibidabopmmprogram, "TIME");
        //glUniform1f(vertexColorLocation, TimeValue);
        skibidabopmmdada->setFloat("t",TimeValue);
    };

    glBindVertexArray(VAO);




    glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0);

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

    //anti-aliasing (completely borked and i don't know why)
    if (ANTI_ALIASING_SAMPLES > 0) {
        std::cout << "Anti-Aliasing Enabled" << std::endl;
        glfwWindowHint(GLFW_SAMPLES, ANTI_ALIASING_SAMPLES);
        glEnable(GL_MULTISAMPLE);
    }
    else {
        std::cout << "Anti-Aliasing Disabled" << std::endl;
    }

    glEnable(GL_DEPTH_TEST);
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