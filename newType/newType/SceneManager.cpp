#include <DxLib.h>
#include "SceneManager.h"
#include "SceneBase.h"
#include "TitleScene.h"
#include "PlayScene.h"
#include "VictoryScene.h"
#include "DefeatScene.h"
#include "Input.h"

SceneManager::SceneManager()
{
	CreateScene(TAG_SCENE::TAG_TITLE);	// ���݂̃V�[�����^�C�g���ŏ�����
	GameLoop();							// �Q�[���V�[�������[�v����֐���
}

SceneManager::~SceneManager()
{
	if (m_pNowScene != nullptr) { delete m_pNowScene; }	// �������
}

void SceneManager::GameLoop()
{
	Input::CreateInstance();			// ���͊֌W�N���X�̐���
	while (!Input::IsPress(ESCAPE))	// ESCAPE�L�[�������Ƌ����I��
	{
		Input::Update();
		ClearDrawScreen();
		auto tag = m_pNowScene->Update();	// ���݂̃V�[���̍X�V����
		m_pNowScene->Draw();				// ���݂̃V�[���̕`�揈��
		ScreenFlip();
		if (tag == TAG_SCENE::TAG_NONE)		// ���̃V�[���̃^�O���Ԃ��Ă���܂Ō��݂̃V�[���̏����𑱂���
		{
			continue;
		}
		ClearScene();		// ���݂̃V�[�������
		CreateScene(tag);	// ���̃V�[���𐶐�
	}
	Input::DeleteInstance();// ���͊֌W�N���X�̉��
}

void SceneManager::CreateScene(TAG_SCENE tag)
{
	switch (tag)
	{
	case TAG_SCENE::TAG_TITLE:
		m_pNowScene = new TitleScene;	// �^�C�g���V�[���𐶐�
		break;
	case TAG_SCENE::TAG_PLAY:
		m_pNowScene = new PlayScene;	// �v���C�V�[���𐶐�
		break;
	case TAG_SCENE::TAG_CLEAR:
		m_pNowScene = new VictoryScene;	// �����V�[���𐶐�
		break;
	case TAG_SCENE::TAG_OVER:
		m_pNowScene = new DefeatScene;	// �s�k�V�[���𐶐�
		break;
	case TAG_SCENE::TAG_NONE:			// ��̃V�[��
		break;
	default:
		break;
	}
}

void SceneManager::ClearScene()
{
	if (m_pNowScene == nullptr)
	{

	}
	else
	{
		delete m_pNowScene;
		m_pNowScene = nullptr;
	}
}
