#ifndef RENDERSYSTEM_H
#define RENDERSYSTEM_H

#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>

#define GLFW_INCLUDE_GLU
#include <GLFW/glfw3.h>
#include <GL/freeglut_std.h>
#include <GL/freeglut_ext.h>
#include <VertexBuffer.h>
#include <vector>
#include <ShaderInterface.h>



class RenderSystem
{
    private:

        GLFWwindow *_window;

        std::vector<ShaderInterface *> *shaderArray;

        RenderSystem();
        ~RenderSystem();

    public:

        void render();
        void render(VertexBuffer *vertexBuffer);
        static RenderSystem& getRenderSystem();
        static void destroyRenderSystem();

    protected:


};

#endif // RENDERSYSTEM_H
