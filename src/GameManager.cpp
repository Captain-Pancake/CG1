#include "GameManager.h"

GLfloat vertices[] = {
    -0.5f, -0.5f, 0.0f,
    0.5f, -0.5f, 0.0f,
    0.0f, 0.5f, 0.0f
};

GameManager::GameManager(bool running): _running(running), _window(glfwGetCurrentContext()), _renderSystem(&RenderSystem::getRenderSystem())
{
    vertexBuffer = new VertexBuffer(vertices, sizeof(vertices),GL_TRIANGLES, 3, sizeof(GLfloat)*3);
}

GameManager::~GameManager()
{
    RenderSystem::destroyRenderSystem();
}

void GameManager::runGameLoop()
{
    while (_running)
    {
        _running = !glfwWindowShouldClose(_window); //Der Boolean Running ist gleich das gegenteil der Frage "Wurde das Fenster geschlossen". Es bleibt also true solange das Fenster offen ist.

        _renderSystem->render(vertexBuffer);
    }
}

GameManager& GameManager::getGameManager()
{
    static GameManager *gameManager = NULL;

    if(gameManager == NULL)
    {
        glfwInit(); //Initalisierung

        glfwWindowHint(GLFW_DEPTH_BITS, 24);    //Window Configuration
        glfwWindowHint(GLFW_RED_BITS, 8);
        glfwWindowHint(GLFW_GREEN_BITS, 8);
        glfwWindowHint(GLFW_BLUE_BITS, 8);
        glfwWindowHint(GLFW_ALPHA_BITS, 8);

        GLFWwindow *window = glfwCreateWindow(1280, 720, "Game Test 1.1", NULL, NULL); //Erstellt ein Fenster "window" mit den angegebenen Parametern
        glfwMakeContextCurrent(window); // Setzt das Fenster als context für openGL
        glewInit();
        gameManager = new GameManager(true);

        std::cout<<"GameManager.cpp Text1: Singleton hat gameManager Object erfolgreich erstellt."<<std::endl;
    }

    return *gameManager;
}


void GameManager::destroyGameManager()
{
    GameManager *gameManager = &getGameManager();
    if(gameManager != NULL)
    {
        std::cout<<"GameManager.cpp Text2: Singleton hat gameManager Object erfolgreich destroyed."<<std::endl;
        delete gameManager;
        GLFWwindow *window = glfwGetCurrentContext();
        glfwDestroyWindow(window);

        glfwTerminate();
    }
}
