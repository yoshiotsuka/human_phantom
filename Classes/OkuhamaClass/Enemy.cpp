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

	//敵スプライト生成

	if (this->sprite_ == nullptr){

		sprite_ = Sprite::createWithTexture(texture);
		scene->addChild(sprite_);

	}

	this->sprite_->setVisible(true);
	sprite_->setPosition(position);

	if (action != nullptr) {

		sprite_->runAction(action);

	}

	this->usingFlag_ = true;

	return true;
}

void Enemy::Used() {

	ActionManager* manager = this->sprite_->getActionManager();
	manager->removeAllActionsFromTarget(this->sprite_);

	this->sprite_->setVisible(false);

	this->usingFlag_ = false;

}