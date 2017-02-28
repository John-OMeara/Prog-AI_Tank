#include "graphics/PauseMenuView.h"

using namespace entityx;

PauseMenuView::PauseMenuView()
: m_pauseText("Pause", FontRepository::getMenuFont(), 60)
, m_resumeText("Resume", FontRepository::getMenuFont(), 50)
, m_quitText("Quit", FontRepository::getMenuFont(), 50)
, m_selected(MenuChoices::RESUME)
{
   sf::FloatRect bounds(m_pauseText.getLocalBounds());
   m_pauseText.setOrigin(bounds.width/2.0, bounds.height/2.0);
   m_pauseText.setColor(sf::Color(0, 0, 0));
   
   bounds = sf::FloatRect (m_resumeText.getLocalBounds());
   m_resumeText.setOrigin(bounds.width/2.0, bounds.height/2.0);
      
   bounds = sf::FloatRect (m_quitText.getLocalBounds());
   m_quitText.setOrigin(bounds.width/2.0, bounds.height/2.0);
}

void PauseMenuView::update(EventManager &events,
                           double dt)
{
}

void PauseMenuView::draw(sf::RenderWindow& window)
{
   m_pauseText.setPosition(ScreenSize::width()*0.5,
                      ScreenSize::height()*0.2);
   
   m_resumeText.setPosition(ScreenSize::width()*0.5,
                      ScreenSize::height()*0.5);
   
   m_quitText.setPosition(ScreenSize::width()*0.5,
                      ScreenSize::height()*0.76);

   switch(m_selected){
   case MenuChoices::RESUME:
	  m_resumeText.setColor(sf::Color(255, 0, 0, 255));
	  m_quitText.setColor(sf::Color(255, 255, 255, 255));       
      break;
   case MenuChoices::QUIT_GAME:
	  m_resumeText.setColor(sf::Color(255, 255, 255, 255));
	  m_quitText.setColor(sf::Color(255, 0, 0, 255));
      break;
   }
   
   window.draw(m_pauseText);
   window.draw(m_resumeText);
   window.draw(m_quitText);
}


void PauseMenuView::onConfirm(entityx::EventManager& eventManager)
{
    switch(m_selected){
	case MenuChoices::RESUME:
		this->onCancel(eventManager);
        break;
	case MenuChoices::QUIT_GAME:
        eventManager.emit<EvQuitGame>();
        break;
    }
}

void PauseMenuView::onCancel(entityx::EventManager& eventManager){
    eventManager.emit<EvResumeGame>();
}

void PauseMenuView::onUp(entityx::EventManager& eventManager)
{
	if (m_selected == MenuChoices::QUIT_GAME)
	{
		m_selected = MenuChoices::RESUME;
	}
}

void PauseMenuView::onDown(entityx::EventManager& eventManager)
{
	if (m_selected == MenuChoices::RESUME)
	{
		m_selected = MenuChoices::QUIT_GAME;
	}
}