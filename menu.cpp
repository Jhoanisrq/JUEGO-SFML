#include "Menu.h"

Menu::Menu() {
    // Cargar la fuente
    if (!font.loadFromFile("Chernobyl.otf")) {
        cout << "Error al cargar la fuente" << endl;
    }

    // Cargar la textura del fondo
    if (!fondo_menuTexture.loadFromFile("fond_menu.png")) {
        cout << "Error al cargar la textura del fondo" << endl;
    }
    fondo_menu.setTexture(fondo_menuTexture);
    fondo_menu.setScale(1010.0f / fondo_menuTexture.getSize().x, 650.0f / fondo_menuTexture.getSize().y);
    fondo_menu.setPosition(0, 0); 

    // Configuración del título del juego
    titleText.setFont(font);
    titleText.setString("Rebel Point"); 
    titleText.setCharacterSize(80); 
    titleText.setFillColor(Color::White);
    titleText.setPosition(240, 70); 

    // Configuración del texto "Iniciar Juego"
    startText.setFont(font);
    startText.setString("Iniciar Juego");
    startText.setCharacterSize(50);
    startText.setFillColor(Color::White);
    startText.setPosition(320, 210); 

    // Configuración del recuadro para "Iniciar Juego"
    startBox.setSize(Vector2f(360, 80));
    startBox.setFillColor(Color(0, 0, 0, 150)); 
    startBox.setPosition(300, 200); 

    // Configuración del texto "Salir del juego"
    exitText.setFont(font);
    exitText.setString("Salir del juego");
    exitText.setCharacterSize(50);
    exitText.setFillColor(Color::White);
    exitText.setPosition(320, 310); 

    // Configuración del recuadro para "Salir del juego"
    exitBox.setSize(Vector2f(420, 80));
    exitBox.setFillColor(Color(0, 0, 0, 150));
    exitBox.setPosition(300, 300); 

    isStartSelected = true;
}

void Menu::MoveUp() {
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

void Menu::MoveDown() {
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

bool Menu::isStartPressed() const {
    return isStartSelected;
}

void Menu::draw(RenderTarget &target) const {
    target.draw(fondo_menu);    
    target.draw(titleText);   
    target.draw(startBox);   
    target.draw(startText);   
    target.draw(exitBox);   
    target.draw(exitText); 
}