#pragma once
#ifndef __BACKGROUND__
#define __BACKGROUND__

#include "DisplayObject.h"
#include <SDL_hints.h>
/*
Author:seoyoung
*/
class Background : public DisplayObject
{
public:
	Background(std::string imagePath = "../Assets/textures/background.png",
		std::string buttonName = "background",
		GameObjectType type = START_BUTTON,
		glm::vec2 position = glm::vec2(300.0f, 200.0f), bool isCentered = true);

	virtual ~Background();

	void draw() override;
	void update() override;
	void clean() override;

private:
	Uint8 m_alpha;
	std::string m_name;
	bool m_isCentered;
	glm::vec2 m_mousePosition;
};

#endif 