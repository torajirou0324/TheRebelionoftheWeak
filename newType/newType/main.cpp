#include <DxLib.h>
#include "SceneManager.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpCmdLine, int nCmdShow)
{
	// 画面モードの設定
	ChangeWindowMode(TRUE);							// ウィンドウモードで起動
	SetMainWindowText("The Revelion of the weak");	// ウィンドウタイトル
	SetGraphMode(1920, 1080, 16, 60);				// 画面解像度と色数の設定

	// DxLib初期化処理
	if (DxLib_Init() == -1)return -1;

	// グラフィックの描画先を裏画面にセット
	SetDrawScreen(DX_SCREEN_BACK);

	SceneManager* SMG = new SceneManager;

	delete SMG;
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}