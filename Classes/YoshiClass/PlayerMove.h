#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"

class Player;

class PlayerMove
{
public:
	PlayerMove();
	~PlayerMove();

	bool Init(cocos2d::Scene* scene , Player* player);

private:

	void Update();

	void onMouseMove(cocos2d::Event* event); // �}�E�X�ړ�
	void onMouseDown(cocos2d::Event* event); // �}�E�X�{�^���_�E��
	void onMouseUp  (cocos2d::Event* event); // �}�E�X�{�^���A�b�v

	bool touchflag;

	Player* player;

};

