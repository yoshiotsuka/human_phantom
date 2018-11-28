#pragma once
#include "cocos2d.h"

USING_NS_CC;

class CollisionMediator {

public:

	CollisionMediator() {};
	virtual ~CollisionMediator() {};

	virtual void Update() = 0;

};
