#include "Machine.h"
#include "Game.h"

Machine::Machine()
{
	for (int i = 0; i < 2; i++)
	{
		float xPosition = 256.0f;
		if (i == 0)
		{
			xPosition = 100.0f;
		}
		else if (i == 1)
		{
			xPosition = 400.0f;
		}

		int randNum = rand() % 8;
		switch (randNum)
		{
		case 7:
			left[i] = new Dice("1", 128, glm::vec2(xPosition, 100.0));
			right[i] = new Dice("2", 255, glm::vec2(xPosition, 100.0));
			break;
		case 6:
			left[i] = new Dice("3", 128, glm::vec2(xPosition, 100.0));
			right[i] = new Dice("5", 255, glm::vec2(xPosition, 100.0));
			break;
		case 5:
			left[i] = new Dice("6", 128, glm::vec2(xPosition, 100.0));
			right[i] = new Dice("1", 255, glm::vec2(xPosition, 100.0));
			break;
		case 4:
			left[i] = new Dice("2", 128, glm::vec2(xPosition, 100.0));
			right[i] = new Dice("5", 255, glm::vec2(xPosition, 100.0));
			break;
		case 3:
			left[i] = new Dice("1", 128, glm::vec2(xPosition, 100.0));
			right[i] = new Dice("4", 255, glm::vec2(xPosition, 100.0));
			break;
		case 2:
			left[i] = new Dice("6", 128, glm::vec2(xPosition, 100.0));
			right[i] = new Dice("3", 255, glm::vec2(xPosition, 100.0));
			break;
		case 1:
			left[i] = new Dice("3", 128, glm::vec2(xPosition, 100.0));
			right[i] = new Dice("2", 255, glm::vec2(xPosition, 100.0));
			break;
		case 0:
			left[i] = new Dice("5", 128, glm::vec2(xPosition, 100.0));
			right[i] = new Dice("4", 255, glm::vec2(xPosition, 100.0));
			break;
		}
	}
}

Machine::~Machine()
{
}

void Machine::draw()
{
	int xComponent = getPosition().x;
	int yComponent = getPosition().y;

	TheTextureManager::Instance()->draw("Dice", xComponent, yComponent, TheGame::Instance()->getRenderer(), 0, 255, false);
	for (int i = 0; i < 2; i++)
	{
		left[i]->draw();
		right[i]->draw();
	}
}

void Machine::update()
{
}

void Machine::clean()
{
}

void Machine::spin()
{
	int outCome[2] = { 0, 0 };

	for (int spin = 0; spin < 2; spin++)
	{
		outCome[spin] = floor((rand() % 65));
		if (outCome[spin] == check_range(outCome[spin], 1, 27))
		{
			left[spin]->setId("1");
			right[spin]->setId("2");
			one++;
		}
		else if (check_range(outCome[spin], 28, 37))
		{
			left[spin]->setId("3");
			right[spin]->setId("5");
			two++;
		}
		else if (check_range(outCome[spin], 38, 46))
		{
			left[spin]->setId("6");
			right[spin]->setId("1");
			three++;
		}
		else if (check_range(outCome[spin], 47, 54))
		{
			left[spin]->setId("2");
			right[spin]->setId("5");
			four++;
		}
		else if (check_range(outCome[spin], 55, 59))
		{
			left[spin]->setId("1");
			right[spin]->setId("4");
			five++;
		}
		else if (check_range(outCome[spin], 60, 62))
		{
			left[spin]->setId("3");
			right[spin]->setId("6");
			six++;
		}
		else if (check_range(outCome[spin], 63, 64))
		{
			left[spin]->setId("3");
			right[spin]->setId("2");
			one++;
		}
		else if (check_range(outCome[spin], 65, 65))
		{
			left[spin]->setId("5");
			right[spin]->setId("4");
			one++;
		}
	}

}

std::string Machine::getMessage()
{
	return std::string();
}

int Machine::check_range(int value, int minValue, int maxValue)
{
	if (value >= minValue && value <= maxValue)
	{
		return value;
	}
	else
	{
		return !value;
	}
}

void Machine::resetWheel()
{
	one = 0;
	two = 0;
	three = 0;
	four = 0;
	five = 0;
	six = 0;
}
