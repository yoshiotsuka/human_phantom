#pragma once

#include <vector>
#include "cocos2d.h"

class Enemy;

class EnemyCollection final{

public:

	static EnemyCollection& GetInstance() {

		static EnemyCollection instance;
		return instance;

	}

	~EnemyCollection();

	bool Initialize(cocos2d::Scene* scene);
	void Update();
	void CreateEnemy(cocos2d::Scene* scene);

	std::vector<Enemy*>& GetEnemys(){ return this->enemys_; }

private:

	EnemyCollection();

    cocos2d::SpriteBatchNode* enemyTexture_;

	std::vector<Enemy*> enemys_;

};