#ifndef GAMEMANAGER_H
#define GAMEMANAGER_H

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <RenderSystem.h>

class GameManager
{
    private:

        bool _running;
        RenderSystem *_renderSystem;
        GLFWwindow *_window;

        VertexBuffer *vertexBuffer;

        GameManager(bool running);
        ~GameManager();

    public:

        void runGameLoop();

        static GameManager& getGameManager();
        static void destroyGameManager();

    protected:


};

#endif // GAMEMANAGER_H
