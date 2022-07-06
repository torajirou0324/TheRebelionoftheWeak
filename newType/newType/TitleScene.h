#pragma once
#include "SceneBase.h"

class Player;

class TitleScene : public SceneBase
{
public:
	TitleScene();			// �R���X�g���N�^
	~TitleScene()override;	// �f�X�g���N�^

	TAG_SCENE Update()override;	// �X�V����
	void Draw()override;		// �`�揈��

private:
	Player* m_pPlayer;		// �v���C���[�N���X�̃|�C���^

	int m_BackGroundImg;	// �t�F�[�h�A�E�g�p�摜�n���h��
	int m_ArrowImg;			
	int m_AlphaNum;			// �A���t�@�l

	bool m_AlphaFlag;		// �A���t�@�t���O
};