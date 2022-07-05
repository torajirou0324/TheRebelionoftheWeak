#pragma once
class SceneBase;
enum class TAG_SCENE;

// �V�[�����Ǘ�����N���X
class SceneManager
{
public:
	SceneManager();	// �R���X�g���N�^
	~SceneManager();// �f�X�g���N�^

	void GameLoop();	// �V�[�����[�v�֐�

	void CreateScene(TAG_SCENE tag);	// �V�[���𐶐�
	void ClearScene();					// �V�[����j��

private:
	SceneBase* m_pNowScene;		// ���݂̃V�[��
};