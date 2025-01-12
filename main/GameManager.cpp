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
/// 게임 시작전 초기화 해야하는 것들 추가
/// ex) 플레이어 캐릭터 생성, 등...
/// </summary>
void GameManager::Init()
{
	// 플레이어 이름 입력
	std::string playerName = "";
	std::cout << "플레이어의 이름을 입력하세요 : ";
	std::cin >> playerName;
	Character::getInstance(playerName);
	std::cout << playerName;	// debug

	// 초반 스토리 출력
	FileReaderManager* FRM = FileReaderManager::GetInstance();
	FRM->OpenFile("../test.txt");
	FRM->CloseFile();

	// 플레이어 레벨 2로 설정하고 시작
	Character::getInstance()->levelUp();
}

/// <summary>
/// 게임 로직
/// 
/// 한 턴동안 발생해야하는 모든 것
///	ex)
///		플레이어 입력 (공격? 스킬? 아이템? 상점?)
///		플레이어의 입력값에 따른 상호작용
///			case1 : 플레이어가 몬스터를 공격했다.
///			case2 : 플레이어가 스킬을쓴다 -> MP 부족하다
///			case3 : 아이템을 사용했다 -> 그에따른 효과
///			case4 : 상점 NPC 만났다 -> 아이템 사야하는데 돈이 부족하다. 구매했다.
///		플레이어 or 몬스터가 죽음
///			case1 : 플레이어 죽음 -> 게임 끝 (로그라이크)
///			case2 : 몬스터가 죽었다 -> 경험치, 아이템 드랍 -> 레벨업 or 장비를 갈아낄수도있고 or 이벤트발생
///		목적지 or 다음 진행을 위한 선택 
/// 
/// </summary>

/// <summary>
/// 
/// 몬스터 : 늑대, 고블린, 오크, 트롤
///	 
/// 플레이어 레벨 1 ~ 4  : 늑대, 고블린
/// 플레이어 레벨 5 ~ 8 : (늑대, 고블린) + 강한, 오크
/// 플레이어 레벨 9 ~ 10 : 오크, 트롤
/// 
/// </summary>
bool GameManager::Update()
{
	Character* player = Character::getInstance();

	// enter 입력 -> 한턴
	char bStore = 'n';	// true : 상점
	std::cout << "상점 가실? (Y/N) : ";
	std::cin >> bStore;

	// 상점을 들리게 된다면 -> 템 사는거 내가 선택해서 구매 (템 : 물약, 수상한 물약)
	if('y' == bStore || 'Y' == bStore)
	{
		// 아이템 목록 출력
		 
		// 아이템 선택 및 구매

		// 구매 완료 후 상점 탈출

	}

	// 몬스터 생성
	Monster* genMonster = GenMonster(Character::getInstance()->getLevel());
	std::cout << "야생의 " << genMonster->mGetName() << "이 출몰했습니다.\n";

	// 전투
	// 몬스터의 체력이 0 초과 이고 플레이어가 살아있을 때
	while (genMonster->mGetHealth() > 0 && player->IsAlive())
	{
		// if(수상한 물약을 소지하고 있으면)
		// {
		//	30% 확률로 사용
		// }
		// 
		// if(체력이 50% 이하면)
		// {
		//	체력 물약을 사용한다.
		// }
		// else
		// {
		//	공격
		genMonster->mTakeDamage(player->getAttack());
		// }

		// 몬스터가 플레이어 공격
		player->TakeDamage(genMonster->mGetAttack());
	}

	// 몬스터가 죽은 경우
	if (genMonster->mGetHealth() <= 0)
	{
		int rndGold = 0;
		// 몬스터가 죽으면? -> 경험치/골드 획득
		player->setGold(player->getGold() + rndGold);
		// 경험치 작업 ㄱㄱ 
	}

	return player->IsAlive();
}

/// <summary>
/// 
/// container = [ 늑대, 고블린, 오크, 트롤 ]
///                0      1      2     3
/// 
/// 플레이어 레벨 1 ~ 4  : 늑대, 고블린
/// 플레이어 레벨 5 ~ 8 : (늑대, 고블린) + 강한, 오크
/// 플레이어 레벨 9 ~ 10 : 오크, 트롤
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
		// 늑대, 고블린 (0, 1)
		int idx = rand() % 2;	// 0 ~ 1
		result = Monsters[idx];
	}
	else if (playerLevel < 9)
	{
		// (늑대, 고블린) + 강한, 오크 (0,1,2)
		int idx = rand() % 3;	// 0 ~ 2
		result = Monsters[idx];
	}
	else
	{
		// 오크, 트롤 (2,3)
		int idx = rand() % 2 + 2;	// 0 ~ 1
		result = Monsters[idx];
	}

	return result;
}

#pragma region Progress
// 게임 로직 돌려주는 곳
void GameManager::Progress()
{
	// 게임 종료 조건 : Player 사망 또는 플레이어의 레벨이 10 미만일때
	bool bPlayerAlive = true;
	while (bPlayerAlive || Character::getInstance()->getLevel() < 10)
	{
		bPlayerAlive = Update();
	}

	// 게임종료 로직 수행

}
#pragma endregion