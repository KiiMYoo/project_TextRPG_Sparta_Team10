#include "Troll.h"
#include <cstdlib>
#include "../Character/Character.h"

Troll:Troll(const Character& character)
	:Monster(character.getLevel(),
		"Ʈ��",
<<<<<<< Updated upstream
		(rand() % (character.getLevel() * 11)) + (character.getLevel() * 20),
		(rand() % (character.getLevel() * 6)) + (character.getLevel() * 5),
		character.getLevel() * 15
=======
		(rand() % (level * 11)) + (level * 20),
		(rand() % (level * 6)) + (level * 5),
		level * 23
>>>>>>> Stashed changes
	) {}

void Troll::TakeDamage(int damage) {
	health -= damage;
	if (health < 0) {
		health = 0;
	}
}
