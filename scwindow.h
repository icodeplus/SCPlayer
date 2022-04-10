#ifndef SCWINDOW_H
#define SCWINDOW_H
#include <memory>
#include <string>

struct SDL_Window;

#define DEFAULT_WINDOWPOS -1

class SCWindow
{ 
public:
    SCWindow();
    SCWindow(const void *nativeWindow);
    SCWindow(const std::string& title, int x = DEFAULT_WINDOWPOS, int y = DEFAULT_WINDOWPOS, int width = 640, int height = 480, unsigned int flags = 0);
    ~SCWindow();

    bool Init();


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
