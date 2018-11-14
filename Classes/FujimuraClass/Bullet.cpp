#include "Bullet.h"

USING_NS_CC;


Bullet::Bullet() {

	this->sprite_ = nullptr;

}

Bullet::~Bullet() {

}

bool Bullet::init(cocos2d::Scene*     scene,
	cocos2d::Texture2D* texture,
	cocos2d::Vec2		 position,
	cocos2d::Action*    action) {

	//球スプライト生成

	if (this->sprite_ == nullptr) {

		sprite_ = Sprite::createWithTexture(texture);
		scene->addChild(sprite_);

	}

	sprite_->setPosition(position);

	if (action != nullptr) {

		sprite_->runAction(action);

	}

	this->usingFlag_ = true;

	return true;
}