#include "graphics/StartMenuView.h"

StartMenuView::StartMenuView(bool withFade)
: m_texture()
, m_logoSprite()
, m_timer(0.0)
, m_fadeInTimer(2000.0)
, m_showTextTimer(4000.0)
, m_alpha(0.0)
, m_drawText( !withFade )
, m_selected(MenuChoices::NEW_GAME)
{
   m_texture.loadFromFile(resourcePath() + "images/BattleTanks_Logo.png");

   sf::Vector2u size(m_texture.getSize());
   m_logoSprite.setTexture(m_texture);
   m_logoSprite.setOrigin(size.x/2.0, size.y/2.0);

   m_newGameText.setFont(FontRepository::getMenuFont());
   m_newGameText.setCharacterSize(50);
   m_newGameText.setString("New Game");

   sf::FloatRect bounds(m_newGameText.getLocalBounds());
   m_newGameText.setOrigin(bounds.width/2.0, bounds.height/2.0);

   m_quitText.setFont(FontRepository::getMenuFont());
   m_quitText.setCharacterSize(50);
   m_quitText.setString("Quit");

   bounds = m_quitText.getLocalBounds();
   m_quitText.setOrigin(bounds.width/2.0, bounds.height/2.0);

}

void StartMenuView::update(entityx::EventManager& events, double dt)
{
   m_timer += dt;

   if (!m_drawText && m_fadeInTimer > m_timer)
   {
      m_alpha = m_timer/m_fadeInTimer;
   }
   else
   {
      m_alpha = 1.0;


      if (m_showTextTimer > m_timer)
      {
         m_drawText = true;
      }
   }
}

void StartMenuView::draw(sf::RenderWindow& window)
{
   m_logoSprite.setPosition(ScreenSize::width()*0.2,
                            ScreenSize::height()*0.33);

   m_logoSprite.setColor(sf::Color(255, 255, 255, 255 * m_alpha));

   window.clear();
   window.draw(m_logoSprite);

   if (m_drawText)
   {
      float newGameTextY = ScreenSize::height()*0.5;

      m_newGameText.setPosition(ScreenSize::width()*0.5,
                                newGameTextY);

      m_quitText.setPosition(ScreenSize::width()*0.5,
								ScreenSize::height()*0.76);

      switch(m_selected){
	  case MenuChoices::NEW_GAME:
		   m_newGameText.setColor(sf::Color(255, 0, 0, 255));
		   m_quitText.setColor(sf::Color(255, 255, 255, 255));
          break;
	  case MenuChoices::QUIT_GAME:
		   m_newGameText.setColor(sf::Color(255, 255, 255, 255));
		   m_quitText.setColor(sf::Color(255, 0, 0, 255));
          break;
      }
      window.draw(m_newGameText);
      window.draw(m_quitText);
   }
}

void StartMenuView::onConfirm(entityx::EventManager& eventManager)
{
   if (m_drawText)
   {
      switch(m_selected){
	  case MenuChoices::NEW_GAME:
         eventManager.emit<EvStartGame>();
         break;
	  case MenuChoices::QUIT_GAME:
         eventManager.emit<EvQuitGame>();
         break;
      }
   }
   else
   {
      m_drawText = true;
   }
}

void StartMenuView::onUp(entityx::EventManager& eventManager)
{
   if (m_selected == MenuChoices::QUIT_GAME)
   {
	   m_selected = MenuChoices::NEW_GAME;
   }
}

void StartMenuView::onDown(entityx::EventManager& eventManager)
{

   if (m_selected == MenuChoices::NEW_GAME)
   {
	   m_selected = MenuChoices::QUIT_GAME;
   }
}
