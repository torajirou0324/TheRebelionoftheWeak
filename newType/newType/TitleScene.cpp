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
	m_pPlayer = new Player(1500.0f);	// �v���C���[�N���X�̐���
}

TitleScene::~TitleScene()
{
	delete m_pPlayer;				// �v���C���[�N���X�̉��
}

TAG_SCENE TitleScene::Update()
{
	if (!m_AlphaFlag) { m_pPlayer->Update(); }
	else { m_AlphaNum++; }
	if (m_pPlayer->GetPosX() > 1760.0f) { m_AlphaFlag = true; }
	if (m_AlphaNum > 255) { return TAG_SCENE::TAG_PLAY; SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255); }// ���̃V�[����Ԃ�
	if (m_pPlayer->GetPosX() < -50.0f ) { return TAG_SCENE::TAG_ESCAPE; }	// �Q�[���I���Ƃ������Ƃ�Ԃ�
	return TAG_SCENE::TAG_NONE;												// ���݂̃V�[����Ԃ�
}

void TitleScene::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	MapManager::Draw();												// �}�b�v�`�揈��
	DrawGraph(1570, 730, m_ArrowImg, TRUE);							// ���i�E�j
	DrawTurnGraph(150, 730, m_ArrowImg, TRUE);						// ���i���j
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleScene");	// ������`��
	m_pPlayer->Draw();												// �v���C���[�̕`�揈��
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_AlphaNum);
	DrawGraph(0, 0, m_BackGroundImg, FALSE);
}
