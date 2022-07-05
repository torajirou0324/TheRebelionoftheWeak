#include <DxLib.h>
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// ��ʃ��[�h�̐ݒ�
	ChangeWindowMode(TRUE);							// �E�B���h�E���[�h�ŋN��
	SetMainWindowText("The Revelion of the weak");	// �E�B���h�E�^�C�g��
	SetGraphMode(1920, 1080, 16, 60);				// ��ʉ𑜓x�ƐF���̐ݒ�

	// DxLib����������
	if (DxLib_Init() == -1)return -1;

	// �O���t�B�b�N�̕`���𗠉�ʂɃZ�b�g
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager* SMG = new SceneManager;

	delete SMG;
	DxLib_End(); // DX���C�u�����I������
	return 0;
}