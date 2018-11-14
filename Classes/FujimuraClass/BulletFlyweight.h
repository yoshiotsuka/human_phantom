#pragma once

#include "cocos2d.h"
#include <vector>

class Bullet;

class BulletFlyweight final {

public:

	static BulletFlyweight& GetInstance() {

		static BulletFlyweight instance;
		return instance;

	}

	virtual ~BulletFlyweight();

	Bullet* GetBulletInstance();
	void UsedBulletInstance(Bullet* bullet);

private:

	BulletFlyweight();

	cocos2d::SpriteBatchNode* enemyTexture_;

	std::vector<Bullet*> bullets_;

};