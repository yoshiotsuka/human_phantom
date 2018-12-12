#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "HamadaClass\Observer.hpp"
USING_NS_CC;

class Player;

/*プレイヤーの動きを管理するクラス
Subjectを継承したのは、移動したら通知するため*/
class PlayerMove : public Subject
{
public:
	PlayerMove();
	~PlayerMove();

	bool Init(cocos2d::Scene* node , Player* player);
	//void Update();

	////タッチ開始
	bool  onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	//タッチ中
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	//タッチ終了
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	
	Vec2 GetPosition();

private:

	void Update();

	void onMouseMove(cocos2d::Event* event); // マウス移動
	void onMouseDown(cocos2d::Event* event); // マウスボタンダウン
	void onMouseUp  (cocos2d::Event* event); // マウスボタンアップ

	bool touchflag;

	Player* player;
	Vec2 position;

	Vec2 prev_mouse_position;

	//タッチポジション
	Vec2 touch_postion;
};

