#include "Goblin.h"
#include <string>
#include "../Character/Character.h"

//���� ������ ĳ���� ������ ����ؼ� ���� ���� +- 1
// ü�� : ����x20 ~ ���� x 30
// ���ݷ� : ���� x 5 ~ ���� x 10
<<<<<<< Updated upstream
Goblin::Goblin(const Character& character)
	:Monster(character.getLevel(),
			"���",
			(rand() % (character.getLevel() * 11)) + (character.getLevel() * 20),	//  ü��
			(rand() % (character.getLevel() * 6)) + (character.getLevel() * 5),		//  ����
			character.getLevel() * 15)												// ����ġ
			{}
=======
Goblin::Goblin(int level)
	:Monster(
		"���",
		(rand() % (level * 11)) + (level * 20),  //  ü��
		(rand() % (level * 6)) + (level * 5),  //  ����
		level * 17 // ����ġ
	) {}
>>>>>>> Stashed changes

void Goblin::TakeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

