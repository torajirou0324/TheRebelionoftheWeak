#include <DxLib.h>
#include "TitleScene.h"
#include "Player.h"
#include "MapManager.h"
#include "Input.h"

TitleScene::TitleScene()
	: m_ArrowImg(LoadGraph("data/BackGround/arrow.png"))
{
	m_pPlayer = new Player(810.0f);	// プレイヤークラスの生成
}

TitleScene::~TitleScene()
{
	delete m_pPlayer;				// プレイヤークラスの解放
}

TAG_SCENE TitleScene::Update()
{
	m_pPlayer->Update();
	if (m_pPlayer->GetPosX() > 1760.0f) { return TAG_SCENE::TAG_PLAY; }		// 次のシーンを返す
	if (m_pPlayer->GetPosX() < -50.0f) { return TAG_SCENE::TAG_ESCAPE; }	// ゲーム終了ということを返す
	return TAG_SCENE::TAG_NONE;												// 現在のシーンを返す
}

void TitleScene::Draw()
{
	MapManager::Draw();												// マップ描画処理
	DrawGraph(1570, 730, m_ArrowImg, TRUE);							// 矢印（右）
	DrawTurnGraph(150, 730, m_ArrowImg, TRUE);						// 矢印（左）
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleScene");	// 文字列描画
	m_pPlayer->Draw();												// プレイヤーの描画処理
}
