#pragma once

#include <cocos2d.h>

class Bullet {

public:

	Bullet();
	virtual ~Bullet();

	virtual bool init(	cocos2d::Scene*	  scene,
						cocos2d::Texture2D* texture,
						cocos2d::Vec2		  position,
						cocos2d::Action*	  action = nullptr);

	bool IsUsing() { return this->usingFlag_; }
	void Used() { this->usingFlag_ = false; }

	cocos2d::Vec2 GetPosition() { return this->sprite_->getPosition(); }
	void		  SetPosition(cocos2d::Vec2 position) { this->sprite_->setPosition(position); }

	cocos2d::Rect GetRect() { this->sprite_->getBoundingBox(); }

private:

	cocos2d::Sprite* sprite_ = nullptr;

	bool usingFlag_;

};