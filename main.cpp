#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    unsigned int screenResolutionX = 500, screenResolutionY = 500;
    sf::RenderWindow window(sf::VideoMode(screenResolutionX, screenResolutionY), "SFML works!");

    float radius1 = 100.0, radius2 = 50.0, radius3 = 25.0;

    // circle 1
    sf::CircleShape shape1(radius1);
    shape1.setFillColor(sf::Color::Blue);
    shape1.setPosition(250, 50);

    // circle 2
    sf::CircleShape shape2(radius2);
    shape2.setFillColor(sf::Color::Yellow);
    shape2.setPosition(100, 200);

    // circle 3
    sf::CircleShape shape3(radius3);
    shape3.setFillColor(sf::Color::Red);
    shape3.setPosition(100, 100);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonPressed)
            {
                // Check if the event is a left mouse button click
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    // Get the mouse click coordinates
                    int mouseX = event.mouseButton.x;
                    int mouseY = event.mouseButton.y;

                    // Do something with the mouse click coordinates
                    std::cout << "LEFT CLICK: (" << mouseX << ", " << mouseY << ")\n";
                }
            }
        }
        window.clear();
        window.draw(shape1);
        window.draw(shape2);
        window.draw(shape3);
        window.display();
    }

    return 0;
}