#include "GameManager.h"

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
void GameManager::Update()
{
	
}

#pragma region Progress
// ���� ���� �����ִ� ��
void GameManager::Progress()
{
	// ���� ���� ���� : Player ���
	bool bPlayerAlive = true;
	while (bPlayerAlive)
	{
		Update();

		//bPlayerAlive = �÷��̾�κ��� üũ;
	}

	// �������� ���� ����

}
#pragma endregion