#pragma once
#include "CollisionMediator.h"

class PlayerBulletCollection;
class EnemyCollection;

class PlayerBulletCollisionMediator : public CollisionMediator {

public:

	PlayerBulletCollisionMediator(PlayerBulletCollection* playerBulletManager,
								  EnemyCollection*		  enemyManager);

	virtual ~PlayerBulletCollisionMediator();

	virtual void Update() override;

private:

	PlayerBulletCollection* playerBulletManager_;
	EnemyCollection*		enemyManager_;

};