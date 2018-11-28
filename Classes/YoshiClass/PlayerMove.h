#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "HamadaClass/Observer.hpp"

class Player;

class PlayerMove : public Subject
{
public:
	PlayerMove();
	~PlayerMove();

	bool Init(cocos2d::Scene* scene , Player* player);
	void Update();

	Vec2 GetPlayerPosition() { return player->GetPosition(); }

private:

	void onMouseMove(cocos2d::Event* event); // �}�E�X�ړ�
	void onMouseDown(cocos2d::Event* event); // �}�E�X�{�^���_�E��
	void onMouseUp  (cocos2d::Event* event); // �}�E�X�{�^���A�b�v

	Player* player;

	bool touchFlag_;

};