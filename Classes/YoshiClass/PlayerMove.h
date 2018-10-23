#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "HamadaClass\Observer.hpp"

class Player;

/*プレイヤーの動きを管理するクラス
Subjectを継承したのは、移動したら通知するため*/
class PlayerMove : public Subject
{
public:
	PlayerMove();
	~PlayerMove();

	bool Init(cocos2d::Scene* scene , Player* player);
	
	Vec2 GetPosition();

private:

	void Update();

	void onMouseMove(cocos2d::Event* event); // マウス移動
	void onMouseDown(cocos2d::Event* event); // マウスボタンダウン
	void onMouseUp  (cocos2d::Event* event); // マウスボタンアップ

	bool touchflag;

	Player* player;
	Vec2 position;
};

