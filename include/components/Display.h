#pragma once

#include "entityx/Entity.h"
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Color.hpp>


struct Display : public entityx::Component<Display>
{
   Display();

   Display(const sf::IntRect& coord);

   Display(const sf::IntRect& coord, sf::Color color);

   sf::IntRect m_coord;

   sf::Color m_color;
};

