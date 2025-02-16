
#include<SDL2/SDL.h>
#include <utility>

#include "dot.cpp"


void single_arrow_movement(SDL_Renderer *renderer, int start_x, int start_y) {
  bool quit = false;

  std::pair<int,int> position = {start_x, start_y};

  SDL_Event windowEvent;
  while (!quit) {
    render_dot(renderer, position.first, position.second);
    // SDL_Delay(10);

    if (SDL_PollEvent(&windowEvent)) {
      if (windowEvent.type == SDL_QUIT) {
        quit = true;
      } else if (windowEvent.type == SDL_KEYDOWN) {  // need smoother movement controls
        switch (windowEvent.key.keysym.sym) {
          case SDLK_UP:
            position.second-=10;
            break;
          case SDLK_LEFT:
            position.first-=10;
            break;
          case SDLK_DOWN:
            position.second+=10;
            break;
          case SDLK_RIGHT:
            position.first+=10;
            break;
        }
      }
    } 
  }
}

