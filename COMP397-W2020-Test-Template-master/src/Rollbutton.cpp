#include "Rollbutton.h"
#include "Game.h"

Rollbutton::Rollbutton()
// call super constructor
	:Button(
		"../Assets/textures/rollButton.png",
		"startButton",
		START_BUTTON, glm::vec2(300.0f, 400.0f)), m_isClicked(false)
{

}

Rollbutton::~Rollbutton()
{
}

bool Rollbutton::getMouseOver()
{
	return m_mouseOver();
}

bool Rollbutton::ButtonClick()
{
	if (m_mouseOver() && m_mouseButtonClicked)
	{
		if (!m_isClicked)
		{
			std::cout << "Mouse Button Clicked!" << std::endl;
			m_isClicked = true;
		}
		return true;
	}
	else
	{
		m_isClicked = false;
	}

	return false;
}
