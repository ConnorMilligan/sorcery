#include "Console.h"

Console::Console(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {}

void Console::addMessage(std::string message) {
    messageBuffer.push_back(message + '\n');
}

void Console::draw() {
    Window::draw();
    //Having the new line means there will be room for the grey text
    std::string buffer = "\n";
    
    //This will loop through the message buffer in reverse
    for (int i = messageBuffer.size()-1; i > 0; i--) {
        //Ensures that the text does not run off the quad
        if (-(i-messageBuffer.size()+1)*(9+TEXT_PADDING_Y)+this->getTopY() > (this->getBottomY()) - TEXT_PADDING_Y)
            i = 0;
        
        //The most recent string will be printed first, otherwise add it to the buffer
        if (i == messageBuffer.size()-1)
            this->write(messageBuffer[i]);
        else
            buffer.append(messageBuffer[i]);
    }
    this->write({GREY}, buffer);
}