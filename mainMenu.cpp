#include "mainMenu.h"
#include <SFML/Graphics.hpp>

MainMenu::MainMenu()
{
    background.loadFromFile("Textures/back.jpg");
    backSprite.setTexture(background);
    backSprite.setScale(sf::Vector2f(768, 512));
    font.loadFromFile("Textures/times.ttf");
    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[0].setString("Start Game");
    menu[0].setCharacterSize(50);
    menu[0].setPosition(sf::Vector2f(512 / 2, 768 / (MAX_MAIN_MENU + 2))); // 256, 256

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setCharacterSize(50);
    menu[1].setPosition(sf::Vector2f(512 / 2, 768 / (MAX_MAIN_MENU + 1))); // 256, 192
    selectedMenu = 0;
}

MainMenu::~MainMenu()
{
}

void MainMenu::moveUp()
{
    if (selectedMenu == 0)
    {
        menu[selectedMenu].setFillColor(sf::Color::White);
        selectedMenu++;
        if (selectedMenu > 1)
        {
            selectedMenu = 1;
        }
        menu[selectedMenu].setFillColor(sf::Color::Blue);
    }
}

void MainMenu::moveDown()
{
    if (selectedMenu == 1)
    {
        menu[selectedMenu].setFillColor(sf::Color::White);
        selectedMenu--;
        if (selectedMenu < 0)
        {
            selectedMenu = 0;
        }
        menu[selectedMenu].setFillColor(sf::Color::Blue);
    }
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backSprite);
    for (int i = 0; i < 2; i++)
    {
        target.draw(menu[i]);
    }
}