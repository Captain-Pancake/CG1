#ifndef SHADERINTERFACE_H
#define SHADERINTERFACE_H

#include <iostream>
#include <GL/glew.h>
#include <ShaderLoader.h>

class ShaderInterface
{
    private:

        ShaderLoader *shader;

        GLint aPositionVertex;
        GLint uColor;

        char *_vertexShaderString;
        char *_fragmentShaderString;

        char *loadTextFromFile(const char *file);


    public:

        GLuint getProgramHandle();
        GLint get_aPositionVertex();
        GLint get_uColor();
        ShaderInterface(const char *VS,const char *FS);
        ~ShaderInterface();

    protected:

};

#endif // SHADERINTERFACE_H
