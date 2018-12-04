#pragma once
#include "cocos2d.h"
#include "HamadaClass\Observer.hpp"
#include <vector>

using namespace cocos2d;

class Player;

/*�S�[�X�g���Ǘ�����N���X
Observer���p�������̂́APlayerMove���ϑ���
�v���C���[���ړ�������A�Ǐ]�����邽��*/
class Ghost : public Observer
{
public:
	Ghost();
	~Ghost();
	bool Initialize(cocos2d::Scene* conectScene, Player* player);
	void Update(Subject* subject) override;
	void Following();

	// �Z�b�^�[
	void SetPosition(Vec2 position);

	// �Q�b�^�[
	Vec2 GetPosition();
private:
	Sprite* ghost;
	// �S�[�X�g�̍��W���Ǘ�����ϐ�
	Vec2 position;
	// �v���C���[��10�t���[���O�̍��W��ۑ�����z��
	std::vector<Vec2> save_position;

	Player* player;

};