#pragma once
#include "HelloWorldScene.h"
#include "cocos2d.h"
#include "HamadaClass\Observer.hpp"
USING_NS_CC;

class Player;

/*�v���C���[�̓������Ǘ�����N���X
Subject���p�������̂́A�ړ�������ʒm���邽��*/
class PlayerMove : public Subject
{
public:
	PlayerMove();
	~PlayerMove();

	bool Init(cocos2d::Scene* node , Player* player);
	//void Update();

	////�^�b�`�J�n
	bool  onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event);

	//�^�b�`��
	void onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event);

	//�^�b�`�I��
	void onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event);
	
	Vec2 GetPosition();

private:

	void Update();

	void onMouseMove(cocos2d::Event* event); // �}�E�X�ړ�
	void onMouseDown(cocos2d::Event* event); // �}�E�X�{�^���_�E��
	void onMouseUp  (cocos2d::Event* event); // �}�E�X�{�^���A�b�v

	bool touchflag;

	Player* player;
	Vec2 position;

	Vec2 prev_mouse_position;

	//�^�b�`�|�W�V����
	Vec2 touch_postion;
};

