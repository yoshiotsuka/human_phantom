#pragma once

#include <cocos2d.h>

class Bullet;

class PlayerBulletCollection final {

public:

	static PlayerBulletCollection& GetInstance() {

		static PlayerBulletCollection instance;
		return instance;

	}

	~PlayerBulletCollection();

	bool Initialize(cocos2d::Scene* scene);
	void Update();
	void CreateBullet(cocos2d::Scene* scene,cocos2d::Vec2 shotPos);
	void EraseBullet( Bullet* bullet );

	std::vector<Bullet*>& GetBullets() { return this->bullets_; }

private:

	PlayerBulletCollection();

	std::vector<Bullet*> bullets_;
};