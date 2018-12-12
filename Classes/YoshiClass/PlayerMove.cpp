#include "PlayerMove.h"
#include "HamadaClass\Player.hpp"

PlayerMove::PlayerMove()
{
	
}


PlayerMove::~PlayerMove()
{
}

bool PlayerMove::Init(cocos2d::Scene* node, Player* player)
{
	//�}�E�X�C�x���g�o�^�A������
	auto listener = EventListenerMouse::create();
	listener->onMouseMove = CC_CALLBACK_1(PlayerMove::onMouseMove, this);
	listener->onMouseDown = CC_CALLBACK_1(PlayerMove::onMouseDown, this);
	listener->onMouseUp = CC_CALLBACK_1(PlayerMove::onMouseUp, this);
	//�^�b�`�t���O������
	touchflag = false;


	
	node->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, node);

	//�v���C���[���[�u�N���X�������Ă���v���C���[�|�C���^�ɁA�v���C���[�����т���B
	this->player = player;

	//�}�E�X�C�x���g�o�^�A������

	//�^�b�`�������󂯕t����
	auto listener_2 = EventListenerTouchOneByOne::create();

	//��ʂ��^�b�`���ꂽ���ɌĂяo���֐����w��     
	listener_2->onTouchBegan = CC_CALLBACK_2(PlayerMove::onTouchBegan, this);

	//�^�b�`���Ȃ���ړ����Ă��鎞�ɌĂяo�����֐����w��
	listener_2->onTouchMoved = CC_CALLBACK_2(PlayerMove::onTouchMoved, this);

	//��ʂ���w�����ꂽ���ɌĂяo�����֐����w��
	listener_2->onTouchEnded = CC_CALLBACK_2(PlayerMove::onTouchEnded, this);

	//�^�b�`�t���O������
	touchflag = false;

	//�^�b�`�|�C���g
	touch_postion = player->GetPosition();

	//// �^�b�`������ǉ�
	auto testinstance = Director::getInstance();
	auto testevent = testinstance->getEventDispatcher();


	//Director::getInstance()->getEventDispatcher();
	testevent->addEventListenerWithSceneGraphPriority(listener_2, node);

	// �ړ��ʏ�����
	prev_mouse_position.x = 0.0f;
	prev_mouse_position.y = 0.0f;

	return true;
}
void PlayerMove::Update()
{


	//	auto mouse = (EventMouse*)event;
	//->setPosition(Point(mouse->getCursorX(),
	//	mouse->getCursorY()));*/
}

// �}�E�X�𓮂��������𔻒�
void PlayerMove::onMouseMove(Event* event)
{
	auto player_mouse = (EventMouse*)event;
	// �{�^����������Ă���Ƃ�
	if (touchflag == true)
	{
		float x = player_mouse->getCursorX();
		float y = player_mouse->getCursorY();
		Vec2 nowMousePos = Vec2(x,y);
		Vec2 delta = nowMousePos - prev_mouse_position;

		player->SetPostion(delta + player->GetPosition());
		prev_mouse_position = nowMousePos;
		/*�o�^����Ă���I�u�U�[�o�[�ɒʒm����*/
		this->notifyObservers();
	}
}

// �v���C���[�̍��W���擾
Vec2 PlayerMove::GetPosition()
{
	return player->GetPosition();
}

// �}�E�X�̃{�^�������������𔻒�
void PlayerMove::onMouseDown(Event* event)
{
	/*�}�E�X�̃{�^������������t���O��true��
	�{�^�����͂�L���ɂ���*/ 
	touchflag = true;

	auto player_mouse = (EventMouse*)event;

	float x = player_mouse->getCursorX();
	float y = player_mouse->getCursorY();
	Vec2 nowMousePos = Vec2(x, y);
	prev_mouse_position = nowMousePos;

}

// �}�E�X�̃{�^���𗣂������𔻒�
void PlayerMove::onMouseUp(Event* event)
{
	/*�}�E�X�̃{�^���𗣂�����false�ɂ�
	�{�^�����͂𖳌��ɂ���*/ 
	touchflag = false;
}

bool PlayerMove::onTouchBegan(cocos2d::Touch* touch, cocos2d::Event* event)
{
	touchflag = true;
	auto player_touch = (EventMouse*)event;

	player->GetPosition();

	if (touchflag == true)
	{
		/*�o�^����Ă���I�u�U�[�o�[�ɒʒm����*/
		this->notifyObservers();
	}
	touchflag = true;
	return true;
}

void PlayerMove::onTouchMoved(cocos2d::Touch* touch, cocos2d::Event* event)
{
	auto player_touch = (EventMouse*)event;

	//player->SetPostion(Point(position, player_touch->getDelta()));
	if (touchflag == true)
	{
		//���݂�2�̃f���^����ʍ��W�̈ʒu�ɖ߂�
		Vec2 delta = touch->getDelta();

		// ���݂̍��W���擾����
		Vec2 player_position = player->GetPosition();

		// ���ݍ��W�@+ �ړ��ʂ�V���ȍ��W�ɂ���
		Vec2 new_player_position = player_position + delta;

		player->SetPostion(new_player_position);
	}
}

void PlayerMove::onTouchEnded(cocos2d::Touch* touch, cocos2d::Event* event)
{
	touchflag = false;
}

