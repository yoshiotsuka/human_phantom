#pragma once
#include "cocos2d.h"
using namespace cocos2d;

#include "../HamadaClass/Observer.hpp"

class Subject;

class PlayerShotObserver final : public Observer{

public:

	PlayerShotObserver();
	~PlayerShotObserver();

	void Update(Subject* subject);

private:

};