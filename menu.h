#include <bits/stdc++.h>
#include <SFML/Graphics.hpp>
#ifndef MENU_H
#define MENU_H
using namespace std;
using namespace sf;

class Menu {
private:
    Font font;
    Text startText;
    Text exitText;
    bool isStartSelected;

public:
    Menu() {
        if (!font.loadFromFile("Chernobyl.otf")) {
            cout << "Error al cargar la fuente" << endl;
        }

        startText.setFont(font);
        startText.setString("Iniciar Juego");
        startText.setCharacterSize(50);
        startText.setFillColor(Color::White);
        startText.setPosition(400, 200); 

        exitText.setFont(font);
        exitText.setString("Salir");
        exitText.setCharacterSize(50);
        exitText.setFillColor(Color::White);
        exitText.setPosition(400, 300); 

        isStartSelected = true;
    }

    void MoveUp() {
        if (isStartSelected) {
            startText.setFillColor(Color::White);
            exitText.setFillColor(Color::Red);
            isStartSelected = false;
        } else {
            startText.setFillColor(Color::Red);
            exitText.setFillColor(Color::White);
            isStartSelected = true;
        }
    }

    void MoveDown() {
        if (!isStartSelected) {
            startText.setFillColor(Color::White);
            exitText.setFillColor(Color::Red);
            isStartSelected = true;
        } else {
            startText.setFillColor(Color::Red);
            exitText.setFillColor(Color::White);
            isStartSelected = false;
        }
    }

    bool isStartPressed() {
        return isStartSelected;
    }

    void draw(RenderTarget &target) const {
        target.draw(startText);
        target.draw(exitText);
    }
};

#endif