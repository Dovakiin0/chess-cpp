#ifndef _MAINMENU_H
#define _MAINMENU_H
#define MAX_MAIN_MENU 4

#include <SFML/Graphics.hpp>

class MainMenu : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text title;
    sf::Text menu[MAX_MAIN_MENU];
    sf::Texture background;
    sf::Sprite backSprite;
    int selectedMenu;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    MainMenu();
    ~MainMenu();

    void moveUp();
    void moveDown();
    int getSelectedMenu();
};

#endif
