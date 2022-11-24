#include <iostream>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

typedef struct
{
    float x;
    float y;
} coordinate;

int main(void)
{
    GLFWwindow* window;

    if (!glfwInit()) return 1;

    window = glfwCreateWindow(800, 600, "Hello World", NULL, NULL); //CREATE WINDOW
    if (!window)
    {
        glfwTerminate();
        return 1;
    }

    glfwMakeContextCurrent(window);

    if (glewInit() != GLEW_OK) //INIT GLEW
    {
        std::cerr << "Glew failed to init!" << std::endl;
        return 1;
    }

    coordinate coord1 = { -.5f, -.5f };
    coordinate coord2 = { .5f, -.5f };
    coordinate coord3 = { -.0f, .5f };

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        glVertex2f(coord1.x, coord1.y);
        glVertex2f(coord2.x, coord2.y);
        glVertex2f(coord3.x, coord3.y);

        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}