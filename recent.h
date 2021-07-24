#ifndef _RECENT_H
#define _RECENT_H

#include <SFML/Graphics.hpp>
#include <vector>

class Recent : public sf::Drawable
{
private:
    bool loaded = false;
    sf::Font font;
    sf::Text title;
    sf::Sprite backSprite;
    sf::Texture background;
    sf::Text header;
    std::vector<sf::Text> records;
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    std::vector<std::string> name_vec;
    std::vector<int> sec_vec;

public:
    void loadDetail();
    void cleanUp();
    Recent();
    ~Recent();
};

#endif