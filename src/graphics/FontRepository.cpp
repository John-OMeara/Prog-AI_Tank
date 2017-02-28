#include "graphics/FontRepository.h"

sf::Font FontRepository::s_menuFont;
sf::Font FontRepository::s_hudFont;

FontRepository::FontRepository()
{
}

void FontRepository::load()
{
   s_menuFont.loadFromFile(resourcePath() + "fonts/bernhc.ttf");
   s_hudFont.loadFromFile(resourcePath() + "fonts/munro_small.ttf");
}

const sf::Font &FontRepository::getMenuFont()
{
   return s_menuFont;
}

const sf::Font &FontRepository::getHudFont()
{
   return s_hudFont;
}
