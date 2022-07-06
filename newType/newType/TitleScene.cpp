#include <DxLib.h>
#include "TitleScene.h"
#include "Player.h"
#include "MapManager.h"
#include "Input.h"

TitleScene::TitleScene()
	: m_ArrowImg(LoadGraph("data/BackGround/arrow.png"))
	, m_BackGroundImg(LoadGraph("data/BackGround/BackBlack.png"))
	, m_AlphaNum(0)
	, m_AlphaFlag(false)
{
	m_pPlayer = new Player(1500.0f);	// プレイヤークラスの生成
}

TitleScene::~TitleScene()
{
	delete m_pPlayer;				// プレイヤークラスの解放
}

TAG_SCENE TitleScene::Update()
{
	if (!m_AlphaFlag) { m_pPlayer->Update(); }
	else { m_AlphaNum++; }
	if (m_pPlayer->GetPosX() > 1760.0f) { m_AlphaFlag = true; }
	if (m_AlphaNum > 255) { return TAG_SCENE::TAG_PLAY; SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255); }// 次のシーンを返す
	if (m_pPlayer->GetPosX() < -50.0f ) { return TAG_SCENE::TAG_ESCAPE; }	// ゲーム終了ということを返す
	return TAG_SCENE::TAG_NONE;												// 現在のシーンを返す
}

void TitleScene::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	MapManager::Draw();												// マップ描画処理
	DrawGraph(1570, 730, m_ArrowImg, TRUE);							// 矢印（右）
	DrawTurnGraph(150, 730, m_ArrowImg, TRUE);						// 矢印（左）
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleScene");	// 文字列描画
	m_pPlayer->Draw();												// プレイヤーの描画処理
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_AlphaNum);
	DrawGraph(0, 0, m_BackGroundImg, FALSE);
}
