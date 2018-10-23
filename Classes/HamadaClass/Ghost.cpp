#include "Ghost.hpp"
#include "cocos2d.h"
#include "Classes\HamadaClass\Player.hpp"


Ghost::Ghost()
{

}

Ghost::~Ghost()
{

}

bool Ghost::Initialize(cocos2d::Scene* conectScene, Player* player)
{
	// �S�[�X�g
	auto ghost_sprite = Sprite::create("unnamed.jpg");
	if (ghost_sprite == nullptr)
	{

	}
	else
	{
		conectScene->addChild(ghost_sprite, 0);
	}
	// �S�[�X�g�摜�f�[�^�ǂݍ���
	ghost = Sprite::create("player.JPG");
	if (ghost_sprite == nullptr)
	{

	}
	else
	{

	}
	// TODO�v���C���[�Ǐ]
	Size size = Director::getInstance()->getWinSize();
	ghost->setPosition(Vec2(550, 100));
	conectScene->addChild(ghost, 0);
	/*�S�[�X�g�N���X�������Ă���v���C���[�|�C���^�ɁA
	�v���C���[�����т���*/ 
	this->player = player;
	return true;
}

// �S�[�X�g�̍��W���擾
Vec2 Ghost::GetPosition()
{
	return position;
}

// �S�[�X�g�̍��W�ݒ�
void Ghost::SetPosition(Vec2 position)
{
	this->position = position;
}