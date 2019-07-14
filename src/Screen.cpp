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

  return true;
}

bool Screen::createWindow() {}

bool Screen::processEvents() {}

Screen::~Screen() {}