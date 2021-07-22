#ifndef _RECENT_H
#define _RECENT_H

#include <SFML/Graphics.hpp>
#include <vector>

class Recent : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text title;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

public:
    Recent();
    ~Recent();
};

#endif