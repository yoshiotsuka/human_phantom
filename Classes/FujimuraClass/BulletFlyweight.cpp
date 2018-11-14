#include "BulletFlyweight.h"
#include "Bullet.h"

BulletFlyweight::BulletFlyweight() {



}

BulletFlyweight::~BulletFlyweight() {

	if (this->bullets_.size() > 0) {

		for (auto data : this->bullets_) {

			delete data;

		}

	}

}

Bullet* BulletFlyweight::GetBulletInstance() {

	for (auto bullet : this->bullets_) {

		if (bullet->IsUsing()) continue;

		return bullet;

	}

	Bullet* bullet = new Bullet();
	this->bullets_.push_back(bullet);

	return bullet;

}

void BulletFlyweight::UsedBulletInstance(Bullet* bullet) {

	bullet->Used();

}