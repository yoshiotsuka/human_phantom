#include "EnemyCollection.h"
#include "../OkuhamaClass/Enemy.h"
#include "EnemyFlyweight.h"

EnemyCollection::EnemyCollection(){

	this->enemyTexture_ = nullptr;

}

EnemyCollection::~EnemyCollection(){



}

bool EnemyCollection::Initialize(cocos2d::Scene* scene){

	this->enemyTexture_ = cocos2d::SpriteBatchNode::create("player.JPG");

	scene->addChild(this->enemyTexture_);

	return true;

}

void EnemyCollection::Update(){

	auto itr = this->enemys_.begin();

	while (itr != this->enemys_.end()){

		cocos2d::Vec2 position = (*itr)->GetPosition();

		if (position.y <= -150.0f){

			EnemyFlyweight::GetInstance().UsedEnemyInstance((*itr));

			itr = this->enemys_.erase(itr);

			continue;

		}

		itr++;

	}

}

void EnemyCollection::CreateEnemy(cocos2d::Scene* scene){

	if (this->enemyTexture_ == nullptr) return;

	Enemy* enemy = EnemyFlyweight::GetInstance().GetEnemyInstance();
	cocos2d::Texture2D* texture = this->enemyTexture_->getTexture();

	cocos2d::RandomHelper random;
	float x = random.random_real(0.0f,1000.0f);

	cocos2d::Action* action = cocos2d::MoveTo::create(2.0f, cocos2d::Vec3(x, -160.0f, 0.0f));

	enemy->init(scene,texture,cocos2d::Vec2(x,2000.0f), action);

	this->enemys_.push_back(enemy);

}