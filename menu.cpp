#include "Menu.h"

Menu::Menu() {
    // Cargar la fuente
    if (!font.loadFromFile("Chernobyl.otf")) {
        cout << "Error al cargar la fuente" << endl;
    }

    // Cargar la textura del fondo
    if (!backgroundTexture.loadFromFile("fond_menu.png")) {
        cout << "Error al cargar la textura del fondo" << endl;
    }
    background.setTexture(backgroundTexture);
    background.setScale(1000.0f / backgroundTexture.getSize().x, 650.0f / backgroundTexture.getSize().y); // Ajustar escala al tamaño de la ventana
    background.setPosition(0, 0); // Posición del fondo

    // Configuración del título del juego
    titleText.setFont(font);
    titleText.setString("Rebel Shooter"); // Título del juego
    titleText.setCharacterSize(70); // Tamaño del texto
    titleText.setFillColor(Color::White);
    titleText.setPosition(350, 50); // Posición en la ventana

    // Configuración del texto "Iniciar Juego"
    startText.setFont(font);
    startText.setString("Iniciar Juego");
    startText.setCharacterSize(50);
    startText.setFillColor(Color::White);
    startText.setPosition(420, 210); // Posición en la ventana

    // Configuración del recuadro para "Iniciar Juego"
    startBox.setSize(Vector2f(300, 70));
    startBox.setFillColor(Color(0, 0, 0, 150)); // Color de fondo semi-transparente
    startBox.setPosition(400, 200); // Posición del recuadro

    // Configuración del texto "Salir del juego"
    exitText.setFont(font);
    exitText.setString("Salir del juego");
    exitText.setCharacterSize(50);
    exitText.setFillColor(Color::White);
    exitText.setPosition(420, 310); // Posición en la ventana

    // Configuración del recuadro para "Salir del juego"
    exitBox.setSize(Vector2f(300, 70));
    exitBox.setFillColor(Color(0, 0, 0, 150)); // Color de fondo semi-transparente
    exitBox.setPosition(400, 300); // Posición del recuadro

    isStartSelected = true; // La opción inicial seleccionada
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
    target.draw(background); // Dibujar el fondo
    target.draw(titleText); // Dibujar el título del juego
    target.draw(startBox); // Dibujar el recuadro de "Iniciar Juego"
    target.draw(startText); // Dibujar el texto de "Iniciar Juego"
    target.draw(exitBox); // Dibujar el recuadro de "Salir del juego"
    target.draw(exitText); // Dibujar el texto de "Salir del juego"
}