#pragma once
#include "SceneBase.h"

class VictoryScene : public SceneBase
{
public:
	VictoryScene();
	~VictoryScene()override;

	TAG_SCENE Update()override;
	void Draw()override;
};