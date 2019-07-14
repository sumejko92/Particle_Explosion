#include "../include/Screen.h"
#include <iostream>

using namespace std;

Screen::Screen()
    : window_(NULL), renderer_(NULL), texture_(NULL), buffer_(NULL) {
  cout << "Window constructor called" << endl;
}
bool Screen::init() {}
bool Screen::processEvents() {}

Screen::~Screen() {}