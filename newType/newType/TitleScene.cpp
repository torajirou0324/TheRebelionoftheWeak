#include <DxLib.h>
#include "TitleScene.h"
#include "Player.h"
#include "MapManager.h"
#include "Input.h"

TitleScene::TitleScene()
	: m_ArrowImg(LoadGraph("data/BackGround/arrow.png"))
{
	m_pPlayer = new Player(810.0f);	// �v���C���[�N���X�̐���
}

TitleScene::~TitleScene()
{
	delete m_pPlayer;				// �v���C���[�N���X�̉��
}

TAG_SCENE TitleScene::Update()
{
	m_pPlayer->Update();
	if (m_pPlayer->GetPosX() > 1760.0f) { return TAG_SCENE::TAG_PLAY; }		// ���̃V�[����Ԃ�
	if (m_pPlayer->GetPosX() < -50.0f) { return TAG_SCENE::TAG_ESCAPE; }	// �Q�[���I���Ƃ������Ƃ�Ԃ�
	return TAG_SCENE::TAG_NONE;												// ���݂̃V�[����Ԃ�
}

void TitleScene::Draw()
{
	MapManager::Draw();												// �}�b�v�`�揈��
	DrawGraph(1570, 730, m_ArrowImg, TRUE);							// ���i�E�j
	DrawTurnGraph(150, 730, m_ArrowImg, TRUE);						// ���i���j
	DrawFormatString(0, 0, GetColor(255, 255, 255), "TitleScene");	// ������`��
	m_pPlayer->Draw();												// �v���C���[�̕`�揈��
}
