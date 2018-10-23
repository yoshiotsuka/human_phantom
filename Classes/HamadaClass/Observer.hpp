#pragma once
#include "cocos2d.h"
#include <list>

using namespace cocos2d;

// �ω���ʒm����I�u�U�[�o�[

// �T�u�W�F�N�g���N���X
class Subject
{
public:

	virtual ~Subject() {};

	void AddObserver(Observer* observer)
	{
		observers.push_back(observer);
	}

	void RemoveObserver(Observer* observer)
	{
		observers.remove(observer);
	}

	void notifyObservers()
	{
		for (std::list<Observer*>::iterator itr = observers.begin(); itr != observers.end(); ++itr)
		{
			(*itr)->Update(this);
		}
	}

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
	void Run()
	{
		// ��ԕω��̂��鏈��
		notifyObservers();
	}
};

// �I�u�U�[�o�[���N���X
class Observer
{
public:
	virtual ~Observer() {};
	virtual void Update(Subject* subject) = 0;
};

// �I�u�U�[�o�[�����N���X
class ConcreateObserver : public Observer
{
public:
	virtual void Update(Subject* subject)
	{
		subject->GetStatus();
	}
};