#include "Ghost.hpp"
#include "cocos2d.h"
#include "Classes\HamadaClass\Player.hpp"
#include "YoshiClass\PlayerMove.h"


Ghost::Ghost()
{

}

Ghost::~Ghost()
{

}

bool Ghost::Initialize(cocos2d::Scene* conectScene, Player* player)
{
	// ゴースト
	auto ghost_sprite = Sprite::create("unnamed.jpg");
	if (ghost_sprite == nullptr)
	{

	}
	else
	{
		conectScene->addChild(ghost_sprite, 0);
	}
	// ゴースト画像データ読み込み
	ghost = Sprite::create("player.JPG");
	if (ghost_sprite == nullptr)
	{

	}
	else
	{

	}
	// TODOプレイヤー追従
	Size size = Director::getInstance()->getWinSize();
	ghost->setPosition(Vec2(550, 100));
	conectScene->addChild(ghost, 0);
	/*ゴーストクラスが持っているプレイヤーポインタに、
	プレイヤーを結びつける*/ 
	this->player = player;

	// 配列初期化
	this->save_position = std::vector<Vec2>(30, this->player->GetPosition());

	return true;
}

/*引数subjectは通知してきたPlayerMoveを受け取るため*/
void Ghost::Update(Subject* subject)
{
	/*subjectをキャストして、PlayerMoveを受ける*/
	PlayerMove* playerMove = (PlayerMove*)subject;

	/*PlayerMoveの座標を取得する*/
	position = playerMove->GetPosition();
	

	Following();
	
	ghost->setPosition(save_position[29].x, save_position[29].y);
}

// グラディウスオプション風の動きを再現させる関数
void Ghost::Following()
{
	// 一番後ろの要素を削除
	save_position.pop_back();
	// 先頭の要素にプレイヤーの座標を追加
	save_position.insert(save_position.begin(), player->GetPosition());
}

// ゴーストの座標を取得
Vec2 Ghost::GetPosition()
{
	return position;
}

// ゴーストの座標設定
void Ghost::SetPosition(Vec2 position)
{
	this->position = position;
}