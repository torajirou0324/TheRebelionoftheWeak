#include <fstream>
#include <sstream>
#include <DxLib.h>
#include "Enemy.h"

Enemy::Enemy()
	: m_ImgNum(0)
	, m_ImgCount(0)
	, m_Speed(0.0f)
{
	// •¶š—ñ‚ğg‚Á‚½“Ç‚İ‚İ
	std::string str = "";
	int num = 0;
	for (auto i = 0; i < 160; i++)
	{
		std::stringstream fname;
		if (i < 10) { str = "00"; }
		else if (i < 100) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Attack_1/" << str << i + 1 << ".png";
		if (i % 2 == 0) { m_DragonAttack1Img[num] = LoadGraph(fname.str().c_str()); num++; }
	}
	num = 0;
	for (auto i = 0; i < 200; i++)
	{
		std::stringstream fname;
		if (i < 10) { str = "00"; }
		else if (i < 100) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Attack_2/" << str << i + 1 << ".png";
		if (i % 2 == 0) { m_DragonAttack2Img[num] = LoadGraph(fname.str().c_str()); num++; }
	}
	num = 0;
	for (auto i = 1; i <= 300; i++)
	{
		std::stringstream fname;
		if (i < 10) { str = "00"; }
		else if (i < 100) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Death/" << str << i << ".png";
		if (i % 3 == 0 || i == 1) { m_DragonDeathImg[num] = LoadGraph(fname.str().c_str()); num++; }
	}
	for (auto i = 1; i <= 62;i++)
	{
		std::stringstream fname;
		if (i < 10) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Hurt/" << str << i << ".png";
		m_DragonHurtImg[i -1] = LoadGraph(fname.str().c_str());
	}
	num = 0;
	for (auto i = 0; i < 160; i++)
	{
		std::stringstream fname;
		if (i < 10) { str = "00"; }
		else if (i < 100) { str = "0"; }
		else { str = ""; }
		fname << "data/Enemy/Dragon/Idle/" << str << i + 1 << ".png";
		if (i % 2 == 0) { m_DragonIdleImg[num] = LoadGraph(fname.str().c_str()); num++; }
	}

	m_Pos.x = 800.0f;
	m_Pos.y = 280.0f;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	m_ImgCount++;
	if (m_ImgCount > 20)
	{
		m_ImgNum++;
		m_ImgCount = 0;
		if (m_ImgNum > 99)
		{
			m_ImgNum = 0;
		}
	}

}

void Enemy::Draw()
{
	DrawExtendGraph(m_Pos.x, m_Pos.y, m_Pos.x + 1450.0f, m_Pos.y + 910.0f, m_DragonIdleImg[m_ImgNum], TRUE);
}
