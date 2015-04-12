#include <stdio.h>
#include <GL/glew.h>
#include <SDL2/SDL.h>

#define TITLEBAR "OpenGL"
#define WIDTH 800
#define HEIGHT 300
#define TRUE 1
#define FALSE 0

void update(SDL_Window *window, int *m_isClosed);


int main(int argc, char *argv[]) {
    // Declare the window
    SDL_Window *m_window;
    // Declare the OpenGL context
    SDL_GLContext m_glContext;
    // Keep track of open/closed state
    int *m_isClosed = malloc(sizeof(int));
    *m_isClosed = FALSE;

    // Initialize SDL
    SDL_Init(SDL_INIT_EVERYTHING);
    // Set GL attributes for SDL
    SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);
    SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    // Create the window
    m_window = SDL_CreateWindow(TITLEBAR, SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL);
    // Create the context
    m_glContext = SDL_GL_CreateContext(m_window);

    // GLEW enum
    GLenum status = glewInit();

    if (status != GLEW_OK) {
        perror("glew");
        exit(1);
    }

    // Main loop
    while (*m_isClosed == FALSE) {
        glClearColor(0.5f, 0.15f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        update(m_window, m_isClosed);
    }

    // Delete the context
    SDL_GL_DeleteContext(m_glContext);
    // Destroy the window
    SDL_DestroyWindow(m_window);
    // Close SDL
    SDL_Quit();

    return 0;
}

void update(SDL_Window *window, int *m_isClosed) {
    SDL_GL_SwapWindow(window);

    SDL_Event e;

    while(SDL_PollEvent(&e)) {
        if (e.type == SDL_QUIT) {
            *m_isClosed = TRUE;
        }
    }
}
