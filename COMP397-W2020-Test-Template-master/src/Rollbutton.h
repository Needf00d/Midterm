#pragma once
#ifndef __ROLL_BUTTON__
#define __ROLL_BUTTON__

#include "Button.h"

class Rollbutton : public Button
{
public:
	Rollbutton();
	~Rollbutton();

	bool getMouseOver();
	bool ButtonClick() override;
private:
	bool m_isClicked;
};

#endif
