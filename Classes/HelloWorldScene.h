#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Classes\HamadaClass\Player.hpp"
#include "Classes\HamadaClass\Ghost.hpp"
#include "FujimuraClass/PlayerShotObserver.h"
#include "FujimuraClass/PlayerBulletCollisionMediator.h"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
	virtual void update(float delta) override;
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void Update();
    
    // implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
private:

	Player player;
	PlayerMove* player_move;
	Ghost* ghost;
	PlayerShotObserver* shotObserver;

	PlayerBulletCollisionMediator* playerBulletCollision;

};

#endif // __HELLOWORLD_SCENE_H__
