#pragma once
#ifndef __LEVEL_1_SCENE__
#define __LEVEL_1_SCENE__

#include "Scene.h"
#include "Rollbutton.h"
#include "Label.h"
#include "Machine.h"
#include "Dice.h"
#include "Background.h"
class Level1Scene : public Scene
{
public:
	Level1Scene();
	~Level1Scene();
	
	void draw() override;
	void update() override;
	void clean() override;
	void handleEvents() override;
	void start() override;

	// getters
	glm::vec2 getMousePosition();

private:
	// game objects
	Background* m_pBackground;
	Machine* m_pMachine;
	Rollbutton* m_pRollbutton;
	Dice* m_pDice;
	bool canSpin;

	// private data member
	glm::vec2 m_mousePosition;
	Label* m_pSlotLabel;
	
};

#endif /* defined (__LEVEL_1_SCENE__) */
