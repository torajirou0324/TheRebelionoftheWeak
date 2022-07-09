#pragma once
#include "GameObject.h"

// �v���C���[�N���X
class Player : public GameObject
{
public:
	Player(float _x);	// �R���X�g���N�^
	~Player();	// �f�X�g���N�^

	void Update()override;	// �X�V����
	void Draw()override;	// �`�揈��

	// �Z�b�^�[
	void SetDamageFlag(const bool& _flag) { m_DamageFlag = _flag; }

	// �Q�b�^�[
	const float& GetHPLength() const { return m_HPLength; }
	const bool& GetDamageFlag() const { return m_DamageFlag; }
	const bool& GetAttackFlag() const { return m_AttackFlag; }
private:

	unsigned char m_Alpha;		// �����x

	int m_PlayerImg[8];			// �v���C���[�̉摜�n���h���ۑ��z��
	int m_PlayerAttackImg[6];	// �v���C���[�̍U�����̉摜�n���h���ۑ��z��
	int m_PotionImg;			// �|�[�V�����̉摜�n���h��
	int m_ImgNum;				// ���݂̉摜�ԍ��ۑ��p
	int m_ImgCount;				// �摜�̔ԍ����X�V���邽�߂̃J�E���g�p
	int m_DamageCount;			// ���G���Ԃ̃J�E���g
	int m_RecoveryCount;		// �񕜃A�C�e���̃N�[���^�C���J�E���g

	float m_Speed;		// �v���C���[�̈ړ����x
	float m_VelocityX;	// �v���C���[��X���̉����x
	float m_VelocityY;	// �v���C���[��Y���̉����x
	float m_HPLength;
	float m_HP;

	bool m_PlayVecFlag;	// �v���C���[���E���ǂ���������Ă��邩�̔���p
	bool m_JumpFlag;	// �v���C���[���󒆂ɂ��邩���Ȃ����̔���p
	bool m_AttackFlag;	// �v���C���[���U�����Ă��邩���Ă��Ȃ����̔���p
	bool m_DamageFlag;	// �v���C���[���_���[�W���󂯂Ă��邩���Ȃ����̔���p
	bool m_RecoveryFlag;// �񕜃A�C�e�����g�p�ł��邩�̔���p
};
