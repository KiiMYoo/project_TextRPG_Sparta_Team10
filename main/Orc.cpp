#include "Orc.h"
#include <cstdlib>
#include "../Character/Character.h"

Orc::Orc(const Character& character)
	:Monster(character.getLevel(),
		"��ũ", //�̸�
<<<<<<< Updated upstream
		(rand() % (character.getLevel() * 11)) + (character.getLevel() * 20), //ü��
		(rand() % (character.getLevel() * 6)) + (character.getLevel() * 5), //����
		character.getLevel() * 15 //����ġ
=======
		(rand() % (level * 11)) + (level * 20), //ü��
		(rand() % (level * 6)) + (level * 5), //����
		level * 20 //����ġ
>>>>>>> Stashed changes
	) {}

void Orc::TakeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}