#include "Bullet.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Bullet::Bullet() {

}

Bullet::~Bullet() {

}

bool Bullet::Initialize(cocos2d::Scene* scene)

{

	// ‹Ê
	auto bullet = Sprite::create("HelloWorld.png");


	if (bullet == nullptr)
	{

	}
	else
	{
		// add the sprite as a child to this layer
		scene->addChild(bullet, 0);

		bullet->runAction(MoveBy::create(10.0f, Point(0, 2500)));

	}


	return true;

}


Vec2 Bullet::GetPosition()
{

	return bullet->getPosition();

}

void Bullet::SetPostion(Vec2 postion)
{
	bullet->setPosition(postion);
}