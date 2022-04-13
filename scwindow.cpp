#include "scwindow.h"
#include <iostream>

SCWindow::SCWindow()
    : _nativeWindow(nullptr)
    , _sdlWindow(), _title("SCPlayer")
    , _x(SDL_WINDOWPOS_UNDEFINED)
    , _y(SDL_WINDOWPOS_UNDEFINED)
    , _width(640)
    , _height(480)
    , _flags(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE)
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
    SDL_SetEventFilter(SCWindow::Envent_Filter, this);
    return true;
}

unsigned int SCWindow::GetWindowID() const
{
    if (_sdlWindow)
    {
        return SDL_GetWindowID(_sdlWindow.get());
    }
    return 0;
}

int SCWindow::HandleEvent(SDL_Event *event)
{
    switch (event->type)
    {
    case SDL_WINDOWEVENT:
        if (event->window.windowID != GetWindowID())
            break;
        return HandleWindowEvent(&event->window);
    case SDL_KEYDOWN:
    case SDL_KEYUP:
        if (event->key.windowID != GetWindowID())
            break;
        return HandleKeyboardEvent(&event->key);
    case SDL_MOUSEMOTION:
        if (event->motion.windowID != GetWindowID())
            break;
        return HandleMouseMotionEvent(&event->motion);
    case SDL_MOUSEBUTTONDOWN:
    case SDL_MOUSEBUTTONUP:
        if (event->button.windowID != GetWindowID())
            break;
        return HandleMouseButtonEvent(&event->button);
    case SDL_MOUSEWHEEL:
        if (event->wheel.windowID != GetWindowID())
            break;
        return HandleMouseWheelEvent(&event->wheel);
    }
    return 1;
}

int SCWindow::HandleWindowEvent(SDL_WindowEvent *event)
{
    if (event->event == SDL_WINDOWEVENT_SIZE_CHANGED)
    {

    }
    return 1;
}

int SCWindow::HandleKeyboardEvent(SDL_KeyboardEvent *event)
{
    return 1;
}

int SCWindow::HandleMouseMotionEvent(SDL_MouseMotionEvent *event)
{
    return 1;
}

int SCWindow::HandleMouseButtonEvent(SDL_MouseButtonEvent *event)
{
    return 1;
}

int SCWindow::HandleMouseWheelEvent(SDL_MouseWheelEvent *event)
{
    return 1;
}

int SDLCALL SCWindow::Envent_Filter(void *userdata, SDL_Event *event)
{
    auto pWindow = static_cast<SCWindow*>(userdata);
    return pWindow->HandleEvent(event);
}
