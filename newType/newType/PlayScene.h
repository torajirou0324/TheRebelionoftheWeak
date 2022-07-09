#pragma once
#include "SceneBase.h"

class Player;
class Enemy;
class Collider;

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene()override;

	TAG_SCENE Update()override;	// �X�V����
	void Draw()override;		// �`�揈��
private:
	Player* m_pPlayer;		// �v���C���[�̃|�C���^
	Enemy* m_pEnemy;		// �G�l�~�[�̃|�C���^
	Collider* m_pCollider;	// �R���C�_�[�|�C���^

	int m_StatusImg;	// �X�e�[�^�X�\���̘g�摜�n���h��
};