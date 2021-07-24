#include <iostream>
#include <SFML/Graphics.hpp>
#include "chessGame.h"
#include "mainMenu.h"
#include "help.h"
#include "recent.h"

int main()
{
    MainMenu menu;
    Recent recent_page;
    ChessGame chess(sf::Color(0xf3bc7aff), sf::Color(0xae722bff));

    sf::RenderWindow window(sf::VideoMode(768, 512), "Chess Game", sf::Style::Titlebar | sf::Style::Close);
    window.setVerticalSyncEnabled(true);

    Help help;

    bool isHelp = false;
    bool isMenu = true;
    bool isGame = false;
    bool isRecentPage = false;
    // MainMenu menu;

    // appliaction starts here
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {

            if (event.type == sf::Event::Closed)
                window.close();

            // For Main Menu
            if (isMenu)
            {

                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        menu.moveUp();
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        menu.moveDown();
                    }
                    if (event.key.code == sf::Keyboard::Enter)
                    {
                        if (menu.getSelectedMenu() == 0)
                        {
                            window.clear();
                            isMenu = false;
                            isGame = true;
                        }

                        else if (menu.getSelectedMenu() == 2)
                        {
                            window.clear();
                            isHelp = true;
                            isMenu = false;
                        }
                        else if (menu.getSelectedMenu() == 1)
                        {
                            window.clear();
                            isMenu = false;
                            isRecentPage = true;
                        }
                        else
                        {
                            window.close();
                        }
                    }
                }
            }
            if (isRecentPage)
            {
                recent_page.loadDetail();
                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.clear();
                        isRecentPage = false;
                        isMenu = true;
                        recent_page.cleanUp();
                    }
                }
            }
            if (isHelp)
            {
                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.clear();
                        isMenu = true;
                        isHelp = false;
                    }
                    if (event.key.code == sf::Keyboard::Up)
                    {
                        help.moveUp();
                    }
                    if (event.key.code == sf::Keyboard::Down)
                    {
                        help.moveDown();
                    }
                }
            }

            // For GamePlay
            if (isGame)
            {
                if (event.type == sf::Event::KeyReleased)
                {
                    if (event.key.code == sf::Keyboard::Escape)
                    {
                        window.clear();
                        isGame = false;
                        isMenu = true;
                    }
                }
                if (event.type == sf::Event::MouseButtonPressed)
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        if ((0 <= event.mouseButton.x) && (event.mouseButton.x <= 512) && (0 <= event.mouseButton.y) && (event.mouseButton.y <= 512))
                        {
                            unsigned int buttonPos{(event.mouseButton.x / 64) + ((event.mouseButton.y / 64) * (8 * (512 / window.getSize().y)))};
                            if (!chess.getSelected())
                                chess.selectPiece(buttonPos);
                            else
                                chess.moveSelected(buttonPos);
                        }
                        else if ((517 <= event.mouseButton.x) && (event.mouseButton.x <= 763) && (5 <= event.mouseButton.y) && (event.mouseButton.y <= 45))
                        {
                            chess.restart();
                        }
                    }
                }
            }
        }
        if (isGame)
        {
            window.draw(chess);
        }
        if (isMenu)
        {
            window.draw(menu);
        }
        if (isRecentPage)
        {
            window.draw(recent_page);
        }
        if (isHelp)
        {
            window.draw(help);
        }
        window.display();
    }
}
