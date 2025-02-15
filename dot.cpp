#include<iostream>

#include<SDL2/SDL.h>

void render_dot(SDL_Renderer *renderer, int x, int y) {
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);  // what is alpha channel?
  SDL_RenderClear(renderer);

  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  SDL_RenderDrawPoint(renderer, x, y);

  SDL_RenderPresent(renderer);
}

void travelling_dot(SDL_Renderer *renderer, int start_x, int start_y, int end_x, int end_y) {
  
}
