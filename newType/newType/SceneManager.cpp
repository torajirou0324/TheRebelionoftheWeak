#include <DxLib.h>
#include "SceneManager.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "VictoryScene.h"
#include "DefeatScene.h"
#include "MapManager.h"
#include "Input.h"

SceneManager::SceneManager()
{
	MapManager::CreateInstance();
	CreateScene(TAG_SCENE::TAG_TITLE);	// 現在のシーンをタイトルで初期化
	GameLoop();							// ゲームシーンをループする関数へ
}

SceneManager::~SceneManager()
{
	if (m_pNowScene != nullptr) { delete m_pNowScene; }	// 解放処理
	MapManager::DeleteInstance();
}

void SceneManager::GameLoop()
{
	Input::CreateInstance();			// 入力関係クラスの生成
	while (!Input::IsPress(ESCAPE))	// ESCAPEキーを押すと強制終了
	{
		Input::Update();
		ClearDrawScreen();
		auto tag = m_pNowScene->Update();	// 現在のシーンの更新処理
		m_pNowScene->Draw();				// 現在のシーンの描画処理
		ScreenFlip();
		if (tag == TAG_SCENE::TAG_NONE)		// 次のシーンのタグが返ってくるまで現在のシーンの処理を続ける
		{
			continue;
		}
		if (tag == TAG_SCENE::TAG_ESCAPE) { break; }
		ClearScene();		// 現在のシーンを解放
		CreateScene(tag);	// 次のシーンを生成
	}
	Input::DeleteInstance();// 入力関係クラスの解放
}

void SceneManager::CreateScene(TAG_SCENE tag)
{
	switch (tag)
	{
	case TAG_SCENE::TAG_TITLE:
		m_pNowScene = new TitleScene;	// タイトルシーンを生成
		MapManager::Init(MapScene::MAP_TITLE);
		break;
	case TAG_SCENE::TAG_PLAY:
		m_pNowScene = new PlayScene;	// プレイシーンを生成
		MapManager::Init(MapScene::MAP_BATTLE);
		break;
	case TAG_SCENE::TAG_CLEAR:
		m_pNowScene = new VictoryScene;	// 勝利シーンを生成
		MapManager::Init(MapScene::MAP_VICTORY);
		break;
	case TAG_SCENE::TAG_OVER:
		m_pNowScene = new DefeatScene;	// 敗北シーンを生成
		MapManager::Init(MapScene::MAP_DEFEAT);
		break;
	case TAG_SCENE::TAG_ESCAPE:			// ゲーム終了シーン
		break;
	case TAG_SCENE::TAG_NONE:			// 空のシーン
		break;
	default:
		break;
	}
}

void SceneManager::ClearScene()
{
	if (m_pNowScene == nullptr)
	{

	}
	else
	{
		delete m_pNowScene;
		m_pNowScene = nullptr;
	}
}
