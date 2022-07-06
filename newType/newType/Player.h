#pragma once

// �v���C���[�N���X
class Player
{
public:
	Player(float _x);	// �R���X�g���N�^
	~Player();	// �f�X�g���N�^

	void Update();	// �X�V����
	void Draw();	// �`�揈��

	// �Q�b�^�[
	const float& GetPosX() const { return m_Pos.x; }
private:
	struct Position // float�^��x,y
	{
		float x;
		float y;
	};
	Position m_Pos;				// �v���C���[�̍��W�ix,y�j

	int m_PlayerImg[8];			// �v���C���[�̉摜�n���h���ۑ��z��
	int m_PlayerAttackImg[6];	// �v���C���[�̍U�����̉摜�n���h���ۑ��z��
	int m_ImgNum;				// ���݂̉摜�ԍ��ۑ��p
	int m_ImgCount;				// �摜�̔ԍ����X�V���邽�߂̃J�E���g�p

	float m_Speed;		// �v���C���[�̈ړ����x
	float m_VelocityX;	// �v���C���[��X���̉����x
	float m_VelocityY;	// �v���C���[��Y���̉����x

	bool m_PlayVecFlag;	// �v���C���[���E���ǂ���������Ă��邩�̔���p
	bool m_JumpFlag;	// �v���C���[���󒆂ɂ��邩���Ȃ����̔���p
	bool m_AttackFlag;	// �v���C���[���U�����Ă��邩���Ă��Ȃ����̔���p
	bool m_DamageFlag;	// �v���C���[���_���[�W���󂯂Ă��邩���Ȃ����̔���p
};