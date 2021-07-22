#include "recent.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>

Recent::Recent()
{
    font.loadFromFile("Textures/times.ttf");

    title.setFont(font);
    title.setString("Recent Matches");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(512 / 2.5, 10));

    header.setFont(font);
    header.setString("Player\t\tTime");
    header.setCharacterSize(35);
    header.setFillColor(sf::Color::White);
    header.setPosition(sf::Vector2f(512 / 2, 100));
}

Recent::~Recent() {}

void Recent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(title);
    target.draw(header);
    for (auto &rec : records)
    {
        target.draw(rec);
    }
}

void Recent::loadDetail()
{
    std::ifstream fp;
    std::string name;
    int second;
    fp.open("recent.dat", std::ios::app);
    while (!fp.eof())
    {
        fp >> name;
        name_vec.push_back(name);
        fp >> second;
        sec_vec.push_back(second);
    }
    name_vec.pop_back();
    sec_vec.pop_back();
    std::reverse(name_vec.begin(), name_vec.end());
    std::reverse(sec_vec.begin(), sec_vec.end());
    fp.close();

    int pos = 150;

    for (int i = 0; i < 5; i++)
    {
        records[i].setFont(font);
        records[i].setString(name_vec.at(i) + "\t\t" + std::to_string(sec_vec.at(i)) + " sec");
        records[i].setCharacterSize(30);
        records[i].setFillColor(sf::Color::White);
        records[i].setPosition(sf::Vector2f(512 / 2, pos));
        pos += 50;
    }
}
