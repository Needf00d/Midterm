#pragma once
#ifndef __DICE__
#define __DICE__

#include "DisplayObject.h"

class Dice : public DisplayObject
{
public:
	Dice(std::string id, int alpha, glm::vec2 position);
	~Dice();
	void draw() override;
	void update() override;
	void clean() override;
	void setId(std::string id);

private:
	std::string m_id;
	int m_alpha = 255;
	glm::vec2 m_position;
};

#endif
