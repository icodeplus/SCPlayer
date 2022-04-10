#include "scwindow.h"
#include "SDL.h"
#include <iostream>

SCWindow::SCWindow()
    : _nativeWindow(nullptr), _sdlWindow(), _title("SCPlayer"), _x(SDL_WINDOWPOS_UNDEFINED), _y(SDL_WINDOWPOS_UNDEFINED), _width(640), _height(480), _flags(SDL_WINDOW_OPENGL)
{

}

SCWindow::SCWindow(const void *nativeWindow) : _nativeWindow(nativeWindow), _sdlWindow()
{

}

SCWindow::SCWindow(const std::string& title, int x, int y, int width, int height, unsigned int flags)
    : _nativeWindow(nullptr), _sdlWindow(), _title(title), _width(width), _height(height), _flags(flags)
{
    _x = (x == DEFAULT_WINDOWPOS ? SDL_WINDOWPOS_UNDEFINED : x);
    _y = (y == DEFAULT_WINDOWPOS ? SDL_WINDOWPOS_UNDEFINED : y);
}

SCWindow::~SCWindow()
{
    if (_sdlWindow)
    {
        SDL_DestroyWindow(_sdlWindow.get());
    }
}

bool SCWindow::Init()
{
    if (_nativeWindow != nullptr)
    {
        _sdlWindow.reset(SDL_CreateWindowFrom(_nativeWindow));
    }
    else
    {
        _sdlWindow.reset(SDL_CreateWindow(_title.c_str(), _x, _y, _width, _height, _flags));
    }
    if (!_sdlWindow)
    {
        std::cerr << __FILE__ << ":" << __FUNCTION__ << " Fail to create window: " << SDL_GetError() << std::endl;
        return false;
    }
    return true;
}
