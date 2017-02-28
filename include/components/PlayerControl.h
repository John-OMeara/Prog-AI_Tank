#pragma once

#include <SFML/Window/Keyboard.hpp>
#include "entityx/Entity.h"

struct PlayerControl : public entityx::Component<PlayerControl>
{
   PlayerControl();

   sf::Keyboard::Key m_left, m_altLeft;

   sf::Keyboard::Key m_right, m_altRight;

   sf::Keyboard::Key m_up, m_altUp;

   sf::Keyboard::Key m_down, m_altDown;

   sf::Keyboard::Key m_shoot;

   sf::Keyboard::Key m_turretLeft;

   sf::Keyboard::Key m_turretRight;

   sf::Keyboard::Key m_pause;
};

