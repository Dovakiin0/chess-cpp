#include "mainMenu.h"
#include <SFML/Graphics.hpp>

MainMenu::MainMenu()
{
    background.loadFromFile("Textures/back.jpg");
    backSprite.setTexture(background);
    font.loadFromFile("Textures/DK-Lemon-Yellow-Sun.ttf");

    title.setFont(font);
    title.setString("Chess Game");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(512 / 2, 50));

    arrowbg.loadFromFile("Textures/w_king.png");
    arrow.setTexture(arrowbg);
    arrow.setScale(sf::Vector2f(0.3f, 0.3f));
    arrow.setPosition(sf::Vector2f(200, arrpos));

    menu[0].setFont(font);
    menu[0].setFillColor(sf::Color::White);
    menu[selectedMenu].setStyle(sf::Text::Bold);
    menu[0].setString("Start Game");
    menu[0].setCharacterSize(30);
    menu[0].setPosition(sf::Vector2f(512 / 2, 200));

    menu[1].setFont(font);
    menu[1].setFillColor(sf::Color::White);
    menu[1].setString("Recent Match");
    menu[1].setCharacterSize(30);
    menu[1].setPosition(sf::Vector2f(512 / 2, 250));

    menu[2].setFont(font);
    menu[2].setFillColor(sf::Color::White);
    menu[2].setString("Help");
    menu[2].setCharacterSize(30);
    menu[2].setPosition(sf::Vector2f(512 / 2, 300));

    menu[3].setFont(font);
    menu[3].setFillColor(sf::Color::White);
    menu[3].setString("Exit");
    menu[3].setCharacterSize(30);
    menu[3].setPosition(sf::Vector2f(512 / 2, 350));
    selectedMenu = 0;
}

MainMenu::~MainMenu()
{
}

void MainMenu::moveDown()
{
    if (selectedMenu + 1 < MAX_MAIN_MENU || selectedMenu + 2 < MAX_MAIN_MENU)
    {
        menu[selectedMenu].setStyle(sf::Text::Regular);
        selectedMenu++;
        arrpos += 50;
        arrpos = std::min(340, arrpos);
        arrow.setPosition(sf::Vector2f(200, arrpos));
        menu[selectedMenu].setStyle(sf::Text::Bold);
    }
}

void MainMenu::moveUp()
{
    if (selectedMenu - 1 >= 0 || selectedMenu - 2 >= 0)
    {
        menu[selectedMenu].setStyle(sf::Text::Regular);
        selectedMenu--;
        arrpos -= 50;
        arrpos = std::max(190, arrpos);
        arrow.setPosition(sf::Vector2f(200, arrpos));
        menu[selectedMenu].setStyle(sf::Text::Bold);
    }
}

int MainMenu::getSelectedMenu()
{
    return selectedMenu;
}

void MainMenu::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backSprite);
    target.draw(title);
    target.draw(arrow);
    for (int i = 0; i < MAX_MAIN_MENU; i++)
    {
        target.draw(menu[i]);
    }
}
