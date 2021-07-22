#include "recent.h"
#include <SFML/Graphics.hpp>

Recent::Recent()
{
    font.loadFromFile("Textures/times.ttf");

    title.setFont(font);
    title.setString("Recent Matches");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(512 / 2, 100));
}

Recent::~Recent() {}

void Recent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(title);
}