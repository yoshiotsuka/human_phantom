#include "Player.hpp"
#include "cocos2d.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Initialize(cocos2d::Scene* conectScene)
{
	auto sprite = Sprite::create("unnamed.jpg");
	if (sprite == nullptr)
	{
		
	}
	else
	{
		// position the sprite on the center of the screen
		

		// add the sprite as a child to this layer
		conectScene->addChild(sprite, 0);
	}

	// プレイヤー画像データ読み込み
	auto Player = Sprite::create("player.jpg");
	if (sprite == nullptr)
	{
		
	}
	else
	{
		//Player->setPosition(Vec2(visibleSize.width / 3 + origin.x, visibleSize.height / 2 + origin.y));
		/*Player->setPosition(ccp(0, 0));*/
	}

	Size size = Director::getInstance()->getWinSize();

	Player->setPosition(Vec2(550, 100));

	//auto ooooooooooo = Player->convertToWorldSpace(Player->getPosition());


	conectScene->addChild(Player, 0);
	return true;
}