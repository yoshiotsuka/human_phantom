#pragma once
#include "cocos2d.h"
#include <windows.h>

using namespace cocos2d;



class Bullet
{
public:
	Bullet();
	~Bullet();

	bool Initialize(cocos2d::Scene* scene);
	void SetPostion(Vec2 postion);

	Vec2 GetPosition();

private:

	Sprite* bullet;


	float bullet_x;
	float bullet_y;

};

