#include "Console.h"

Console::Console(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {}

int Console::newLineCount(std::string message) {
    int count = 0;
    for (char character : message) {
        if (character == '\n')
            count++;
    }
    return count;
}

void Console::addMessage(std::string message) {
    messageBuffer.push_back(message + '\n');
}

//This currently misses the first input
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

        for (int j = 1; j < newLineCount(messageBuffer[i]); j++)
            buffer.append("\n");
    }
    this->write({GREY}, buffer);
}