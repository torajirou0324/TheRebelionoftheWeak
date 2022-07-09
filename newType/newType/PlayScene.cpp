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
	if (!m_pPlayer->GetDamageFlag()) { m_pPlayer->SetDamageFlag(m_pCollider->PCollision()); }	// プレイヤーとエネミーの当たり判定処理
	if (m_pPlayer->GetAttackFlag() && !m_pEnemy->GetDamageFlag()) { m_pEnemy->SetDamageFlag(m_pCollider->ECollision()); }	// 敵のプレイヤー攻撃が当たったかの判定処理

	m_pPlayer->Update();		// プレイヤーの更新処理
	m_pEnemy->Update();			// エネミーの更新処理

	if (m_pEnemy->GetDeathFlag()) { return TAG_SCENE::TAG_CLEAR; }			// クリアシーンを返す
	if (m_pPlayer->GetHPLength() == 0.0f) { return TAG_SCENE::TAG_OVER; }	// ゲームオーバーシーンを返す
	return TAG_SCENE::TAG_NONE;												// 現在のシーンを継続することを返す
}

void PlayScene::Draw()
{
	MapManager::Draw();
	DrawGraph(0, 0, m_StatusImg, FALSE);
	DrawFormatString(100, 50, GetColor(255, 255, 255), "Solder");
	DrawBox(100, 100, 100 + static_cast<int>(m_pPlayer->GetHPLength()), 150, GetColor(0, 255, 0), TRUE);
	DrawBox(100, 100, 600, 150, GetColor(255, 255, 255), FALSE);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "PlayScene");	// 文字列描画
	m_pPlayer->Draw();
	m_pEnemy->Draw();
}
