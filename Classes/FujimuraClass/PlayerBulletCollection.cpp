#include "PlayerBulletCollection.h"
#include "Bullet.h"
#include "BulletFlyweight.h"

PlayerBulletCollection::PlayerBulletCollection() {

	this->bulletTexture_ = nullptr;

}

PlayerBulletCollection::~PlayerBulletCollection() {



}

bool PlayerBulletCollection::Initialize(cocos2d::Scene* scene) {

	this->bulletTexture_ = cocos2d::SpriteBatchNode::create("HelloWorld.png");
	scene->addChild(this->bulletTexture_);

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
	cocos2d::Texture2D* texture = this->bulletTexture_->getTexture();

	cocos2d::Action* action = cocos2d::MoveBy::create(5.0f,cocos2d::Vec3(0.0f, designScreenHeight * 1.5f,0.0f));

	bullet->init(scene, texture, shotPos, action);

	this->bullets_.push_back(bullet);

}