#ifndef _RECENT_H
#define _RECENT_H

#include <SFML/Graphics.hpp>
#include <vector>

class Recent : public sf::Drawable
{
private:
    sf::Font font;
    sf::Text title;
    sf::Text header;
    sf::Text records[5];
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
    std::vector<std::string> name_vec;
    std::vector<int> sec_vec;

public:
    void loadDetail();
    Recent();
    ~Recent();
};

#endif