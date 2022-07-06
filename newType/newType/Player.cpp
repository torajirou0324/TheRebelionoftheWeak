#include <fstream>
#include <sstream>
#include <DxLib.h>
#include "Player.h"
#include "MapManager.h"
#include "Input.h"

Player::Player(float _x)
	: m_ImgNum(0)
	, m_ImgCount(0)
	, m_Speed(0.0f)
	, m_VelocityX(0.0f)
	, m_VelocityY(0.0f)
	, m_PlayVecFlag(true)
	, m_JumpFlag(false)
	, m_AttackFlag(false)
	, m_DamageFlag(false)
{
	// 文字列を使った読み込み
	for (auto i = 0; i < 8; i++)
	{
		std::stringstream fname;
		fname << "data/Player/" << "soldier" << i << ".png";
		m_PlayerImg[i] = LoadGraph(fname.str().c_str());
	}
	for (auto i = 0; i < 6; i++)
	{
		std::stringstream fname;
		fname << "data/Player/" << "soldier_attck" << i << ".png";
		m_PlayerAttackImg[i] = LoadGraph(fname.str().c_str());
	}
	m_Pos.x = _x;
	m_Pos.y = 720.0f;
}

Player::~Player()
{
}

void Player::Update()
{
	// プレイヤーの移動処理（ジャンプ中・攻撃中・被弾中は移動入力を受け付けない）
	if (m_JumpFlag && !m_AttackFlag && !m_DamageFlag)
	{
		if (Input::IsPressed(LEFT) && Input::NoPressed(RIGHT))	// 左矢印を押したとき
		{
			m_Speed = -1.5f;
			m_ImgCount++;
			m_PlayVecFlag = false;
		}
		if (Input::IsPressed(RIGHT) && Input::NoPressed(LEFT))	// 右矢印を押したとき
		{
			m_Speed = 1.5f;
			m_ImgCount++;
			m_PlayVecFlag = true;
		}
		if (Input::NoPressed(LEFT) && Input::NoPressed(RIGHT)) { m_Speed = 0.0f; m_ImgNum = 0; }	// 左矢印も右矢印も押していないとき
	}
	m_Pos.x += m_Speed; // 移動速度加算
	if (m_Pos.x < 0.0f) { m_Pos.x = 0.0f; }			// 左端めり込まない処理
	if (m_Pos.x > 1790.0f) { m_Pos.x = 1790.0f; }	// 右端めり込まない処理

	// プレイヤーがVを押した時攻撃フラグをTRUEにする
	if (Input::IsPress(V) && !m_AttackFlag)
	{
		m_AttackFlag = true;
		m_ImgNum = 0;
		m_ImgCount = 0;
	}
	if (m_AttackFlag) { m_ImgCount++; if (m_JumpFlag) { m_Speed = 0.0f; } }	// プレイヤーが攻撃中の処理

	// マップとの当たり判定(プレイヤーが地面についているか)
	m_JumpFlag = MapManager::CollisionManager(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y));

	// 地面についているときジャンプを有効にする
	if (Input::IsPress(SPACE) && m_JumpFlag)
	{
		m_VelocityY = -5.5f;
		m_JumpFlag = false;
	}

	// 空中にいるとき
	if (!m_JumpFlag)
	{
		m_Pos.y += m_VelocityY;
		m_VelocityY += 0.1f;
		if (m_VelocityY > 6.0f) { m_VelocityY = 6.0f; }
	}

	// プレイヤーの画像番号を回す処理
	if (m_ImgCount > 20)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (!m_AttackFlag && m_ImgNum > 7) { m_ImgNum = 0; }
		if ( m_AttackFlag && m_ImgNum > 5) { m_ImgNum = 0; m_AttackFlag = false; }
	}
}

void Player::Draw()
{
	if (m_AttackFlag)	// プレイヤーが攻撃中かどうか
	{
		// 攻撃中であるプレイヤーの画像を反転するかしないか
		if (m_PlayVecFlag) { DrawGraphF(m_Pos.x, m_Pos.y, m_PlayerAttackImg[m_ImgNum], TRUE); }
		else { DrawTurnGraphF(m_Pos.x, m_Pos.y, m_PlayerAttackImg[m_ImgNum], TRUE); }
	}
	else
	{
		// 攻撃中でないプレイヤーの画像を反転するかしないか
		if (m_PlayVecFlag) { DrawGraphF(m_Pos.x, m_Pos.y, m_PlayerImg[m_ImgNum], TRUE); }
		else { DrawTurnGraphF(m_Pos.x, m_Pos.y, m_PlayerImg[m_ImgNum], TRUE); }
	}
}
