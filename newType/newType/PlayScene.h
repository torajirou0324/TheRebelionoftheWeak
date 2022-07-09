#pragma once
#include "SceneBase.h"

class Player;
class Enemy;
class Collider;

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene()override;

	TAG_SCENE Update()override;	// 更新処理
	void Draw()override;		// 描画処理
private:
	Player* m_pPlayer;		// プレイヤーのポインタ
	Enemy* m_pEnemy;		// エネミーのポインタ
	Collider* m_pCollider;	// コライダーポインタ

	int m_StatusImg;	// ステータス表示の枠画像ハンドル
};