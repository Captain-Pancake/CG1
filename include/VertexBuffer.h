#ifndef VERTEXBUFFER_H
#define VERTEXBUFFER_H


#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

/*

#include <GL/glext.h>﻿
*/



class VertexBuffer
{
    private:

        GLuint _vertexBufferID;

        GLenum _mode;
        GLsizei _count;
        GLsizei _stride;

    public:

        GLuint getVertexBuffer();

        VertexBuffer(const GLvoid *data, GLsizeiptr size, GLenum mode, GLsizei count, GLsizei stride);
        ~VertexBuffer();

        void renderVertexBuffer();
        void configureVertexAttributes(GLint vertexPosition);

};

#endif // VERTEXBUFFER_H
