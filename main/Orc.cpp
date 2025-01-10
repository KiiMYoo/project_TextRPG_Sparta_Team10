#include "Orc.h"
#include <cstdlib>

Orc::Orc(int level)
	:Monster(
		"Orc", //�̸�
		(rand() % (level * 20)) + (level * 30), //ü��
		(rand() % (level * 5)) + (level * 10), //����
		level * 15 //����ġ
	) {}

void Orc::TakeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}