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

	// �z�񏉊���
	this->save_position = std::vector<Vec2>(30, this->player->GetPosition());

	return true;
}

/*����subject�͒ʒm���Ă���PlayerMove���󂯎�邽��*/
void Ghost::Update(Subject* subject)
{
	/*subject���L���X�g���āAPlayerMove���󂯂�*/
	PlayerMove* playerMove = (PlayerMove*)subject;

	/*PlayerMove�̍��W���擾����*/
	position = playerMove->GetPosition();
	

	Following();
	
	ghost->setPosition(save_position[29].x, save_position[29].y);
}

// �O���f�B�E�X�I�v�V�������̓������Č�������֐�
void Ghost::Following()
{
	// ��Ԍ��̗v�f���폜
	save_position.pop_back();
	// �擪�̗v�f�Ƀv���C���[�̍��W��ǉ�
	save_position.insert(save_position.begin(), player->GetPosition());
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