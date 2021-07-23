#include "help.h"
#include <SFML/Graphics.hpp>

Help::Help()

{
    background.loadFromFile("Textures/chess-playing-hand.jpg");
    backSprite.setTexture(background);
    backSprite.setColor(sf::Color(255, 255, 255, 10)); // half transparent

    font.loadFromFile("Textures/DK-Lemon-Yellow-Sun.ttf");

    title.setFont(font);
    title.setString("Tutorial !!!");
    title.setStyle(sf::Text::Bold | sf::Text::Underlined);
	title.setCharacterSize(40);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(512 / 2, 100));

    helps[0].setFont(font);
    helps[0].setFillColor(sf::Color::Green);
    helps[0].setString("Tap and hold anywhere on the piece to select it");
    helps[0].setStyle(sf::Text::Bold);
    helps[0].setCharacterSize(40);
    helps[0].setPosition(sf::Vector2f(20, 250));

    helps[1].setFont(font);
    helps[1].setFillColor(sf::Color::White);
    helps[1].setString("Drop it in the highlighted box to move it");
    helps[1].setStyle(sf::Text::Bold);
    helps[1].setCharacterSize(30);
    helps[1].setPosition(sf::Vector2f(20, 300));
      
	helps[2].setFont(font);
    helps[2].setFillColor(sf::Color::White);
    helps[2].setString("Exit");
    helps[2].setStyle(sf::Text::Bold);
    helps[2].setCharacterSize(30);
    helps[2].setPosition(sf::Vector2f(20, 350));
    selectHelp = 0;
}

Help::~Help()
{
}

void Help::moveDown()
{
    if (selectHelp + 1 < MAX_MAIN_HELP || selectHelp + 2 < MAX_MAIN_HELP)
    {
        helps[selectHelp].setFillColor(sf::Color::White);
        selectHelp++;
        helps[selectHelp].setFillColor(sf::Color::Green);
    }
}

void Help::moveUp()
{
    if (selectHelp - 1 >= 0 || selectHelp - 2 >= 0)
    {
        helps[selectHelp].setFillColor(sf::Color(255,155,0));
        selectHelp--;
        helps[selectHelp].setFillColor(sf::Color::Green);
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
