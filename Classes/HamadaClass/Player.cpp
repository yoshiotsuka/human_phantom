#include "Player.hpp"
#include "cocos2d.h"
#include "Classes\YoshiClass\PlayerMove.h"

Player::Player()
{

}

Player::~Player()
{

}

bool Player::Initialize(cocos2d::Scene* conectScene, PlayerMove* player_move)
{

	bullet = new Bullet();
	bullet->Initialize(conectScene);


	// プレイヤー
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
	player = Sprite::create("player.jpg");
	if (sprite == nullptr)
	{
		
	}
	else
	{
		//Player->setPosition(Vec2(visibleSize.width / 3 + origin.x, visibleSize.height / 2 + origin.y));
		/*Player->setPosition(ccp(0, 0));*/
	}

	Size size = Director::getInstance()->getWinSize();

	player->setPosition(Vec2(550, 300));
	
	this->player_move = player_move;
	this->player_move->Init(conectScene,this);

	
	conectScene->addChild(player, 0);
	return true;
}

Vec2 Player::GetPosition() 
{

	return player->getPosition();

}
void Player::SetPostion(Vec2 postion)
{
	player->setPosition(postion);
}