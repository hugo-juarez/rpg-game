#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <glad/gl.h>

#include <cstdio>

#include "SDL3/SDL_video.h"

int main(int argc, char* argv[]) {
  SDL_Window* window;

  bool done = false;

  SDL_Init(SDL_INIT_VIDEO);

  // OpengGL Flags
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
#ifdef __APPLE__
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS,
                      SDL_GL_CONTEXT_FORWARD_COMPATIBLE_FLAG);
#endif

  window = SDL_CreateWindow("An SDL3 window", 640, 480, SDL_WINDOW_OPENGL);

  if (window == NULL) {
    SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n",
                 SDL_GetError());
    return 1;
  }

  SDL_GLContext ctx = SDL_GL_CreateContext(window);
  SDL_GL_MakeCurrent(window, ctx);
  SDL_GL_SetSwapInterval(1);

  if (!gladLoadGL((GLADloadfunc)SDL_GL_GetProcAddress)) {
    std::printf("Failed to load OpenGL\n");
    return 1;
  }

  while (!done) {
    SDL_Event event;

    while (SDL_PollEvent(&event)) {
      if (event.type == SDL_EVENT_QUIT) {
        done = true;
      }

      SDL_GL_SwapWindow(window);
    }
  }

  SDL_DestroyWindow(window);

  SDL_Quit();

  return 0;
}
