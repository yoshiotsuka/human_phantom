#pragma once
#include "cocos2d.h"
#include <list>

using namespace cocos2d;

// 変化を通知するオブザーバー

// サブジェクト基底クラス
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
	// 観察対象の情報
	int status;
private:
	std::list<Observer*> observers;
};

// サブジェクト実装クラス
class ConcreteSubject : Subject
{
public:
	void Run()
	{
		// 状態変化のある処理
		notifyObservers();
	}
};

// オブザーバー基底クラス
class Observer
{
public:
	virtual ~Observer() {};
	virtual void Update(Subject* subject) = 0;
};

// オブザーバー実装クラス
class ConcreateObserver : public Observer
{
public:
	virtual void Update(Subject* subject)
	{
		subject->GetStatus();
	}
};