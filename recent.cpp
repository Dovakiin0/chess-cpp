#include "recent.h"
#include <SFML/Graphics.hpp>
#include <fstream>
#include <algorithm>
#include <iostream>

Recent::Recent()
{
    background.loadFromFile("Textures/recentbg.jpg");
    backSprite.setTexture(background);
    backSprite.setColor(sf::Color(255, 255, 255, 100));

    font.loadFromFile("Textures/DK-Lemon-Yellow-Sun.ttf");

    title.setFont(font);
    title.setString("Recent Matches");
    title.setCharacterSize(50);
    title.setFillColor(sf::Color::White);
    title.setPosition(sf::Vector2f(250, 10));

    header.setFont(font);
    header.setString("Player\t\tTime");
    header.setCharacterSize(35);
    header.setFillColor(sf::Color::White);
    header.setPosition(sf::Vector2f(270, 100));

    cleanUp();
}

Recent::~Recent()
{
}

void Recent::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(backSprite);
    target.draw(title);
    target.draw(header);
    for (int i = 0; i < records.size(); i++)
    {
        target.draw(records.at(i));
    }
}

void Recent::loadDetail()
{
    if (!loaded)
    {
        std::ifstream fp;
        std::string name;
        int second;
        fp.open("recent.dat");
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

        int pos = 190;

        if (name_vec.size() > 5)
            records.resize(5);
        else
            records.resize(name_vec.size());

        if (!name_vec.empty())
        {
            for (int i = 0; i < records.size(); i++)
            {
                records.at(i).setFont(font);
                records.at(i).setString(name_vec.at(i) + "\t\t\t\t\t" + std::to_string(sec_vec.at(i)) + " sec");
                records.at(i).setCharacterSize(20);
                records.at(i).setFillColor(sf::Color::White);
                records.at(i).setPosition(sf::Vector2f(270, pos));
                pos += 50;
            }
            loaded = true;
        }
    }
}

void Recent::cleanUp()
{
    records.clear();
    name_vec.clear();
    sec_vec.clear();
    loaded = false;
}
