#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Menu {
private:
    Font font;
    Text titleText; 
    Text startText;
    Text exitText;
    RectangleShape startBox;
    RectangleShape exitBox;
    Sprite fondo_menu; 
    Texture fondo_menuTexture; 
    bool isStartSelected;

public:
    Menu();

    void MoveUp();
    void MoveDown();
    bool isStartPressed() const;
    void draw(RenderTarget &target) const;
};

#endif