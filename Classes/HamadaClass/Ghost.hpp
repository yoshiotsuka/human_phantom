#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class Player;

class Ghost
{
public:
	Ghost();
	~Ghost();
	bool Initialize(cocos2d::Scene* conectScene, Player* player);

	// �Z�b�^�[
	void SetPosition(Vec2 position);

	// �Q�b�^�[
	Vec2 GetPosition();
private:
	Sprite* ghost;
	Vec2 position;

	Player* player;
};