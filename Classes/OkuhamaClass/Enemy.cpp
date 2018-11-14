#include "Enemy.h"

USING_NS_CC;


Enemy::Enemy() {

	this->sprite_ = nullptr;

}

Enemy::~Enemy() {

}

bool Enemy::init(cocos2d::Scene*     scene, 
				 cocos2d::Texture2D* texture,
				 cocos2d::Vec2		 position,
				 cocos2d::Action*    action){

	//�G�X�v���C�g����

	if (this->sprite_ == nullptr){

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