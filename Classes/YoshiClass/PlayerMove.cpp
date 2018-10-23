#include "PlayerMove.h"
#include "HamadaClass\Player.hpp"

PlayerMove::PlayerMove()
{
	
}


PlayerMove::~PlayerMove()
{
}

bool PlayerMove::Init(cocos2d::Scene* scene , Player* player)
{
	//マウスイベント登録、初期化
	auto listener = EventListenerMouse::create();
	listener->onMouseMove = CC_CALLBACK_1(PlayerMove::onMouseMove, this);
	listener->onMouseDown = CC_CALLBACK_1(PlayerMove::onMouseDown, this);
	listener->onMouseUp = CC_CALLBACK_1(PlayerMove::onMouseUp, this);

	scene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, scene);

	//プレイヤームーブクラスが持っているプレイヤーポインタに、プレイヤーを結びつける。
	this->player = player;

	return true;
}
void PlayerMove::Update()
{


	//	auto mouse = (EventMouse*)event;
	//->setPosition(Point(mouse->getCursorX(),
	//	mouse->getCursorY()));*/
}
void PlayerMove::onMouseMove(Event* event)
{
	auto player_mouse = (EventMouse*)event;
	//player->GetPosition();

	player->SetPostion(Point(player_mouse->getCursorX(),player_mouse->getCursorY()));


}
void PlayerMove::onMouseDown(Event* event)
{

}
void PlayerMove::onMouseUp(Event* event)
{

}
