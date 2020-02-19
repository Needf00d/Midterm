#include "Dice.h"
#include "Game.h"

Dice::Dice(std::string id, int alpha, glm::vec2 position)
{
	m_id = id;
	m_alpha = alpha;
	m_position = position;

	TheTextureManager::Instance()->load("../Assets/textures/1.png", "1",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/2.png", "2",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/3.png", "3",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/4.png", "4",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/5.png", "5",
		TheGame::Instance()->getRenderer());

	TheTextureManager::Instance()->load("../Assets/textures/6.png", "6",
		TheGame::Instance()->getRenderer());


	glm::vec2 size = TheTextureManager::Instance()->getTextureSize(m_id);
	setWidth(size.x);
	setHeight(size.y);
	setPosition(m_position);

	setType(DICE);
}

Dice::~Dice()
{

}

void Dice::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw(m_id, xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, m_alpha, false);
}

void Dice::update()
{
}

void Dice::clean()
{
}

void Dice::setId(std::string id)
{
	m_id = id;
}
#pragma once
