#pragma once

#include "cocos2d.h"
#include <vector>

class Enemy;

class EnemyFlyweight{

public:

	static EnemyFlyweight& GetInstance(){

		static EnemyFlyweight instance;
		return instance;

	}
	virtual ~EnemyFlyweight();

	Enemy* GetEnemyInstance();
	void UsedEnemyInstance(Enemy* enemy);

private:

	EnemyFlyweight();

	std::vector<Enemy*> enemys_;

};