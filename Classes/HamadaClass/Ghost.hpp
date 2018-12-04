#pragma once
#include "cocos2d.h"
#include "HamadaClass\Observer.hpp"
#include <vector>

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
	void Following();

	// セッター
	void SetPosition(Vec2 position);

	// ゲッター
	Vec2 GetPosition();
private:
	Sprite* ghost;
	// ゴーストの座標を管理する変数
	Vec2 position;
	// プレイヤーの10フレーム前の座標を保存する配列
	std::vector<Vec2> save_position;

	Player* player;

};