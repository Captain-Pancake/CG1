#include "ShaderInterface.h"
#include <stdio.h>
#include <stdlib.h>

GLuint ShaderInterface::getProgramHandle()
{
    return shader->getProgramHandle();
}

GLint ShaderInterface::get_aPositionVertex()
{
    return aPositionVertex;
}

GLint ShaderInterface::get_uColor()
{
    return uColor;
}
ShaderInterface::ShaderInterface(const char *VS,const char *FS)
{
    _vertexShaderString = loadTextFromFile(VS);
    _fragmentShaderString = loadTextFromFile(FS);

    shader = new ShaderLoader(_vertexShaderString,_fragmentShaderString);

    free(_vertexShaderString);
    free(_fragmentShaderString);

    aPositionVertex = glGetAttribLocation(shader->getProgramHandle(), "aPositionVertex");

    uColor = glGetUniformLocation(shader->getProgramHandle(),"uColor");

}

ShaderInterface::~ShaderInterface()
{
    delete shader;
}

char *ShaderInterface::loadTextFromFile(const char *file)
{
    FILE *currentFile = fopen(file, "rt");
    fseek(currentFile, 0, SEEK_END);
    int count = (int)ftell(currentFile); //amount of characters in file

    rewind(currentFile);
    char *data = (char *)malloc(sizeof(char)*(count+1)); //Allukiert speicher
    count = (int)fread(data, sizeof(char),count, currentFile);
    data[count] = '\0';
    fclose(currentFile);
    return data;
}


