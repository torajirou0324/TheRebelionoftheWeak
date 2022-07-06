#pragma once
#include "SceneBase.h"

class Player;

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene()override;

	TAG_SCENE Update()override;
	void Draw()override;
private:
	Player* m_pPlayer;	// プレイヤーのポインタ

	int m_StatusImg;	// ステータス表示の枠画像ハンドル
};