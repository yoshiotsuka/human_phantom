#include "PlayerMove.h"
#include "HamadaClass\Player.hpp"

PlayerMove::PlayerMove()
{
	
}


PlayerMove::~PlayerMove()
{
}

bool PlayerMove::Init(cocos2d::Scene* node, Player* player)
{
	//マウスイベント登録、初期化
	auto listener = EventListenerMouse::create();
	listener->onMouseMove = CC_CALLBACK_1(PlayerMove::onMouseMove, this);
	listener->onMouseDown = CC_CALLBACK_1(PlayerMove::onMouseDown, this);
	listener->onMouseUp = CC_CALLBACK_1(PlayerMove::onMouseUp, this);
	//タッチフラグ初期化
	touchflag = false;


	
	node->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, node);

	//プレイヤームーブクラスが持っているプレイヤーポインタに、プレイヤーを結びつける。
	this->player = player;

	//マウスイベント登録、初期化

	//タッチ処理を受け付ける
	auto listener_2 = EventListenerTouchOneByOne::create();

	//画面がタッチされた時に呼び出す関数を指定     
	listener_2->onTouchBegan = CC_CALLBACK_2(PlayerMove::onTouchBegan, this);

	//タッチしながら移動している時に呼び出される関数を指定
	listener_2->onTouchMoved = CC_CALLBACK_2(PlayerMove::onTouchMoved, this);

	//画面から指が離れた時に呼び出される関数を指定
	listener_2->onTouchEnded = CC_CALLBACK_2(PlayerMove::onTouchEnded, this);

	//タッチフラグ初期化
	touchflag = false;

	//タッチポイント
	touch_postion = player->GetPosition();

	//// タッチ処理を追加
	auto testinstance = Director::getInstance();
	auto testevent = testinstance->getEventDispatcher();


	//Director::getInstance()->getEventDispatcher();
	testevent->addEventListenerWithSceneGraphPriority(listener_2, node);

	// 移動量初期化
	prev_mouse_position.x = 0.0f;
	prev_mouse_position.y = 0.0f;

	return true;
}
void PlayerMove::Update()
{


	//	auto mouse = (EventMouse*)event;
	//->setPosition(Point(mouse->getCursorX(),
	//	mouse->getCursorY()));*/
}

// マウスを動かしたかを判定
void PlayerMove::onMouseMove(Event* event)
{
	auto player_mouse = (EventMouse*)event;
	// ボタンを押されているとき
	if (touchflag == true)
	{
		float x = player_mouse->getCursorX();
		float y = player_mouse->getCursorY();
		Vec2 nowMousePos = Vec2(x,y);
		Vec2 delta = nowMousePos - prev_mouse_position;

		player->SetPostion(delta + player->GetPosition());
		prev_mouse_position = nowMousePos;
		/*登録されているオブザーバーに通知する*/
		this->notifyObservers();
	}
}

// プレイヤーの座標を取得
Vec2 PlayerMove::GetPosition()
{
	return player->GetPosition();
}

// マウスのボタンを押したかを判定
void PlayerMove::onMouseDown(Event* event)
{
	/*マウスのボタンを押したらフラグをtrueに
	ボタン入力を有効にする*/ 
	touchflag = true;

	auto player_mouse = (EventMouse*)event;

	float x = player_mouse->getCursorX();
	float y = player_mouse->getCursorY();
	Vec2 nowMousePos = Vec2(x, y);
	prev_mouse_position = nowMousePos;

}

// マウスのボタンを離したかを判定
void PlayerMove::onMouseUp(Event* event)
{
	/*マウスのボタンを離したらfalseにし
	ボタン入力を無効にする*/ 
	touchflag = false;
}

bool PlayerMove::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	touchflag = true;
	auto player_touch = (EventMouse*)event;

	player->GetPosition();

	if (touchflag == true)
	{
		/*登録されているオブザーバーに通知する*/
		this->notifyObservers();
	}
	touchflag = true;
	return true;
}

void PlayerMove::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto player_touch = (EventMouse*)event;

	//player->SetPostion(Point(position, player_touch->getDelta()));
	if (touchflag == true)
	{
		//現在の2つのデルタを画面座標の位置に戻す
		Vec2 delta = touch->getDelta();

		// 現在の座標を取得する
		Vec2 player_position = player->GetPosition();

		// 現在座標　+ 移動量を新たな座標にする
		Vec2 new_player_position = player_position + delta;

		player->SetPostion(new_player_position);
	}
}

void PlayerMove::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	touchflag = false;
}

