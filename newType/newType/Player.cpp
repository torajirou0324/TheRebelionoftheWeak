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
	// ��������g�����ǂݍ���
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
	// �v���C���[�̈ړ������i�W�����v���E�U�����E��e���͈ړ����͂��󂯕t���Ȃ��j
	if (m_JumpFlag && !m_AttackFlag && !m_DamageFlag)
	{
		if (Input::IsPressed(LEFT) && Input::NoPressed(RIGHT))	// �������������Ƃ�
		{
			m_Speed = -1.5f;
			m_ImgCount++;
			m_PlayVecFlag = false;
		}
		if (Input::IsPressed(RIGHT) && Input::NoPressed(LEFT))	// �E�����������Ƃ�
		{
			m_Speed = 1.5f;
			m_ImgCount++;
			m_PlayVecFlag = true;
		}
		if (Input::NoPressed(LEFT) && Input::NoPressed(RIGHT)) { m_Speed = 0.0f; m_ImgNum = 0; }	// �������E���������Ă��Ȃ��Ƃ�
	}
	m_Pos.x += m_Speed; // �ړ����x���Z
	if (m_Pos.x < 0.0f) { m_Pos.x = 0.0f; }			// ���[�߂荞�܂Ȃ�����
	if (m_Pos.x > 1790.0f) { m_Pos.x = 1790.0f; }	// �E�[�߂荞�܂Ȃ�����

	// �v���C���[��V�����������U���t���O��TRUE�ɂ���
	if (Input::IsPress(V) && !m_AttackFlag)
	{
		m_AttackFlag = true;
		m_ImgNum = 0;
		m_ImgCount = 0;
	}
	if (m_AttackFlag) { m_ImgCount++; if (m_JumpFlag) { m_Speed = 0.0f; } }	// �v���C���[���U�����̏���

	// �}�b�v�Ƃ̓����蔻��(�v���C���[���n�ʂɂ��Ă��邩)
	m_JumpFlag = MapManager::CollisionManager(static_cast<int>(m_Pos.x), static_cast<int>(m_Pos.y));

	// �n�ʂɂ��Ă���Ƃ��W�����v��L���ɂ���
	if (Input::IsPress(SPACE) && m_JumpFlag)
	{
		m_VelocityY = -5.5f;
		m_JumpFlag = false;
	}

	// �󒆂ɂ���Ƃ�
	if (!m_JumpFlag)
	{
		m_Pos.y += m_VelocityY;
		m_VelocityY += 0.1f;
		if (m_VelocityY > 6.0f) { m_VelocityY = 6.0f; }
	}

	// �v���C���[�̉摜�ԍ����񂷏���
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
	if (m_AttackFlag)	// �v���C���[���U�������ǂ���
	{
		// �U�����ł���v���C���[�̉摜�𔽓]���邩���Ȃ���
		if (m_PlayVecFlag) { DrawGraphF(m_Pos.x, m_Pos.y, m_PlayerAttackImg[m_ImgNum], TRUE); }
		else { DrawTurnGraphF(m_Pos.x, m_Pos.y, m_PlayerAttackImg[m_ImgNum], TRUE); }
	}
	else
	{
		// �U�����łȂ��v���C���[�̉摜�𔽓]���邩���Ȃ���
		if (m_PlayVecFlag) { DrawGraphF(m_Pos.x, m_Pos.y, m_PlayerImg[m_ImgNum], TRUE); }
		else { DrawTurnGraphF(m_Pos.x, m_Pos.y, m_PlayerImg[m_ImgNum], TRUE); }
	}
}
