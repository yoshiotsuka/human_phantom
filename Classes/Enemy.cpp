#include "Enemy.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


Enemy::Enemy() {

}

Enemy::~Enemy() {

}

bool Enemy::init(cocos2d::Scene* scene){

	//敵スプライト生成
	auto sprite_1 = Sprite::create("player1.JPG");
	auto sprite_2 = Sprite::create("player1.JPG");
	auto sprite_3 = Sprite::create("player1.JPG");
	auto sprite_4 = Sprite::create("player1.JPG");
	auto sprite_5 = Sprite::create("player1.JPG");
	auto sprite_6 = Sprite::create("player1.JPG");
	auto sprite_7 = Sprite::create("player1.JPG");
	auto sprite_8 = Sprite::create("player1.JPG");
	auto sprite_9 = Sprite::create("player1.JPG");
	auto sprite_10 = Sprite::create("player1.JPG");






	//敵1
	if (sprite_1 == nullptr)
	{
		
	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_1->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_1, 0);

		sprite_1->runAction(MoveBy::create(10.0f, Point(0, -2500)));
	}


	//敵2
	if (sprite_2 == nullptr)
	{

	}
	else
	{
		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_2->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_2, 0);

		sprite_2->runAction(MoveBy::create(20.0f, Point(0, -2500)));


	}	//敵3
	if (sprite_3 == nullptr)
	{

	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_3->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_3, 0);

		sprite_3->runAction(MoveBy::create(30.0f, Point(0, -2500)));


	}	//敵4
	if (sprite_4 == nullptr)
	{

	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_4->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_4, 0);

		sprite_4->runAction(MoveBy::create(40.0f, Point(0, -2500)));
	}	
	
	   //敵5
	if (sprite_5 == nullptr)
	{

	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_5->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_5, 0);

		sprite_5->runAction(MoveBy::create(50.0f, Point(0, -2500)));


	}	//敵6
	if (sprite_6 == nullptr)
	{

	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_6->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_6, 0);

		sprite_6->runAction(MoveBy::create(60.0f, Point(0, -2500)));

	}	//敵7
	if (sprite_7 == nullptr)
	{

	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_7->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_7, 0);

		sprite_7->runAction(MoveBy::create(70.0f, Point(0, -2500)));
	}

	//敵8
	if (sprite_8 == nullptr)
	{

	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_8->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_8, 0);

		sprite_8->runAction(MoveBy::create(80.0f, Point(0, -2500)));
	}	
	
	//敵9
	if (sprite_9 == nullptr)
	{

	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_9->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_9, 0);

		sprite_9->runAction(MoveBy::create(90.0f, Point(0, -2500)));
	}	
	
	//敵10
	if (sprite_10 == nullptr)
	{

	}
	else
	{

		//横位置ランダム
		// 指定した範囲内の乱数を取得
		int scoped_num = random(100, 1000);

		// position the sprite on the center of the screen
		sprite_10->setPosition(Vec2(scoped_num, 2100.0f));

		// add the sprite as a child to this layer
		scene->addChild(sprite_10, 0);

		sprite_10->runAction(MoveBy::create(100.0f, Point(0, -2500)));


	}



	return true;
}