#include "StrangePotion.h"

StrangePotion::StrangePotion()
{
	name = "Strange Potion";
}

std::string StrangePotion::getName()
{
	return name;
}

void StrangePotion::use(Character* character)
{
	Item::use(character);

	std::cout << "수상한 물약 사용!" << std::endl;

	int probability = rand() % 100;
	if (probability < 40)
	{
		std::cout << "아무 일도 일어나지 않았습니다." << std::endl;
	}
	else if (probability < 70)
	{
		character->setAttack(character->getAttack() + 10);
		std::cout << "공격력이 10 상승했습니다." << std::endl;
	}
	else
	{
		character->setMaxHealth(character->geMaxtHealth() + 50);
		std::cout << "최대 체력이 50 상승했습니다." << std::endl;
	}
}
