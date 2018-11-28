#include "PlayerShotObserver.h"
#include "PlayerBulletCollection.h"
#include "../YoshiClass/PlayerMove.h"
#include <typeinfo>

PlayerShotObserver::PlayerShotObserver(){


}

PlayerShotObserver::~PlayerShotObserver() {



}

void PlayerShotObserver::Update(Subject* subject) {

	//if (typeid(PlayerMove*) != typeid(subject)) return;

	static float time = 0.0f;
	time += Director::getInstance()->getDeltaTime();

	if (time < 0.2f) return;
	time -= 0.2f;

	PlayerMove* playerMove = (PlayerMove*)subject;

	Vec2 pos = playerMove->GetPlayerPosition();

	Scene* scene = Director::getInstance()->getRunningScene();

	PlayerBulletCollection::GetInstance().CreateBullet(scene,pos);

}