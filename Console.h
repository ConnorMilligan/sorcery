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
    int newLineCount(std::string message);
public:
    Console(color fill, point center, unsigned int width, unsigned int height);

    //Adds a message to the buffer
    void addMessage(std::string message);
    virtual void draw();
};


#endif