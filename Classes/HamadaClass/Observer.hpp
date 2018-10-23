#pragma once
#include "cocos2d.h"
#include <list>

using namespace cocos2d;

// �ω���ʒm����I�u�U�[�o�[

class Subject;

/*�I�u�U�[�o�[���N���X
(�I�u�U�[�o�[���ϑ��A�T�u�W�F�N�g���ʒm����)*/ 
class Observer
{
public:
	virtual ~Observer() {};
	virtual void Update(Subject* subject) = 0;
};

// �T�u�W�F�N�g���N���X
class Subject
{
public:

	virtual ~Subject() {};

	// �ϑ�����I�u�W�F�N�g��o�^
	void AddObserver(Observer* observer)
	{
		observers.push_back(observer);
	}

	// �w�肵���I�u�W�F�N�g�̒ʒm���I��点��
	void RemoveObserver(Observer* observer)
	{
		observers.remove(observer);
	}

	// �o�^����Ă���I�u�U�[�o�[�ɒʒm����
	void notifyObservers()
	{
		for (std::list<Observer*>::iterator itr = observers.begin(); itr != observers.end(); ++itr)
		{
			(*itr)->Update(this);
		}
	}

	// �ώ@�Ώۂ̏�Ԃ��擾
	const int GetStatus()
	{
		return status;
	}

protected:
	// �ώ@�Ώۂ̏��
	int status;
private:
	std::list<Observer*> observers;
};

// �T�u�W�F�N�g�����N���X
class ConcreteSubject : Subject
{
public:
	/*��ԕω��̂��鏈����������notifyObservers���Ăяo��*/ 
	void Run()
	{
		// ��ԕω��̂��鏈��
		notifyObservers();
	}
};

//// �I�u�U�[�o�[�����N���X
//class ConcreateObserver : public Observer
//{
//public:
//	virtual void Update(Subject* subject)
//	{
//		subject->GetStatus();
//	}
//};