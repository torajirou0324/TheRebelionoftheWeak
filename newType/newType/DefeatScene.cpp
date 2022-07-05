#include <DxLib.h>
#include "DefeatScene.h"
#include "Input.h"

DefeatScene::DefeatScene()
{
}

DefeatScene::~DefeatScene()
{
}

TAG_SCENE DefeatScene::Update()
{
	if (Input::IsPress(SPACE))
	{
		return TAG_SCENE::TAG_TITLE;
	}
	return TAG_SCENE::TAG_NONE;
}

void DefeatScene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), "DefeatScene");
}
