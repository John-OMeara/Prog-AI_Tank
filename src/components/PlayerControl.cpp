#include "components/PlayerControl.h"

PlayerControl::PlayerControl()
: m_left(sf::Keyboard::A)
, m_altLeft(sf::Keyboard::Left)
, m_right(sf::Keyboard::D)
, m_altRight(sf::Keyboard::Right)
, m_up(sf::Keyboard::W)
, m_altUp(sf::Keyboard::Up)
, m_down(sf::Keyboard::S)
, m_altDown(sf::Keyboard::Down)
, m_shoot(sf::Keyboard::Space)
, m_turretLeft(sf::Keyboard::Z)
, m_turretRight(sf::Keyboard::X)
, m_pause(sf::Keyboard::Escape)
{
}
