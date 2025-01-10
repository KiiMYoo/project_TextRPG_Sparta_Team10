#include "Goblin.h"
#include <string>
//���� ������ ĳ���� ������ ����ؼ� ���� ���� +- 1
// ü�� : ����x20 ~ ���� x 30
// ���ݷ� : ���� x 5 ~ ���� x 10
Goblin::Goblin(int level)
	:Monster(
		"Goblin",
		(rand() % (level * 20)) + (level * 30),  //  ü��
		(rand() % (level * 5)) + (level * 10),  //  ����
		level * 15 // ����ġ
	) {}

void Goblin::TakeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

