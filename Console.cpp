#include "Console.h"

Console::Console(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {}

void Console::addMessage(std::string message) {
    messageBuffer.push_back(message + '\n');
}

void Console::draw() {
    Window::draw();
    std::string buffer = "\n";
    //|| i < i*(8 + TEXT_PADDING_Y) < this->height
    //(i-messageBuffer.size())*9+this->getTopY() < (this->getBottomY()) - TEXT_PADDING_Y ||
    
    for (int i = messageBuffer.size()-1; i > 0; i--) {
        if (-(i-messageBuffer.size())*9+this->getTopY() > (this->getBottomY()) - TEXT_PADDING_Y)
            i = 0;
        
        if (i == messageBuffer.size()-1)
            this->write(messageBuffer[i]);
        else
            buffer.append(messageBuffer[i]);
    }
    this->write({GREY}, buffer);
}