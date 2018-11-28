#include "Bullet.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Bullet::Bullet() {

	this->usingFlag_ = false;

}

Bullet::~Bullet() {

}

bool Bullet::Initialize(cocos2d::Scene* scene,Vec2 position)
{

	bullet = Sprite::create("HelloWorld.png");

	bullet->setPosition(position);

	if (bullet == nullptr)
	{

	}
	else
	{
		// add the sprite as a child to this layer
		scene->addChild(bullet, 0);

		bullet->runAction(MoveBy::create(1.0f, Point(0, 2500)));

	}

	this->bullet->setVisible(true);

	this->usingFlag_ = true;

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

Rect Bullet::GetRect() {

	return bullet->getBoundingBox();

}

void Bullet::Used() {

	ActionManager* manager = this->bullet->getActionManager();
	manager->removeAllActionsFromTarget(this->bullet);

	this->bullet->setVisible(false);

	this->usingFlag_ = false;

}