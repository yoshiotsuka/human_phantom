#pragma once
#include "cocos2d.h"
#include <list>

using namespace cocos2d;

// 変化を通知するオブザーバー

class Subject;

/*オブザーバー基底クラス
(オブザーバーが観測、サブジェクトが通知する)*/ 
class Observer
{
public:
	virtual ~Observer() {};
	virtual void Update(Subject* subject) = 0;
};

// サブジェクト基底クラス
class Subject
{
public:

	virtual ~Subject() {};

	// 観測するオブジェクトを登録
	void AddObserver(Observer* observer)
	{
		observers.push_back(observer);
	}

	// 指定したオブジェクトの通知を終わらせる
	void RemoveObserver(Observer* observer)
	{
		observers.remove(observer);
	}

	// 登録されているオブザーバーに通知する
	void notifyObservers()
	{
		for (std::list<Observer*>::iterator itr = observers.begin(); itr != observers.end(); ++itr)
		{
			(*itr)->Update(this);
		}
	}

	// 観察対象の状態を取得
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
	/*状態変化のある処理をしたらnotifyObserversを呼び出す*/ 
	void Run()
	{
		// 状態変化のある処理
		notifyObservers();
	}
};

//// オブザーバー実装クラス
//class ConcreateObserver : public Observer
//{
//public:
//	virtual void Update(Subject* subject)
//	{
//		subject->GetStatus();
//	}
//};