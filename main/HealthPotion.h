#pragma once
#include "Item.h"
#include <string>

class HealthPotion :
    public Item
{
public:
	HealthPotion();

public:
	virtual std::string getName();
	virtual void use(Character* character);
};
