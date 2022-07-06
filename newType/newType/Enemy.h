#pragma once

class Enemy
{
public:
	Enemy();	// �R���X�g���N�^
	~Enemy();	// �f�X�g���N�^

	void Update();
	void Draw();

private:
	struct Position
	{
		float x;
		float y;
	};
	Position m_Pos;				// �v���C���[�̍��W�ix,y�j
	int m_ImgNum;				// ���݂̉摜�ԍ��ۑ��p
	int m_ImgCount;				// �摜�̔ԍ����X�V���邽�߂̃J�E���g�p

	int m_DragonAttack1Img[80];	// �h���S���U��1�摜�n���h���̔z��
	int m_DragonAttack2Img[100];	// �h���S���U��2�摜�n���h���̔z��
	int m_DragonDeathImg[100];		// �h���S�����S�摜�n���h���̔z��
	int m_DragonHurtImg[62];				// �h���S����_���摜�n���h���̔z��
	int m_DragonIdleImg[80];				// �h���S���ҋ@�摜�n���h���̔z��
	//int m_IdleBattleImg[140];		// �h���S���o�g�����̑ҋ@�摜�n���h���̔z��
	//int m_WalkingImg[161];			// �h���S�������摜�n���h���̔z��

	float m_Speed;		// �ړ����x
};