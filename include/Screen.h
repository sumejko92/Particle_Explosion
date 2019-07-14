#pragma once

#include <SDL2/SDL.h>

class Screen {
public:
  const static int SCREEN_WIDTH = 800;
  const static int SCREEN_HEIGHT = 600;

  Screen();

  bool init();
  bool processEvents();
  void destroyScreen();

  ~Screen();

private:
  SDL_Window *window_;
  SDL_Renderer *renderer_;
  SDL_Texture *texture_;
  Uint32 *buffer_;

  SDL_Event event_;

  bool createWindow();
};