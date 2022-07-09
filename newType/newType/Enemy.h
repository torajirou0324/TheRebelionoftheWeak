#pragma once
#include "GameObject.h"

// �X�e�[�g�Ǘ�������\����
enum class STATE
{
	ATTACK_1,
	ATTACK_2,
	IDLE,
	IDLE_BATTLE,
	WALKING,
	DEATH,
	HURT
};

// �G�l�~�[�N���X
class Enemy : public GameObject
{
public:
	Enemy();	// �R���X�g���N�^
	~Enemy();	// �f�X�g���N�^

	void Update()override;		// �X�V����
	void Attack_1();
	void Attack_2();
	void Death();
	void Hurt();
	void Idle();
	void Idle_Battle();
	void Walking();
	void Draw()override;		// �`�揈��

	// �Z�b�^�[
	void SetDamageFlag(const bool& _flag) { m_DamageFlag = _flag; }

	// �Q�b�^�[
	const bool& GetDamageFlag() const { return m_DamageFlag; }
	const bool& GetDeathFlag() const { return m_DeathFlag; }
private:

	STATE m_DragonState;		// �h���S���̍s���X�e�[�g

	unsigned char m_Alpha;		// �����x

	int m_ImgNum;				// ���݂̉摜�ԍ��ۑ��p
	int m_ImgCount;				// �摜�̔ԍ����X�V���邽�߂̃J�E���g�p
	int m_DamageCount;

	int m_DragonAttack1Img[160];	// �h���S���U��1�摜�n���h���̔z��
	int m_DragonAttack2Img[200];	// �h���S���U��2�摜�n���h���̔z��
	int m_DragonDeathImg[300];		// �h���S�����S�摜�n���h���̔z��
	int m_DragonHurtImg[62];				// �h���S����_���摜�n���h���̔z��
	int m_DragonIdleImg[160];				// �h���S���ҋ@�摜�n���h���̔z��
	int m_DragonIdleBattleImg[140];		// �h���S���o�g�����̑ҋ@�摜�n���h���̔z��
	int m_DragonWalkingImg[160];			// �h���S�������摜�n���h���̔z��

	float m_Speed;		// �ړ����x
	float m_HPLength;	
	float m_HP;

	bool m_VecFlag;		// �����t���O
	bool m_DamageFlag;	// ��_���t���O
	bool m_DeathFlag;	// ���S�t���O
};