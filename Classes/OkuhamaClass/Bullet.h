#pragma once
#include "cocos2d.h"
#include <windows.h>

using namespace cocos2d;


class Bullet
{
public:
	Bullet();
	~Bullet();

	bool Initialize(cocos2d::Scene* scene,Vec2 position = Vec2::ZERO);
	void SetPostion(Vec2 postion);

	Vec2 GetPosition();
	Rect GetRect();

	bool IsUsing() { return this->usingFlag_; }
	void Used();

private:

	Sprite* bullet;


	float bullet_x;
	float bullet_y;

	bool usingFlag_;

};

