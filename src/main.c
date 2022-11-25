#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>

//TYPEDEFS
typedef struct
{
    float x;
    float y;
} coordinate;

//FUNCTIONS
float countDistance(coordinate c1, coordinate c2);
void divideCoord(coordinate *coord);

//CONSTS
#define WIDTH 1024
#define HEIGHT 768

const coordinate coord1 = { -.5f, -.5f };
const coordinate coord2 = { +.5f, -.5f };
const coordinate coord3 = { +.0f, +.5f };

int main(void)
{
    glewExperimental = true;

    if (!glfwInit())
    {
        fprintf(stderr, "Failed to initialize GLFW\n");
        return -1;
    }

    /*glfwWindowHint(GLFW_SAMPLES, 4); //4x antialiasing
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); //OpenGL 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //MacOS
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //No old OpenGL*/

    //Open a window and create its OpenGL context
    GLFWwindow* window;
    window = glfwCreateWindow(WIDTH, HEIGHT, "BezvyznamnaPochvala", NULL, NULL);

    if (window == NULL)
    {
        fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n");

        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window); //Initialize GLEW

    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize GLEW\n");
        return -1;
    }

    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    while (glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && glfwWindowShouldClose(window) == 0)
    {
        glClear(GL_COLOR_BUFFER_BIT);

        glBegin(GL_TRIANGLES);

        glVertex2f(coord1.x, coord1.y);
        glVertex2f(coord2.x, coord2.y); //TODO: This drawing shit doesn't work
        glVertex2f(coord3.x, coord3.y);

        glEnd();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();

    }

    glfwTerminate();
}

float countDistance(coordinate c1, coordinate c2)
{
    return sqrt(pow(c2.x - c1.x, 2) + pow(c2.y - c1.y, 2));
}

void divideCoord(coordinate *coord)
{
    coord -> x /= 2;
    coord -> y /= 2;
}