#pragma once
#include "cocos2d.h"
#include "HamadaClass\Observer.hpp"

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

	// �Z�b�^�[
	void SetPosition(Vec2 position);

	// �Q�b�^�[
	Vec2 GetPosition();
private:
	Sprite* ghost;
	Vec2 position;

	Player* player;
};