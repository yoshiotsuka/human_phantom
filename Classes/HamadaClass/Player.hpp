#pragma once
#include "cocos2d.h"

using namespace cocos2d;

class PlayerMove;
class Bullet;

class Player
{
public:
	Player();
	~Player();

	bool Initialize(cocos2d::Scene* conectScene,PlayerMove* player_move);
	void SetPostion(Vec2 postion);

	Vec2 GetPosition();

private:

	PlayerMove* player_move;
	Sprite* player;
	float player_movement_x;
	float player_movement_y;
	Bullet* bullet;

};

