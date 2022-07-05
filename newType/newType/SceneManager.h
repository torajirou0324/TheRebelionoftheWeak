#pragma once
class SceneBase;
enum class TAG_SCENE;

// シーンを管理するクラス
class SceneManager
{
public:
	SceneManager();	// コンストラクタ
	~SceneManager();// デストラクタ

	void GameLoop();	// シーンループ関数

	void CreateScene(TAG_SCENE tag);	// シーンを生成
	void ClearScene();					// シーンを破壊

private:
	SceneBase* m_pNowScene;		// 現在のシーン
};