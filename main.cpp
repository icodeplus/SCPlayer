#include <iostream>
#include "SDL.h"
#include "scapplication.h"
#include "scwindow.h"

int main(int argc, char* argv[]) {
    SCApplication scApp;

    SCWindow scWindow;
    scWindow.Init();

    scApp.Run();

    return 0;
}
