#include "Orc.h"
#include <cstdlib>

Orc::Orc(int level)
	:Monster(
		"��ũ", //�̸�
		(rand() % (level * 11)) + (level * 20), //ü��
		(rand() % (level * 6)) + (level * 5), //����
		level * 15 //����ġ
	) {}

void Orc::TakeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}