#include <DxLib.h>
#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "MapManager.h"
#include "Input.h"
#include "Collider.h"

PlayScene::PlayScene()
	: m_StatusImg(LoadGraph("data/BackGround/StatusImg.png"))
{
	m_pCollider = new Collider;
	m_pPlayer = new Player(0.0f);
	Collision_Tag AABB;
	AABB.m_pCollider = m_pPlayer;
	AABB.m_tag = TAG::PLAYER;
	m_pCollider->Add(AABB);
	m_pEnemy = new Enemy;
	AABB.m_pCollider = m_pEnemy;
	AABB.m_tag = TAG::ENEMY;
	m_pCollider->Add(AABB);
}

PlayScene::~PlayScene()
{
	delete m_pPlayer;
	delete m_pEnemy;
	delete m_pCollider;
}

TAG_SCENE PlayScene::Update()
{
	if (!m_pPlayer->GetDamageFlag()) { m_pPlayer->SetDamageFlag(m_pCollider->PCollision()); }	// �v���C���[�ƃG�l�~�[�̓����蔻�菈��
	if (m_pPlayer->GetAttackFlag() && !m_pEnemy->GetDamageFlag()) { m_pEnemy->SetDamageFlag(m_pCollider->ECollision()); }	// �G�̃v���C���[�U���������������̔��菈��

	m_pPlayer->Update();		// �v���C���[�̍X�V����
	m_pEnemy->Update();			// �G�l�~�[�̍X�V����

	if (m_pEnemy->GetDeathFlag()) { return TAG_SCENE::TAG_CLEAR; }			// �N���A�V�[����Ԃ�
	if (m_pPlayer->GetHPLength() == 0.0f) { return TAG_SCENE::TAG_OVER; }	// �Q�[���I�[�o�[�V�[����Ԃ�
	return TAG_SCENE::TAG_NONE;												// ���݂̃V�[�����p�����邱�Ƃ�Ԃ�
}

void PlayScene::Draw()
{
	MapManager::Draw();
	DrawGraph(0, 0, m_StatusImg, FALSE);
	DrawFormatString(100, 50, GetColor(255, 255, 255), "Solder");
	DrawBox(100, 100, 100 + static_cast<int>(m_pPlayer->GetHPLength()), 150, GetColor(0, 255, 0), TRUE);
	DrawBox(100, 100, 600, 150, GetColor(255, 255, 255), FALSE);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "PlayScene");	// ������`��
	m_pPlayer->Draw();
	m_pEnemy->Draw();
}
