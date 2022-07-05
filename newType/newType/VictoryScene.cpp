#include <DxLib.h>
#include "VictoryScene.h"
#include "Input.h"

VictoryScene::VictoryScene()
{
}

VictoryScene::~VictoryScene()
{
}

TAG_SCENE VictoryScene::Update()
{
	if (Input::IsPress(SPACE))
	{
		return TAG_SCENE::TAG_OVER;
	}
	return TAG_SCENE::TAG_NONE;
}

void VictoryScene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "VictoryScene");
}
