#pragma once
#include "SceneBase.h"

class Player;

class TitleScene : public SceneBase
{
public:
	TitleScene();			// コンストラクタ
	~TitleScene()override;	// デストラクタ

	TAG_SCENE Update()override;	// 更新処理
	void Draw()override;		// 描画処理

private:
	Player* m_pPlayer;		// プレイヤークラスのポインタ

	int m_BackGroundImg;	// フェードアウト用画像ハンドル
	int m_ArrowImg;			
	int m_AlphaNum;			// アルファ値

	bool m_AlphaFlag;		// アルファフラグ
};