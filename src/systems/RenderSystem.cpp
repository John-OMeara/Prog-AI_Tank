#include "systems/RenderSystem.h"

using namespace entityx;

RenderSystem::RenderSystem(sf::RenderWindow& window,
                           const std::shared_ptr<sf::Texture>& spSSTexture)
: m_window(window)
, m_spSSTexture(spSSTexture)
, m_bgTexture()
, m_bgSprite()
, m_sprite()
{
   m_sprite.setTexture(*m_spSSTexture);  
   m_bgTexture.loadFromFile(resourcePath() + "images/Background.jpg");
   m_bgTexture.setRepeated(true);
   m_bgSprite.setTexture(m_bgTexture);
}

void RenderSystem::update(EntityManager &entities,
                          EventManager &events,
                          double dt)
{
   m_window.clear(sf::Color::Black);

   Background::Handle background;
   Position::Handle position;
   for (Entity entity : entities.entities_with_components(background, position))
   {
	  m_bgSprite.setTextureRect(sf::IntRect(0, position->m_position.y, ScreenSize::width(), ScreenSize::height()));
      m_window.draw(m_bgSprite);
   }   

   Display::Handle display;
   for (Entity entity : entities.entities_with_components(position, display))
   {
	   if (!isOutsideScreen(position->m_position, display->m_coord.width, display->m_coord.height))
	   {
		   m_sprite.setOrigin(display->m_coord.width / 2.0, display->m_coord.height / 2.0);		  
		     
		   if (entity.has_component<Turret>())
		   { 
			   m_sprite.setOrigin(display->m_coord.width / 3.0, display->m_coord.height / 2.0);
			   
				// Uncomment the block below to see debug draw for turret
				
				/*Volume::Handle turretVol = entity.component<Volume>();	
				sf::RectangleShape turretRect(sf::Vector2f(turretVol->m_box.getRect().width, turretVol->m_box.getRect().height));				
				turretRect.setOrigin(display->m_coord.width / 3.0, display->m_coord.height / 2.0);	
				turretRect.setPosition(position->m_position);
				turretRect.setOutlineColor(sf::Color(250, 150, 100));
				turretRect.setRotation(position->m_rotation);				
				m_window.draw(turretRect);	*/					
		   }					
		   m_sprite.setPosition(position->m_position);
		   m_sprite.setRotation(position->m_rotation);		 
		   m_sprite.setTextureRect(display->m_coord);
		   m_sprite.setColor(display->m_color);		 
		   m_window.draw(m_sprite);		   
	   }
	   else
	   {
		   entity.destroy();
	   }
   }

}

bool RenderSystem::isOutsideScreen(const sf::Vector2f& position,
	int width,
	int height)
{
	return    position.x + width / 2.0 < 0.0
		|| position.x - width / 2.0 > ScreenSize::width()
		|| position.y - height / 2.0 > ScreenSize::height();
}
