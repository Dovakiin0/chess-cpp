#ifndef _HELP_H
#define _HELP_H
#define MAX_MAIN_HELP 3

#include <SFML/Graphics.hpp>

class Help : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text title;
    sf::Text helps[MAX_MAIN_HELP];
    sf::Texture background;
    
    int selectHelp;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
	sf::Sprite backSprite;
    Help();
    ~Help();

    void moveUp();
    void moveDown();
    int getSelectedHelp();
};

#endif
