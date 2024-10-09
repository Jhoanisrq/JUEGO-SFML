#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(500, 500), "Screen");

    sf::Vector2f velocity(0.0f, 0.0f);
    sf::Clock clock;
    float speed = 200.0f;

    sf::RectangleShape player;
    player.setSize(sf::Vector2f(30, 30));
    player.setFillColor(sf::Color::Blue);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            velocity.x = -speed;
        else if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            velocity.x = speed;
        else
            velocity.x = 0;


        float deltaTime = clock.restart().asSeconds();

        window.clear();
        player.move(velocity.x * deltaTime, velocity.y * deltaTime);
        window.draw(player);
        window.display();
    }
}

 