#include "Console.h"

Console::Console(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {}

int Console::newLineCount(std::string message) {

    int count = 1;
    int pos = 0;

    std::string temp = message;
    std::string token;
    while((pos = temp.find('\n')) != std::string::npos) { // Count occurrances between newlines
        count++;
        token = temp.substr(0,pos);
        int ct = floor((token.length()*9)/(this->getRightX()-this->getLeftX()-TEXT_PADDING_X));
        count += ceil((token.length()*9)/(this->getRightX()-this->getLeftX()-TEXT_PADDING_X));
        temp.erase(0,pos+1);
    }

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
//    int lines = 0;
//
//    std::vector<std::string> newBuffer;
//    for(int k = messageBuffer.size()-1; k > 0; k--) {
//        lines += newLineCount(messageBuffer[k]);
//        if(lines*lineHeight + this->getTopY()+TEXT_PADDING_Y > this->getBottomY() - TEXT_PADDING_Y) {
//            messageBuffer = {messageBuffer.begin(), messageBuffer.begin()+(messageBuffer.size()-k)};
//            break;
//        }
//    }

    int lc = 0; // How many lines have we currently filled
    for(int i = messageBuffer.size()-1; i > 0; i--) {

        lc += newLineCount(messageBuffer[i]); // How many lines have we used?

        int adcd = newLineCount("* You dealt 2 damage to the Octopus Cat!* You dealt 2 damage to the Octopus Cat!* You dealt 2 damage to the Octopus Cat!\n The Octopus Cat Dealt 1 to you! asdfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
        int addcd = newLineCount("* You dealt 2 damage to the Octopus Cat!*\n The Octopus Cat Dealt 1 to you!");
        this->write("* You dealt 2 damage to the Octopus Cat!* You dealt 2 damage to the Octopus Cat!* You dealt 2 damage to the Octopus Cat!\n The Octopus Cat Dealt 1 to you! asdfaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");

        //Will push the new text if the message given is multi-line
        for (int j = 1; j < newLineCount(messageBuffer[i]); j++) {
            buffer.append("\n");
            lc++;
        }



        if(i == messageBuffer.size()-1) {
            this->write(messageBuffer[i]);
            continue;
        }

        if(lc*lineHeight + this->getTopY() > this->getBottomY() - (TEXT_PADDING_Y)) {
            messageBuffer = {messageBuffer.begin()+i, messageBuffer.begin()+messageBuffer.size()};
            break;
        } else {
            buffer.append(messageBuffer[i]);
        }
    }

//    //This will loop through the message buffer in reverse
//    for (int i = messageBuffer.size()-1; i > 0; i--) {
//        //Ensures that the text does not run off the quad
//        if (-(i-messageBuffer.size()+1)*(9+TEXT_PADDING_Y)+this->getTopY() > (this->getBottomY()) - TEXT_PADDING_Y)
//            i = 0;
//
//        lc += newLineCount(messageBuffer[i]); // How many lines have we used?
////        if(lc*lineHeight + this->getTopY() >= this->getBottomY() - (TEXT_PADDING_Y)) {
//////            messageBuffer = {messageBuffer.begin(), messageBuffer.begin()+i};
//////            break;
////            buffer.append("\n\n\n");
////        }
//
//        //The most recent string will be printed first, otherwise add it to the buffer
//        if (i == messageBuffer.size()-1)
//            this->write(messageBuffer[i]);
//        else
//            buffer.append(messageBuffer[i]);
//
//        //Will push the new text if the message given is multi-line
//        for (int j = 1; j < newLineCount(messageBuffer[i]); j++)
//            buffer.append("\n");
//
//    }
    this->write({GREY}, buffer);
}