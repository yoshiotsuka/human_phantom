#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "HamadaClass\Observer.hpp"

class Player;

/*�v���C���[�̓������Ǘ�����N���X
Subject���p�������̂́A�ړ�������ʒm���邽��*/
class PlayerMove : public Subject
{
public:
	PlayerMove();
	~PlayerMove();

	bool Init(cocos2d::Scene* scene , Player* player);
	
	Vec2 GetPosition();

private:

	void Update();

	void onMouseMove(cocos2d::Event* event); // �}�E�X�ړ�
	void onMouseDown(cocos2d::Event* event); // �}�E�X�{�^���_�E��
	void onMouseUp  (cocos2d::Event* event); // �}�E�X�{�^���A�b�v

	bool touchflag;

	Player* player;
	Vec2 position;
};

