#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <DxLib.h>
#include "Enemy.h"

const float HP_MAX = 100.0f;	// HPの最大値

Enemy::Enemy()
	: m_ImgNum(1)
	, m_Alpha(255)
	, m_ImgCount(0)
	, m_HP(HP_MAX)
	, m_DamageCount(0)
	, m_Speed(0.0f)
	, m_HPLength(500.0f)
	, m_VecFlag(true)
	, m_DamageFlag(false)
	, m_DeathFlag(false)
{
	// 文字列を使った読み込み
	std::string str = "";
	int num = 0;
	for (auto i = 1; i <= 160; i++)
	{
		std::stringstream fname, ffname, fffname;
		if (i < 10) { str = "00"; }
		else if (i < 100) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Attack_1/" << str << i << ".png";
/*		if (i % 2 == 0) {*/ m_DragonAttack1Img[i] = LoadGraph(fname.str().c_str());
		ffname << "data/Enemy/Dragon/Idle/" << str << i << ".png";
/*		if (i % 2 == 0) {*/ m_DragonIdleImg[i] = LoadGraph(ffname.str().c_str());
		fffname << "data/Enemy/Dragon/Walking/" << str << i << ".png";
	/*	if (i % 2 == 0) {*/ m_DragonWalkingImg[i - 1] = LoadGraph(fffname.str().c_str()); /*num++; }*/
	}
	for (auto i = 1; i <= 200; i++)
	{
		std::stringstream fname, ffname;
		if (i < 10) { str = "00"; }
		else if (i < 100) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Attack_2/" << str << i << ".png";
		m_DragonAttack2Img[i - 1] = LoadGraph(fname.str().c_str());
		//if (i * 3 < 10) { str = "00"; }
		//else if (i * 3 < 100) { str = "0"; }
		//else { str = ""; }
		//ffname << "data/Enemy/Dragon/Death/" << str << i << ".png";
		//m_DragonDeathImg[i - 1] = LoadGraph(ffname.str().c_str());
	}
	for (auto i = 1; i <= 300; i++)
	{
		std::stringstream fname;
		if (i < 10) { str = "00"; }
		else if (i < 100) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Death/" << str << i << ".png";
		m_DragonDeathImg[i - 1] = LoadGraph(fname.str().c_str());

	}
	for (auto i = 1; i <= 62;i++)
	{
		std::stringstream fname;
		if (i < 10) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Hurt/" << str << i << ".png";
		m_DragonHurtImg[i -1] = LoadGraph(fname.str().c_str());
	}
	for (auto i = 1; i <= 140; i++)
	{
		std::stringstream fname;
		if (i < 10) { str = "00"; }
		else if (i < 100) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Idle_Battle/" << str << i << ".png";
		m_DragonIdleBattleImg[i - 1] = LoadGraph(fname.str().c_str());
	}

	m_Pos.x = 800.0f;
	m_Pos.y = 280.0f;

	m_DragonState = STATE::IDLE;
}

Enemy::~Enemy()
{
	//for()
	//DeleteGraph(m_DragonAttack1Img[])
}

void Enemy::Update()
{
	if (m_ImgNum == 0) { m_DragonState = static_cast<STATE>(rand() % 5); m_ImgNum = 1; }	// ステートを乱数で決める
	switch (m_DragonState)
	{
	case STATE::ATTACK_1:
		Attack_1();
		break;
	case STATE::ATTACK_2:
		Attack_2();
		break;
	case STATE::DEATH:
		Death();
		break;
	case STATE::HURT:
		Hurt();
		break;
	case STATE::IDLE:
		Idle();
		break;
	case STATE::IDLE_BATTLE:
		Idle_Battle();
		break;
	case STATE::WALKING:
		Walking();
		break;
	default:
		break;
	}
	// ダメージ処理
	if (m_DamageFlag && m_DamageCount == 0) 
	{ 
		m_Alpha = 180;
		if (m_HP > 0.0f) { m_HP -= 5; }
		if (m_HP == 0.0f) { m_DeathFlag = true; }
	}
	if (m_DamageFlag)
	{
		m_DamageCount++;
	}

	if (m_DamageCount > 300) { m_DamageFlag = false; m_DamageCount = 0; m_Alpha = 255; }	// 無敵時間が終わる処理

	if (m_Pos.x > 1000.0f) { m_VecFlag = true; }
	if (m_Pos.x < 200.0f) { m_VecFlag = false; }

	// HPゲージ処理
	auto magnification = m_HP / HP_MAX;
	m_HPLength = 500.0f * magnification;
}

void Enemy::Attack_1()
{
	m_ImgCount++;
	if (m_ImgCount > 5)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (m_ImgNum > 159)
		{
			m_ImgNum = 0;
		}
	}
}

void Enemy::Attack_2()
{
	m_ImgCount++;
	if (m_ImgCount > 5)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (m_ImgNum > 199)
		{
			m_ImgNum = 0;
		}
	}
}

void Enemy::Death()
{
	m_ImgCount++;
	if (m_ImgCount > 4)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (m_ImgNum > 299)
		{
			m_ImgNum = 0;
		}
	}
}

void Enemy::Hurt()
{
	m_ImgCount++;
	if (m_ImgCount > 15)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (m_ImgNum > 61)
		{
			m_ImgNum = 0;
		}
	}
}

void Enemy::Idle()
{
	m_ImgCount++;
	if (m_ImgCount > 5)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (m_ImgNum > 159)
		{
			m_ImgNum = 0;
		}
	}
}

void Enemy::Idle_Battle()
{
	m_ImgCount++;
	if (m_ImgCount > 5)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (m_ImgNum > 139)
		{
			m_ImgNum = 0;
		}
	}
}

void Enemy::Walking()
{
	if(m_VecFlag){ m_Pos.x -= 0.5f; }
	else { m_Pos.x += 0.5f; }


	m_ImgCount++;
	if (m_ImgCount > 5)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (m_ImgNum > 159)
		{
			m_ImgNum = 0;
		}
	}
}

void Enemy::Draw()
{
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, m_Alpha);
	switch (m_DragonState)
	{
	case STATE::ATTACK_1:
		DrawExtendGraph(m_Pos.x, m_Pos.y, m_Pos.x + 1450.0f, m_Pos.y + 910.0f, m_DragonAttack1Img[m_ImgNum], TRUE);
		break;
	case STATE::ATTACK_2:
		DrawExtendGraph(m_Pos.x, m_Pos.y, m_Pos.x + 1450.0f, m_Pos.y + 910.0f, m_DragonAttack2Img[m_ImgNum], TRUE);
		break;
	case STATE::DEATH:
		DrawExtendGraph(m_Pos.x, m_Pos.y, m_Pos.x + 1450.0f, m_Pos.y + 910.0f, m_DragonDeathImg[m_ImgNum], TRUE);
		break;
	case STATE::HURT:
		DrawExtendGraph(m_Pos.x, m_Pos.y, m_Pos.x + 1450.0f, m_Pos.y + 910.0f, m_DragonHurtImg[m_ImgNum], TRUE);
		break;
	case STATE::IDLE:
		DrawExtendGraph(m_Pos.x, m_Pos.y, m_Pos.x + 1450.0f, m_Pos.y + 910.0f, m_DragonIdleImg[m_ImgNum], TRUE);
		break;
	case STATE::IDLE_BATTLE:
		DrawExtendGraph(m_Pos.x, m_Pos.y, m_Pos.x + 1450.0f, m_Pos.y + 910.0f, m_DragonIdleBattleImg[m_ImgNum], TRUE);
		break;
	case STATE::WALKING:
		DrawExtendGraph(m_Pos.x, m_Pos.y, m_Pos.x + 1450.0f, m_Pos.y + 910.0f, m_DragonWalkingImg[m_ImgNum], TRUE);
		break;
	default:
		break;
	}
	DrawFormatString(1300, 50, GetColor(255, 255, 255), "Dragon");
	DrawBox(1300, 100, 1300 + static_cast<int>(m_HPLength), 150, GetColor(255, 0, 0), TRUE);
	DrawBox(1300, 100, 1800, 150, GetColor(255, 255, 255), FALSE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
}
