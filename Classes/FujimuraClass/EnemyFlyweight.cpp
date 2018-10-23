#include "EnemyFlyweight.h"
#include "../OkuhamaClass/Enemy.h"

EnemyFlyweight::EnemyFlyweight(){



}

EnemyFlyweight::~EnemyFlyweight(){

	if (this->enemys_.size() > 0){

		for (auto data : this->enemys_){

			delete data;

		}

	}

}

Enemy* EnemyFlyweight::GetEnemyInstance(){

	for (auto enemy : this->enemys_){

		if (enemy->IsUsing()) continue;

		return enemy;

	}

	Enemy* enemy = new Enemy();
	this->enemys_.push_back(enemy);

	return enemy;

}

void EnemyFlyweight::UsedEnemyInstance(Enemy* enemy){

	enemy->Used();

}