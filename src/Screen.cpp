#include "../include/Screen.h"
#include <iostream>

using namespace std;

Screen::Screen()
    : window_(NULL), renderer_(NULL), texture_(NULL), buffer_(NULL) {
  cout << "Window constructor called" << endl;
}
bool Screen::init() {
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    cout << "SDL initialization failed." << endl;
    return false;
  }
  cout << "SDL initialization succeeded." << endl;

  if (!createWindow()) {
    return false;
  }

  return true;
}

bool Screen::createWindow() {
  window_ = SDL_CreateWindow("Particle Explosion", SDL_WINDOWPOS_UNDEFINED,
                             SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH,
                             SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

  if (window_ == NULL) {
    cout << SDL_GetError() << endl;
    return false;
  }
  cout << "Window created" << endl;

  renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_PRESENTVSYNC);

  if (renderer_ == NULL) {
    cout << " Could not return renderer" << endl;
    return false;
  }
  cout << "Renderer created" << endl;

  texture_ =
      SDL_CreateTexture(renderer_, SDL_PIXELFORMAT_RGBA8888,
                        SDL_TEXTUREACCESS_STATIC, SCREEN_WIDTH, SCREEN_HEIGHT);

  if (texture_ == NULL) {
    cout << " Could not return texture" << endl;
    return false;
  }
  cout << "Texture created" << endl;

  return true;
}

bool Screen::processEvents() {}

void Screen::destroyScreen() {
  SDL_DestroyRenderer(renderer_);
  SDL_DestroyTexture(texture_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

Screen::~Screen() {}