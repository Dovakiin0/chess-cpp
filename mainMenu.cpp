#include "mainMenu.h"
#include <SFML/Graphics.hpp>

MainMenu::MainMenu()
{
    background.loadFromFile("Textures/back.jpg");
    backSprite.setTexture(background);
    font.loadFromFile("Textures/times.ttf");

    title.setFont(font);
    title.setString("Chess Game");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(512 / 2, 0));

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::Blue);
    menu[0].setString("Start Game");
    menu[0].setCharacterSize(30);
    menu[0].setPosition(sf::Vector2f(512 / 2, 768 / (MAX_MAIN_MENU + 2))); // 256, 192

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Exit");
    menu[1].setCharacterSize(30);
    menu[1].setPosition(sf::Vector2f(512 / 2, 768 / (MAX_MAIN_MENU + 1))); // 256, 256
    selectedMenu = 0;
}

MainMenu::~MainMenu()
{
}

void MainMenu::moveDown()
{
    if (selectedMenu + 1 < MAX_MAIN_MENU)
    {
        menu[selectedMenu].setFillColor(sf::Color::White);
        selectedMenu++;
        menu[selectedMenu].setFillColor(sf::Color::Blue);
    }
}

void MainMenu::moveUp()
{
    if (selectedMenu - 1 >= 0)
    {
        menu[selectedMenu].setFillColor(sf::Color::White);
        selectedMenu--;
        menu[selectedMenu].setFillColor(sf::Color::Blue);
    }
}

int MainMenu::getSelectedMenu()
{
    return selectedMenu;
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    // target.draw(backSprite);
    target.draw(title);
    for (int i = 0; i < 2; i++)
    {
        target.draw(menu[i]);
    }
}