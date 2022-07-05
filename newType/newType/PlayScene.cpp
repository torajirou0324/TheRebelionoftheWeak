#include <DxLib.h>
#include "PlayScene.h"
#include "Input.h"

PlayScene::PlayScene()
{
}

PlayScene::~PlayScene()
{
}

TAG_SCENE PlayScene::Update()
{
	if (Input::IsPress(SPACE))
	{
		return TAG_SCENE::TAG_CLEAR;
	}
	return TAG_SCENE::TAG_NONE;
}

void PlayScene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "PlayScene");
}
