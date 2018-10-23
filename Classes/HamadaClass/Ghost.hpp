#pragma once
#include "cocos2d.h"
#include "HamadaClass\Observer.hpp"

using namespace cocos2d;

class Player;

/*ゴーストを管理するクラス
Observerを継承したのは、PlayerMoveを観測し
プレイヤーが移動したら、追従させるため*/
class Ghost : public Observer
{
public:
	Ghost();
	~Ghost();
	bool Initialize(cocos2d::Scene* conectScene, Player* player);
	void Update(Subject* subject) override;

	// セッター
	void SetPosition(Vec2 position);

	// ゲッター
	Vec2 GetPosition();
private:
	Sprite* ghost;
	Vec2 position;

	Player* player;
};