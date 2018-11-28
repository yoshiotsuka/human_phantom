#include "PlayerBulletCollisionMediator.h"

#include "PlayerBulletCollection.h"
#include "EnemyCollection.h"

#include "../OkuhamaClass/Bullet.h"
#include "../OkuhamaClass/Enemy.h"

PlayerBulletCollisionMediator::PlayerBulletCollisionMediator(PlayerBulletCollection* playerBulletManager,
															 EnemyCollection*		 enemyManager) {

	this->playerBulletManager_ = playerBulletManager;
	this->enemyManager_ = enemyManager;

}

PlayerBulletCollisionMediator::~PlayerBulletCollisionMediator() {



}

void PlayerBulletCollisionMediator::Update() {

	auto playerBullets = this->playerBulletManager_->GetBullets();
	auto enemys = this->enemyManager_->GetEnemys();

	std::list<Bullet*> eraseBullets;
	std::list<Enemy*> eraseEnemys;

	for (auto pb_itr = playerBullets.begin(); pb_itr != playerBullets.end(); pb_itr++) {

		for (auto e_itr = enemys.begin(); e_itr != enemys.end(); e_itr++) {

			Rect playerBulletRect = (*pb_itr)->GetRect();
			Rect enemyRect		  = (*e_itr) ->GetRect();

			if (playerBulletRect.intersectsRect(enemyRect)) {

				eraseBullets.push_back((*pb_itr));
				eraseEnemys .push_back((*e_itr ));

			}

		}

	}

	for (auto data : eraseBullets) {

		this->playerBulletManager_->EraseBullet(data);

	}

	for (auto data : eraseEnemys) {

		this->enemyManager_->EraseEnemy(data);

	}

}