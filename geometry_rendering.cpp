#include<SDL2/SDL.h>

void geometry_rendering(SDL_Renderer *renderer, int WIDTH, int HEIGHT) {  
  bool quit = false;
  SDL_Event windowEvent;

  while (!quit) {
    SDL_Rect simple_rectangle = {WIDTH/2, HEIGHT/2, WIDTH/2, HEIGHT/2};
    SDL_SetRenderDrawColor(renderer,0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderDrawRect(renderer, &simple_rectangle);

    SDL_Rect fill_rectangle = {WIDTH/3, HEIGHT/3, WIDTH/3, HEIGHT/3};
    SDL_SetRenderDrawColor(renderer,0xFF, 0x00, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &fill_rectangle);

    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0xFF, 0xFF);
    SDL_RenderDrawLine(renderer, 0, 0, WIDTH, HEIGHT);

    SDL_RenderPresent(renderer);

    if(SDL_PollEvent(&windowEvent)) {
      if (windowEvent.type == SDL_QUIT) {
        quit = true;
      }
    }
  }
}