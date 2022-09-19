//Demo class

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

#include "Tilemap.h"

#define WIN_X 1280;
#define WIN_Y 720;

int main()
{
    int winX = WIN_X;
    int winY = WIN_Y;

    sf::RenderWindow window(sf::VideoMode(winX, winY), "Tilemap Demo", sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    sf::Texture tileTexture;
    tileTexture.loadFromFile("Square.png");

    sf::Font font;
    font.loadFromFile("Roboto-Regular.ttf");

    sf::Text mouseText;
    std::string mouseTextString;
    mouseText.setFont(font);
    mouseText.setCharacterSize(15);

    //Creates the tilemap with dimensions 10x10
    Tilemap map(sf::Vector2f(10, 5), sf::Vector2f(winX, winY));
    std::vector<sf::Sprite> tiles;

    while (window.isOpen())
    {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        sf::Vector2i currentTile = map.getCurrentTile(mousePos);

        mouseTextString = "Tile: " + std::to_string(currentTile.x) + ", " + std::to_string(currentTile.y);
        mouseText.setString(mouseTextString);
        mouseText.setPosition(mousePos.x + 22, mousePos.y + 15);

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::MouseButtonReleased)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Sprite s;
                    s.setTexture(tileTexture);
                    s = map.createObjAtTile(mousePos, s, true);
                    tiles.push_back(s);
                }
            }
        }

        //Display content

        window.clear(sf::Color::Magenta);

        for (int i = 0; i < tiles.size(); i++)
        {
            window.draw(tiles[i]);
        }

        window.draw(mouseText);

        window.display();
    }
}