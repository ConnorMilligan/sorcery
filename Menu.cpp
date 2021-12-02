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
    this->selection-1 < 0 ? this->selection = this->choices.size()-1 : this->selection--;
}

void Menu::choiceDown() {
    this->selection+1 < this->choices.size() ? this->selection++ : this->selection = 0;
}

std::string Menu::getChoice() {
    return this->choices[selection];
}

void Menu::setChoices(std::vector<std::string> choices) {
    this->choices = choices;
}

int Menu::getSelection() {
    return this->selection;
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