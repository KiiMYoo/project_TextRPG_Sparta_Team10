#include "Goblin.h"
#include <string>
//���� ������ ĳ���� ������ ����ؼ� ���� ���� +- 1
// ü�� : ����x20 ~ ���� x 30
// ���ݷ� : ���� x 5 ~ ���� x 10
Goblin::Goblin(int level)
	:Monster(
		"���",
		(rand() % (level * 11)) + (level * 20),  //  ü��
		(rand() % (level * 6)) + (level * 5),  //  ����
		level * 15 // ����ġ
	) {}

void Goblin::TakeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}

