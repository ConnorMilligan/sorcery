#include "Console.h"

Console::Console(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {}

int Console::newLineCount(std::string message) {

    int count = 0;
    int pos = 0;

    std::string temp = message;
    std::string token;


    while((pos = temp.find('\n')) != std::string::npos) { // Count occurrances between newlines
        token = temp.substr(0,pos);
        count += floor((pos*9)/(width-TEXT_PADDING_X)) + 1;
        temp.erase(0,pos+1);
    }
    if(temp.find('\n') == std::string::npos) count += ceil((float)(temp.length()*9)/(float)(width-TEXT_PADDING_X));

//    for (char character : message) {
//        if (character == '\n')
//            count++;
//    }
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

    int lineHeight = 28;


    int lc = 0; // How many lines have we currently filled


    //This will loop through the message buffer in reverse
    for (int i = messageBuffer.size()-1; i > 0; i--) {

        //Ensures that the text does not run off the quad
        if (-(i-messageBuffer.size()+1)*(9+TEXT_PADDING_Y)+this->getTopY() > (this->getBottomY()) - TEXT_PADDING_Y)
            i = 0;

        lc += newLineCount(messageBuffer[i]);

        if(lc*lineHeight > height - TEXT_PADDING_Y) {
            messageBuffer = {messageBuffer.begin()+i, messageBuffer.begin()+messageBuffer.size()};
            break;
        }

        //The most recent string will be printed first, otherwise add it to the buffer
        if (i == messageBuffer.size()-1)
            this->write(messageBuffer[i]);
        else
            buffer.append(messageBuffer[i]);



        //Will push the new text if the message given is multi-line
        for (int j = 1; j < newLineCount(messageBuffer[i]); j++) {
            buffer.append("\n");
            lc++;
        }


    }
    this->write({GREY}, buffer);
}