#include "PlayerBulletCollection.h"
#include "../OkuhamaClass/Bullet.h"
#include "BulletFlyweight.h"

PlayerBulletCollection::PlayerBulletCollection() {

}

PlayerBulletCollection::~PlayerBulletCollection() {



}

bool PlayerBulletCollection::Initialize(cocos2d::Scene* scene) {

	return true;

}

void PlayerBulletCollection::Update() {

	cocos2d::Director* director = cocos2d::Director::getInstance();
	float designScreenHeight = director->getOpenGLView()->getDesignResolutionSize().height;

	auto itr = this->bullets_.begin();

	while (itr != this->bullets_.end()) {

		cocos2d::Vec2 position = (*itr)->GetPosition();

		if (position.y >= designScreenHeight + 100.0f) {

			BulletFlyweight::GetInstance().UsedBulletInstance((*itr));

			itr = this->bullets_.erase(itr);

			continue;

		}

		itr++;

	}

}

void PlayerBulletCollection::CreateBullet(cocos2d::Scene* scene, cocos2d::Vec2 shotPos) {

	cocos2d::Director* director = cocos2d::Director::getInstance();
	float designScreenHeight = director->getOpenGLView()->getDesignResolutionSize().height;

	Bullet* bullet = BulletFlyweight::GetInstance().GetBulletInstance();

	bullet->Initialize(scene,shotPos);

	this->bullets_.push_back(bullet);

}


void PlayerBulletCollection::EraseBullet(Bullet* bullet) {

	auto itr = std::find(this->bullets_.begin(),this->bullets_.end(),bullet);

	if (itr == this->bullets_.end()) return;

	this->bullets_.erase(itr);
	BulletFlyweight::GetInstance().UsedBulletInstance(bullet);

}