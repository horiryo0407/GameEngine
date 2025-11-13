#include "Direct3D.h"
#include "SceneManager.h"
#include "..\\PlayScene.h"
#include "..\\TestScene.h"
#include "..\\ResultScene.h"


SceneManager* SceneManager::instance_ = nullptr;


SceneManager::SceneManager(GameObject* parent)
	:GameObject(parent, "SceneManager"), currentSceneID_(SCENE_ID_TEST)
{
	instance_ = this;
}

SceneManager::~SceneManager()
{
}

void SceneManager::Initialize()
{
	currentSceneID_ = SCENE_ID_TEST;
	currentSceneID_ = currentSceneID_;
	Instantiate<TestScene>(this);
}

void SceneManager::Update()
{
	if (currentSceneID_ != nextSceneID_)
	{

		auto scene = childList_.front();
		scene->ReleaseSub();
		SAFE_DELETE(scene);
		childList_.clear();

		
		switch (nextSceneID_)
		{
		case SCENE_ID_RESULT:
			Instantiate<ResultScene>(this);
			break;
		case SCENE_ID_PLAY:
		
			Instantiate<PlayScene>(this);
			break;
		case SCENE_ID_TEST:
			Instantiate<TestScene>(this);
			break;
		
		}
		currentSceneID_ = nextSceneID_;
	}
}

void SceneManager::Draw()
{
}

void SceneManager::Release()
{
}

void SceneManager::ChangeScene(SCENE_ID _nextScene)
{
	nextSceneID_ = _nextScene;
}
