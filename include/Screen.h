#pragma once

#include <SDL2/SDL.h>

class Screen {
public:
  const static int SCREEN_WIDTH = 800;
  const static int SCREEN_HEIGHT = 600;

  Screen();

  bool init();
  bool processEvents();
  void update();
  void setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b);
  void clear();
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