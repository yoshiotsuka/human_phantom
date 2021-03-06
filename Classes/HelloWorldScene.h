#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Classes\HamadaClass\Player.hpp"
#include "Classes\HamadaClass\Ghost.hpp"

class HelloWorld : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    // a selector callback
    void menuCloseCallback(cocos2d::Ref* pSender);
	void Update();
    
    // implement the "static create()" method manually
	CREATE_FUNC(HelloWorld);
private:

	Player player;
	Ghost* ghost;

};

#endif // __HELLOWORLD_SCENE_H__
