#include "Ghost.hpp"
#include "cocos2d.h"
#include "Classes\HamadaClass\Player.hpp"


Ghost::Ghost()
{

}

Ghost::~Ghost()
{

}

bool Ghost::Initialize(cocos2d::Scene* conectScene, Player* player)
{
	// ゴースト
	auto ghost_sprite = Sprite::create("unnamed.jpg");
	if (ghost_sprite == nullptr)
	{

	}
	else
	{
		conectScene->addChild(ghost_sprite, 0);
	}
	// ゴースト画像データ読み込み
	ghost = Sprite::create("player.JPG");
	if (ghost_sprite == nullptr)
	{

	}
	else
	{

	}
	// TODOプレイヤー追従
	Size size = Director::getInstance()->getWinSize();
	ghost->setPosition(Vec2(550, 100));
	conectScene->addChild(ghost, 0);
	/*ゴーストクラスが持っているプレイヤーポインタに、
	プレイヤーを結びつける*/ 
	this->player = player;
	return true;
}

// ゴーストの座標を取得
Vec2 Ghost::GetPosition()
{
	return position;
}

// ゴーストの座標設定
void Ghost::SetPosition(Vec2 position)
{
	this->position = position;
}