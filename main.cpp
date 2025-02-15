#include<iostream>
#include<SDL2/SDL.h>

#include "global.cpp"
#include "dot.cpp"

int main(int argc, char *argv[]) {
  SDL_Init(SDL_INIT_EVERYTHING);

  SDL_Window *window = SDL_CreateWindow("Simple triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
  if (NULL == window) {
    std::cout << "Could not create window: " << SDL_GetError() << std::endl;
    return 1;
  }

  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  if(!renderer) {
    std::cout << "Could not create renderer: " << SDL_GetError() << std::endl;
    return 1;
  }

  bool quit = false;

  std::pair<int,int> position = {WIDTH/2, HEIGHT/2};

  SDL_Event windowEvent;
  while (!quit) {
    render_dot(renderer, position.first, position.second);
    SDL_Delay(10);

    if (SDL_PollEvent(&windowEvent)) {
      if (windowEvent.type == SDL_QUIT) {
        quit = true;
      } else if (windowEvent.type == SDL_KEYDOWN) {  // need smoother movement controls
        switch (windowEvent.key.keysym.sym) {
          case SDLK_UP:
            position.second-=10;
            continue;
          case SDLK_LEFT:
            position.first-=10;
            continue;
          case SDLK_DOWN:
            position.second+=10;
            continue;
          case SDLK_RIGHT:
            position.first+=10;
            continue;
        }
      }
    } 
  }

  SDL_DestroyWindow(window);
  SDL_Quit();

  return EXIT_SUCCESS;
}
