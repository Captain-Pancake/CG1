#include "RenderSystem.h"
#include "GL/glu.h"
#include "GL/gl.h"
#include "GL/freeglut.h"

RenderSystem::RenderSystem(): _window(glfwGetCurrentContext())
{
    shaderArray = new std::vector<ShaderInterface *>;
    ShaderInterface *shader = new ShaderInterface("ColorShader.vsh", "ColorShader.fsh");
    shaderArray->push_back(shader);
}

RenderSystem::~RenderSystem()
{
    delete shaderArray->at(0);
    delete shaderArray;
}

void RenderSystem::render(VertexBuffer *vertexBuffer)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glUseProgram(1);

    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, -5.0f, 0.0f, 0.0f, 0.0f,0.0f, 1.0f, 0.0f);


    glUniform4f(0, 1.0f, 0.0f, 0.0f, 1.0f);

    vertexBuffer->configureVertexAttributes(0);
    vertexBuffer->renderVertexBuffer();

    glfwSwapBuffers(_window);//Updates parameter Context durch tausch von front und back buffer (60 fps)
    glfwPollEvents();       // Überprüft user dependet events

}


RenderSystem& RenderSystem::getRenderSystem()
{
    static RenderSystem *renderSystem = NULL;

    if(renderSystem == NULL){
        renderSystem = new RenderSystem();
        glClearColor(1.0f,1.0f,1.0f,1.0f);

        glMatrixMode(GL_PROJECTION);
        gluPerspective(75.0f, 1280.0f/720.0f, 1, 1000);
        glViewport(0.0f,0.0f,1280.0f, 720.0f);
        glMatrixMode(GL_MODELVIEW);
    }
    return *renderSystem;
}

void RenderSystem::destroyRenderSystem()
{
    RenderSystem *renderSystem = &getRenderSystem();
    delete renderSystem;
}
