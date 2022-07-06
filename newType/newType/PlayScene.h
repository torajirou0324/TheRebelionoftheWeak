#pragma once
#include "SceneBase.h"

class Player;
class Enemy;

class PlayScene : public SceneBase
{
public:
	PlayScene();
	~PlayScene()override;

	TAG_SCENE Update()override;
	void Draw()override;
private:
	Player* m_pPlayer;	// �v���C���[�̃|�C���^
	Enemy* m_pEnemy;	// �G�l�~�[�̃|�C���^

	int m_StatusImg;	// �X�e�[�^�X�\���̘g�摜�n���h��
};