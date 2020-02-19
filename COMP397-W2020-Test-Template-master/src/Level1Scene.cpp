#include "Level1Scene.h"
#include "Game.h"
#include <iostream>

Level1Scene::Level1Scene()
{
	start();
}

Level1Scene::~Level1Scene()
{
}

void Level1Scene::draw()
{
	m_pBackground->draw();
	m_pRollbutton-> draw();
	m_pMachine->draw();
	m_pSlotLabel->draw();

}

void Level1Scene::update()
{

	m_pRollbutton->setMousePosition(m_mousePosition);
	m_pRollbutton->ButtonClick();

}

void Level1Scene::clean()
{
}

void Level1Scene::handleEvents()
{
	int wheel = 0;

	SDL_Event event;
	while(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			TheGame::Instance()->quit();
			break;
		case SDL_MOUSEMOTION:
			m_mousePosition.x = event.motion.x;
			m_mousePosition.y = event.motion.y;
			break;

		case SDL_MOUSEBUTTONDOWN:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollbutton->setMouseButtonClicked(true);
				if (m_pRollbutton->getMouseOver())
				{
					m_pMachine->spin();
				}
				break;
			}
		
			break;
		case SDL_MOUSEBUTTONUP:
			switch (event.button.button)
			{
			case SDL_BUTTON_LEFT:
				m_pRollbutton->setMouseButtonClicked(false);
				break;
			}
			break;
		case SDL_MOUSEWHEEL:
			wheel = event.wheel.y;
			break;
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				TheGame::Instance()->quit();
				break;
			case SDLK_1:
				TheGame::Instance()->changeSceneState(SceneState::START_SCENE);
				break;
			case SDLK_2:
				TheGame::Instance()->changeSceneState(SceneState::END_SCENE);
				break;
			

				/************************************************************************/
			case SDLK_w:
				
				break;
			case SDLK_s:
				
				break;
			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		case SDL_KEYUP:
			switch (event.key.keysym.sym)
			{
			case SDLK_w:
				
				break;

			case SDLK_s:
				
				break;

			case SDLK_a:

				break;
			case SDLK_d:

				break;
			}
			
			break;
		default:
			break;
		}
	}
}

void Level1Scene::start()
{

	SDL_Color green = { 0, 255, 50, 255 };
	SDL_Color blue = { 0, 50, 255, 255 };
	SDL_Color white = { 255, 255, 255, 255 };



	m_pMachine = new Machine();
	m_pMachine->setParent(this);
	addChild(m_pMachine);

	m_pRollbutton = new Rollbutton();
	m_pRollbutton->setParent(this);
	addChild(m_pRollbutton);
	m_pRollbutton->setMouseButtonClicked(false);

	m_pSlotLabel = new Label(m_pMachine->dice, "Consolas", 80, green, glm::vec2(500.0f, 360.0f));
	m_pSlotLabel->setParent(this);
	addChild(m_pSlotLabel);

	m_pBackground = new Background();
}

glm::vec2 Level1Scene::getMousePosition()
{
	return m_mousePosition;
}

