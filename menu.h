#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Menu {
private:
    Font font;
    Text titleText; // Título del juego
    Text startText;
    Text exitText;
    RectangleShape startBox;
    RectangleShape exitBox;
    Sprite background; // Sprite para el fondo
    Texture backgroundTexture; // Textura para el fondo
    bool isStartSelected;

public:
    Menu();

    void MoveUp();
    void MoveDown();
    bool isStartPressed() const;
    void draw(RenderTarget &target) const;
};

#endif // MENU_H