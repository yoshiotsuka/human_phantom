#pragma once

#include <vector>
#include "cocos2d.h"

class Enemy;

class EnemyCollection{

public:

	EnemyCollection();
	virtual ~EnemyCollection();

	bool Initialize(cocos2d::Scene* scene);
	void Update();
	void CreateEnemy(cocos2d::Scene* scene);

	std::vector<Enemy*>& GetEnemys(){ return this->enemys_; }

private:


	cocos2d::SpriteBatchNode* enemyTexture_;
	cocos2d::Action* enemyAction_;

	std::vector<Enemy*> enemys_;

};