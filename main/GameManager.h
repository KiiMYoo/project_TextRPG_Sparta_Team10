#pragma once
#include <iostream>
#include <fstream>
#include <filesystem>

class GameManager
{
private:
	static GameManager* instance;

	std::ofstream logFile;

	GameManager()
	{
		std::cout << "[ Create GameManager ]" << std::endl;

		logFile.open("../log.txt", std::ios::app); // �α� ���� ���� (append ���)
		if (!logFile.is_open()) {
			throw std::runtime_error("[ Unable to open log file. ]");
		}
		else
		{
			std::cout << "[ Set Log File ]" << std::endl;
		}
	}

	~GameManager() 
	{
		if (logFile.is_open()) {
			logFile.close();
			std::cout << "[ Close Log File ]" << std::endl;
		}
	}

	GameManager(const GameManager&) = delete;
	GameManager& operator=(const GameManager&) = delete;

public:
	static GameManager* GetInstance() 
	{
		if (nullptr == instance)
		{
			instance = new GameManager();
		}
		return instance;
	}

	static void DestroyInstance()
	{
		if (nullptr != instance)
		{
			delete instance;
			instance = nullptr;
			std::cout << "[ Delete GameManager ]" << std::endl;
		}
	}

	void Log(const std::string& message);	// Log ��� �� ���
	void Init();							// �ʱ�ȭ
	void Progress();						// ���� ���� �� ����
	void Update();
};

GameManager* GameManager::instance = nullptr;
