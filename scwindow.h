#ifndef SCWINDOW_H
#define SCWINDOW_H
#include <memory>
#include <string>
#include "SDL.h"

#define DEFAULT_WINDOWPOS -1

class SCWindow
{ 
public:
    SCWindow();
    SCWindow(const void *nativeWindow);
    SCWindow(const std::string& title, int x = DEFAULT_WINDOWPOS, int y = DEFAULT_WINDOWPOS, int width = 640, int height = 480, unsigned int flags = 0);
    virtual ~SCWindow();

    bool Init();
    unsigned int GetWindowID() const;

protected:
    virtual int HandleEvent(SDL_Event *event);
    virtual int HandleWindowEvent(SDL_WindowEvent *event);
    virtual int HandleKeyboardEvent(SDL_KeyboardEvent *event);
    virtual int HandleMouseMotionEvent(SDL_MouseMotionEvent *event);
    virtual int HandleMouseButtonEvent(SDL_MouseButtonEvent *event);
    virtual int HandleMouseWheelEvent(SDL_MouseWheelEvent *event);

private:
    static int SDLCALL Envent_Filter(void *userdata, SDL_Event *event);

private:
    const void *_nativeWindow;
    std::shared_ptr<SDL_Window> _sdlWindow;
    std::string _title;
    int _x;
    int _y;
    int _width;
    int _height;
    unsigned int _flags;
};

#endif // SCWINDOW_H
