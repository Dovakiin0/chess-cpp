#include "help.h"
#include <SFML/Graphics.hpp>

Help::Help()
{
    background.loadFromFile("Textures/back.jpg");
    backSprite.setTexture(background);
    font.loadFromFile("Textures/times.ttf");

    title.setFont(font);
    title.setString("Chess Game");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(512 / 2, 100));

    helps[0].setFont(font);
    helps[0].setFillColor(sf::Color::Red);
    helps[0].setString("Start Gamesss");
    helps[0].setCharacterSize(30);
    helps[0].setPosition(sf::Vector2f(512 / 2, 250));

    helps[1].setFont(font);
    helps[1].setFillColor(sf::Color::White);
    helps[1].setString("Helpsss");
    helps[1].setCharacterSize(30);
    helps[1].setPosition(sf::Vector2f(512 / 2, 300));
      
	helps[2].setFont(font);
    helps[2].setFillColor(sf::Color::White);
    helps[2].setString("Exitssss");
    helps[2].setCharacterSize(30);
    helps[2].setPosition(sf::Vector2f(512 / 2, 350));
    selectedMenu = 0;
}

Help::~Help()
{
}

void Help::moveDown()
{
    if (selectHelp + 1 < MAX_MAIN_HELP || selectHelp + 2 < MAX_MAIN_HELP)
    {
        helps[selectHelp].setFillColor(sf::Color::White);
        selectedMenu++;
        helps[selectHelp].setFillColor(sf::Color::Red);
    }
}

void Help::moveUp()
{
    if (selectHelp - 1 >= 0 || selectHelp - 2 >= 0)
    {
        helps[selectHelp].setFillColor(sf::Color::Blue);
        selectedMenu--;
        helps[selectHelp].setFillColor(sf::Color::Red);
    }
}

int Help::getSelectedHelp()
{
    return selectHelp;
}

void Help::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backSprite);
    target.draw(title);
    for (int i = 0; i < 3; i++)
    {
        target.draw(helps[i]);
    }
}
