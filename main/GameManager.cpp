#include "GameManager.h"
#include "../Character/Character.h"
#include "FileReaderManager.h"
#include <vector>
#include "Monster.h"
#include "Wolf.h"
#include "Goblin.h"
#include "Orc.h"
#include "Troll.h"

GameManager* GameManager::instance = nullptr;

#pragma region Constructor
void GameManager::Log(const std::string& message)
{
	if (logFile.is_open()) {
		logFile << message << std::endl;
	}
	std::cout << message << std::endl;
}
#pragma endregion

/// <summary>
/// ���� ������ �ʱ�ȭ �ؾ��ϴ� �͵� �߰�
/// ex) �÷��̾� ĳ���� ����, ��...
/// </summary>
void GameManager::Init()
{
	// �÷��̾� �̸� �Է�
	std::string playerName = "";
	std::cout << "�÷��̾��� �̸��� �Է��ϼ��� : ";
	std::cin >> playerName;
	Character::getInstance(playerName);
	std::cout << playerName;	// debug

	// �ʹ� ���丮 ���
	FileReaderManager* FRM = FileReaderManager::GetInstance();
	FRM->OpenFile("../test.txt");
	FRM->CloseFile();

	// �÷��̾� ���� 2�� �����ϰ� ����
	Character::getInstance()->levelUp();
}

/// <summary>
/// ���� ����
/// 
/// �� �ϵ��� �߻��ؾ��ϴ� ��� ��
///	ex)
///		�÷��̾� �Է� (����? ��ų? ������? ����?)
///		�÷��̾��� �Է°��� ���� ��ȣ�ۿ�
///			case1 : �÷��̾ ���͸� �����ߴ�.
///			case2 : �÷��̾ ��ų������ -> MP �����ϴ�
///			case3 : �������� ����ߴ� -> �׿����� ȿ��
///			case4 : ���� NPC ������ -> ������ ����ϴµ� ���� �����ϴ�. �����ߴ�.
///		�÷��̾� or ���Ͱ� ����
///			case1 : �÷��̾� ���� -> ���� �� (�α׶���ũ)
///			case2 : ���Ͱ� �׾��� -> ����ġ, ������ ��� -> ������ or ��� ���Ƴ������ְ� or �̺�Ʈ�߻�
///		������ or ���� ������ ���� ���� 
/// 
/// </summary>

/// <summary>
/// 
/// ���� : ����, ���, ��ũ, Ʈ��
///	 
/// �÷��̾� ���� 1 ~ 4  : ����, ���
/// �÷��̾� ���� 5 ~ 8 : (����, ���) + ����, ��ũ
/// �÷��̾� ���� 9 ~ 10 : ��ũ, Ʈ��
/// 
/// </summary>
bool GameManager::Update()
{
	Character* player = Character::getInstance();

	// enter �Է� -> ����
	char bStore = 'n';	// true : ����
	std::cout << "���� ����? (Y/N) : ";
	std::cin >> bStore;

	// ������ �鸮�� �ȴٸ� -> �� ��°� ���� �����ؼ� ���� (�� : ����, ������ ����)
	if('y' == bStore || 'Y' == bStore)
	{
		// ������ ��� ���
		 
		// ������ ���� �� ����

		// ���� �Ϸ� �� ���� Ż��

	}

	// ���� ����
	Monster* genMonster = GenMonster(Character::getInstance()->getLevel());
	std::cout << "�߻��� " << genMonster->mGetName() << "�� ����߽��ϴ�.\n";

	// ����
	// ������ ü���� 0 �ʰ� �̰� �÷��̾ ������� ��
	while (genMonster->mGetHealth() > 0 && player->IsAlive())
	{
		// if(������ ������ �����ϰ� ������)
		// {
		//	30% Ȯ���� ���
		// }
		// 
		// if(ü���� 50% ���ϸ�)
		// {
		//	ü�� ������ ����Ѵ�.
		// }
		// else
		// {
		//	����
		genMonster->mTakeDamage(player->getAttack());
		// }

		// ���Ͱ� �÷��̾� ����
		player->TakeDamage(genMonster->mGetAttack());
	}

	// ���Ͱ� ���� ���
	if (genMonster->mGetHealth() <= 0)
	{
		int rndGold = 0;
		// ���Ͱ� ������? -> ����ġ/��� ȹ��
		player->setGold(player->getGold() + rndGold);
		// ����ġ �۾� ���� 
	}

	return player->IsAlive();
}

/// <summary>
/// 
/// container = [ ����, ���, ��ũ, Ʈ�� ]
///                0      1      2     3
/// 
/// �÷��̾� ���� 1 ~ 4  : ����, ���
/// �÷��̾� ���� 5 ~ 8 : (����, ���) + ����, ��ũ
/// �÷��̾� ���� 9 ~ 10 : ��ũ, Ʈ��
/// 
/// 
/// </summary>
Monster* GameManager::GenMonster(int playerLevel)
{
	Monster* result = nullptr;

	std::vector<Monster*> Monsters;
	Monsters.push_back(new Wolf(*Character::getInstance()));
	Monsters.push_back(new Goblin(*Character::getInstance()));
	Monsters.push_back(new Orc(*Character::getInstance()));
	Monsters.push_back(new Troll(*Character::getInstance()));

	if (playerLevel < 5)
	{
		// ����, ��� (0, 1)
		int idx = rand() % 2;	// 0 ~ 1
		result = Monsters[idx];
	}
	else if (playerLevel < 9)
	{
		// (����, ���) + ����, ��ũ (0,1,2)
		int idx = rand() % 3;	// 0 ~ 2
		result = Monsters[idx];
	}
	else
	{
		// ��ũ, Ʈ�� (2,3)
		int idx = rand() % 2 + 2;	// 0 ~ 1
		result = Monsters[idx];
	}

	return result;
}

#pragma region Progress
// ���� ���� �����ִ� ��
void GameManager::Progress()
{
	// ���� ���� ���� : Player ��� �Ǵ� �÷��̾��� ������ 10 �̸��϶�
	bool bPlayerAlive = true;
	while (bPlayerAlive || Character::getInstance()->getLevel() < 10)
	{
		bPlayerAlive = Update();
	}

	// �������� ���� ����

}
#pragma endregion