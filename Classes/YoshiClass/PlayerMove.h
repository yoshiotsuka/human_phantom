#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"

class Player;

class PlayerMove
{
public:
	PlayerMove();
	~PlayerMove();

	bool Init(cocos2d::Scene* scene , Player* player);

private:

	void Update();

	void onMouseMove(cocos2d::Event* event); // マウス移動
	void onMouseDown(cocos2d::Event* event); // マウスボタンダウン
	void onMouseUp  (cocos2d::Event* event); // マウスボタンアップ

	bool touchflag;

	Player* player;

};

