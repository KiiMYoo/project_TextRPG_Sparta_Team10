#include "Orc.h"
#include <cstdlib>
#include "../Character/Character.h"

Orc::Orc(const Character& character)
	:Monster(character.getLevel(),
		"��ũ", //�̸�
		(rand() % (character.getLevel() * 11)) + (character.getLevel() * 20), //ü��
		(rand() % (character.getLevel() * 6)) + (character.getLevel() * 5), //����
		character.getLevel() * 20 //����ġ
	) {}

void Orc::mTakeDamage(int damage)
{
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}