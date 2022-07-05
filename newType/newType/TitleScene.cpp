#include <DxLib.h>
#include "TitleScene.h"
#include "Input.h"

TitleScene::TitleScene()
	: m_BackGroundImg(LoadGraph("data/BackGround/TitleImg.png"))
	, m_ArrowImg(LoadGraph("data/BackGround/arrow.png"))
{
}

TitleScene::~TitleScene()
{
}

TAG_SCENE TitleScene::Update()
{
	if (Input::IsPress(SPACE))
	{
		return TAG_SCENE::TAG_PLAY;
	}
	return TAG_SCENE::TAG_NONE;
}

void TitleScene::Draw()
{
	DrawGraph(0, 0, m_BackGroundImg, TRUE);							// 背景描画
	DrawGraph(1570, 750, m_ArrowImg, TRUE);							// 矢印（右）
	DrawTurnGraph(150, 750, m_ArrowImg, TRUE);						// 矢印（左）
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleScene");	// 文字列描画
}
