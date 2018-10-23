#ifndef __HELLOWORLD_SCENE_H__
#define __HELLOWORLD_SCENE_H__

#include "cocos2d.h"
#include "Classes\HamadaClass\Player.hpp"
#include "Classes\OkuhamaClass\Enemy.h"
#include <memory>

class EnemyCollection;

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
	Enemy enemy_;
	std::shared_ptr<EnemyCollection> enemyCollection_;

};

#endif // __HELLOWORLD_SCENE_H__
