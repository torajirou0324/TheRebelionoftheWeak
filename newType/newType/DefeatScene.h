#pragma once
#include "SceneBase.h"

class DefeatScene : public SceneBase
{
public:
	DefeatScene();
	~DefeatScene()override;

	TAG_SCENE Update()override;
	void Draw()override;
};