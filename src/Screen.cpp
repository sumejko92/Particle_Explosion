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

  buffer_ = new Uint32[SCREEN_WIDTH * SCREEN_HEIGHT];
  memset(buffer_, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));

  update();

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

void Screen::update() {
  SDL_UpdateTexture(texture_, NULL, buffer_, SCREEN_WIDTH * sizeof(Uint32));
  SDL_RenderClear(renderer_);
  SDL_RenderCopy(renderer_, texture_, NULL, NULL);
  SDL_RenderPresent(renderer_);
}

void Screen::setPixel(int x, int y, Uint8 r, Uint8 g, Uint8 b) {

  // dont set pixels out of the window limits
  if (x < 0 || x >= SCREEN_WIDTH || y < 0 || y >= SCREEN_HEIGHT)
    return;

  Uint32 color = 0;

  color = color + r;
  color = color << 8;
  color = color + g;
  color = color << 8;
  color = color + b;
  color = color << 8;
  color = color + 0xFF;

  buffer_[(y * SCREEN_WIDTH) + x] = color;
}

void Screen::clear() {
  memset(buffer_, 0, SCREEN_WIDTH * SCREEN_HEIGHT * sizeof(Uint32));
}

bool Screen::processEvents() {
  while (SDL_PollEvent(&event_)) {
    if (event_.type == SDL_QUIT) {
      cout << "event: " << SDL_PollEvent(&event_) << endl;
      return true;
    }
  }
  return false;
}

void Screen::destroyScreen() {
  delete[] buffer_;

  SDL_DestroyRenderer(renderer_);
  SDL_DestroyTexture(texture_);
  SDL_DestroyWindow(window_);
  SDL_Quit();
}

Screen::~Screen() {}