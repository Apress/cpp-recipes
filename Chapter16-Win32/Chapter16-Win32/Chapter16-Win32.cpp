// Chapter16-Win32.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <GL/glew.h>
#include "GLFW/glfw3.h"
#include <string>
#include <vector>

using namespace std;

//////////////////////////////////////////////////////////////////////////
//
// Recipe 16-1
//
//////////////////////////////////////////////////////////////////////////

/*int CALLBACK WinMain(
    _In_  HINSTANCE hInstance,
    _In_  HINSTANCE hPrevInstance,
    _In_  LPSTR lpCmdLine,
    _In_  int nCmdShow
    )
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    GLenum glewError{ glewInit() };
    if (glewError != GLEW_OK)
    {
        return -1;
    }

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}*/

//////////////////////////////////////////////////////////////////////////
//
// Recipe 16-2
//
//////////////////////////////////////////////////////////////////////////

/*#include "BasicShader.h"
#include "Geometry.h"

int CALLBACK WinMain(
    _In_  HINSTANCE hInstance,
    _In_  HINSTANCE hPrevInstance,
    _In_  LPSTR lpCmdLine,
    _In_  int nCmdShow
    )
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    GLenum glewError{ glewInit() };
    if (glewError != GLEW_OK)
    {
        return -1;
    }

    BasicShader basicShader;
    basicShader.Link();

    Geometry triangle;

    Geometry::Vertices vertices{
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f
    };

    Geometry::Indices indices{ 0, 1, 2 };

    triangle.SetVertices(vertices);
    triangle.SetIndices(indices);

    glClearColor(0.25f, 0.25f, 0.95f, 1.0f);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        basicShader.Setup(triangle);

        glDrawElements(GL_TRIANGLES,
            triangle.GetNumIndices(),
            GL_UNSIGNED_SHORT,
            triangle.GetIndices());

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}*/

//////////////////////////////////////////////////////////////////////////
//
// Recipe 16-3
//
//////////////////////////////////////////////////////////////////////////

/*#include "Geometry.h"
#include "TextureShader.h"
#include "TGAFile.h"

int CALLBACK WinMain(
    _In_  HINSTANCE hInstance,
    _In_  HINSTANCE hPrevInstance,
    _In_  LPSTR lpCmdLine,
    _In_  int nCmdShow
    )
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(640, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    GLenum glewError{ glewInit() };
    if (glewError != GLEW_OK)
    {
        return -1;
    }

    TGAFile myTextureFile("MyTexture.tga");
    Texture myTexture(myTextureFile);
    myTexture.Init();

    TextureShader textureShader(myTexture);
    textureShader.Link();

    Geometry quad;

    Geometry::Vertices vertices{
        -0.5f, 0.5f, 0.0f,
        0.0f, 1.0f,
        0.5f, 0.5f, 0.0f,
        1.0f, 1.0f,
        -0.5f, -0.5f, 0.0f,
        0.0f, 0.0f,
        0.5f, -0.5f, 0.0f,
        1.0f, 0.0f
    };

    Geometry::Indices indices{ 0, 2, 1, 2, 3, 1 };

    quad.SetVertices(vertices);
    quad.SetIndices(indices);
    quad.SetNumVertexPositionElements(3);
    quad.SetNumTexCoordElements(2);
    quad.SetVertexStride(sizeof(float) * 5);

    glClearColor(0.25f, 0.25f, 0.95f, 1.0f);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);

        textureShader.Setup(quad);

        glDrawElements(GL_TRIANGLES,
            quad.GetNumIndices(),
            GL_UNSIGNED_SHORT,
            quad.GetIndices());

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}*/

//////////////////////////////////////////////////////////////////////////
//
// Recipe 16-4
//
//////////////////////////////////////////////////////////////////////////

#include "Geometry.h"
#include "OBJFile.h"
#include "TGAFile.h"
#include "TextureShader.h"

int CALLBACK WinMain(
    _In_  HINSTANCE hInstance,
    _In_  HINSTANCE hPrevInstance,
    _In_  LPSTR lpCmdLine,
    _In_  int nCmdShow
    )
{
    GLFWwindow* window;

    // Initialize the library
    if (!glfwInit())
    {
        return -1;
    }

    glfwWindowHint(GLFW_RED_BITS, 8);
    glfwWindowHint(GLFW_GREEN_BITS, 8);
    glfwWindowHint(GLFW_BLUE_BITS, 8);
    glfwWindowHint(GLFW_DEPTH_BITS, 8);
    glfwWindowHint(GLFW_DOUBLEBUFFER, true);

    // Create a windowed mode window and its OpenGL context
    window = glfwCreateWindow(480, 480, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    GLenum glewError{ glewInit() };
    if (glewError != GLEW_OK)
    {
        return -1;
    }

    TGAFile myTextureFile("earthmap.tga");
    Texture myTexture(myTextureFile);
    myTexture.Init();

    TextureShader textureShader(myTexture);
    textureShader.Link();

    OBJFile objSphere("sphere.obj");
    Geometry sphere(objSphere);

    sphere.SetNumVertexPositionElements(3);
    sphere.SetNumTexCoordElements(2);
    sphere.SetVertexStride(sizeof(float) * 5);

    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);

    // Loop until the user closes the window
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        textureShader.Setup(sphere);

        glDrawElements(GL_TRIANGLES,
            sphere.GetNumIndices(),
            GL_UNSIGNED_SHORT,
            sphere.GetIndices());

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}