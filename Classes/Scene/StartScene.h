#define ASIO_STANDALONE
#pragma warning(disable:4996)
#pragma once
#ifndef START_SCENE_H_
#define START_SCENE_H_
#include <cocos2d.h>
#include"asio.hpp"
#include"chat_server.h"
#include"chat_client.h"

USING_NS_CC;

class StartScene :public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void menuServerCallback(cocos2d::Ref* pSender);
	void menuClientCallback(cocos2d::Ref* pSender);
	void menuBackCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(StartScene);
};

class ServerMenu :public cocos2d::Layer{
public:
	static cocos2d::Scene* createScene(int * map_choice);
	static ServerMenu * create(int * map_choice);

	virtual bool init(int * map_choice);

	void menuStartServerCallback(cocos2d::Ref* pSender);
	void menuStartGameCallback(cocos2d::Ref* pSender);
	void menuBackCallback(cocos2d::Ref* pSender);
//	void menuSelectMap1Callback(cocos2d::Ref* pSender);
//	void menuSelectMap2Callback(cocos2d::Ref* pSender);
	void connectionUpdate(float f);

private:
	int _map_choice;

	cocos2d::Label* connection_label;
	chat_server * server_side = nullptr;
	chat_client * client_side = nullptr;
};

class MapChoiceScene :public cocos2d::Layer {
public:
	static cocos2d::Scene * createScene();
	virtual bool init();

	CREATE_FUNC(MapChoiceScene);
private:
	int _map_choice = 1;

	void menuSelectMap1Callback(cocos2d::Ref* pSender);
	void menuSelectMap2Callback(cocos2d::Ref* pSender);
	void menuNextCallback(cocos2d::Ref* pSender);
	void menuBackCallback(cocos2d::Ref* pSender);
};

class ClientMenu :public cocos2d::Layer {
public:
	static cocos2d::Scene* createScene();
	virtual bool init();

	void menuStartGameCallback(cocos2d::Ref* pSender);
	void menuBackCallback(cocos2d::Ref* pSender);

	CREATE_FUNC(ClientMenu);
	void startSchedule(float f);
	void wait_start();
	
	
	
	chat_client *client_side = { nullptr };
};

#endif