/*
* Console that has persisting messages
*/

#ifndef GRAPHICS_CONSOLE_H
#define GRAPHICS_CONSOLE_H

#include "Window.h"
#include <vector>

class Console : public Window {
private:
    std::vector<std::string> messageBuffer;
public:
    Console(color fill, point center, unsigned int width, unsigned int height);

    void addMessage(std::string message);
    virtual void draw();
};


#endif