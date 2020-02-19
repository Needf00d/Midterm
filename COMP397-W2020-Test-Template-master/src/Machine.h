#pragma once
#ifndef __MACHINE__
#define __MACHINE__

#include <vector>
#include "DisplayObject.h"
#include "Label.h"
#include "Dice.h"

class Machine : public DisplayObject
{
public:
	Machine();
	~Machine();
	void draw() override;
	void update() override;
	void clean() override;
	void spin();
	std::string getMessage();
	int one = 0;
	int two = 0;
	int three = 0;
	int four = 0;
	int five = 0;
	int six = 0;
	std::string dice = "";


private:
	Dice* left[2];
	Dice* right[2];
	int check_range(int value, int minValue, int maxValue);
	void resetWheel();
};
#endif#pragma once
