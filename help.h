#ifndef _HELP_H
#define _HELP_H
// #define MAX_MAIN_HELP 3
#define MAX_HELP_PAGE 12

#include <SFML/Graphics.hpp>

class Help : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text title;
    std::string helps[MAX_HELP_PAGE];
    sf::Texture background;
    sf::Text helpText;
    sf::Text footer;
    sf::Sprite backSprite;

    int currentPage = 0;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    Help();
    ~Help();

    void loadHelps();

    void nextPage();
    void prevPage();
};

#endif
