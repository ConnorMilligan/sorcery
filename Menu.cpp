#include "Menu.h"

Menu::Menu(color fill, point center, unsigned int width, unsigned int height) : Window(fill, center, width, height) {
    this->choices = {};
    this->selection = 0;
}

Menu::Menu(color fill, point center, unsigned int width, unsigned int height, std::vector<std::string> choices) : Window(fill, center, width, height) {
    this->choices = choices;
    this->selection = 0;
}

void Menu::choiceUp() {
    this->selection--;
}

void Menu::choiceDown() {
    this->selection++;
}

void Menu::draw() {
    Window::draw();
    std::string options, cursor;

    for (int i = 0; i < this->choices.size(); i++) {
        options.append("  " + this->choices[i] + '\n');
        selection == i ? cursor.append(">") : cursor.append("\n");
    }
    this->write(options);
    this->write(cursor);
    
}