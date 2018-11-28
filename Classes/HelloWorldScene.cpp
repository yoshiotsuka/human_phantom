#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"
#include "YoshiClass\PlayerMove.h"
#include "FujimuraClass\EnemyCollection.h"
#include "FujimuraClass/PlayerBulletCollection.h"


USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
   // printf("Error while loading: %s\n", filename);
   // printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

   // TODO
   // TODO
	player_move = new PlayerMove();
	player.Initialize(this, player_move);

	ghost = new Ghost();
	ghost->Initialize(this, &player);
	player_move->AddObserver(ghost);

	EnemyCollection::GetInstance().Initialize(this);
	PlayerBulletCollection::GetInstance().Initialize(this);

	shotObserver = new PlayerShotObserver();
	player_move->AddObserver(shotObserver);

	EnemyCollection* enemyManager = &EnemyCollection::GetInstance();
	PlayerBulletCollection* playerBulletManager = &PlayerBulletCollection::GetInstance();

	this->playerBulletCollision = new PlayerBulletCollisionMediator(playerBulletManager,enemyManager);

	this->scheduleUpdate();

    return true;

}

void HelloWorld::update(float delta){

	static float totaltime = 0;

	totaltime += delta;

	player_move->Update();
	
	if (totaltime > 0.3f) {

		totaltime -= 0.3f;
		EnemyCollection::GetInstance().CreateEnemy(this);

	}

	EnemyCollection::GetInstance().Update();
	PlayerBulletCollection::GetInstance().Update();

	this->playerBulletCollision->Update();

}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
	//Close the cocos2d-x game scene and quit the application
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif


	/*To navigate back to native iOS screen(if present) without quitting the application  ,do not use Director::getInstance()->end() and exit(0) as given above,instead trigger a custom event created in RootViewController.mm as below*/

	//EventCustom customEndEvent("game_scene_close_event");
	//_eventDispatcher->dispatchEvent(&customEndEvent);

}