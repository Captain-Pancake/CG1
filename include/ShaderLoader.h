#ifndef SHADERLOADER_H
#define SHADERLOADER_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class ShaderLoader
{
    private:

        GLuint _programHandle;

        GLuint compileShader(GLenum, const char *source);

    public:

        GLuint getProgramHandle();
        ShaderLoader(const char *sourceVS, const char *sourceFS);
        ~ShaderLoader();

    protected:


};

#endif // SHADERLOADER_H
