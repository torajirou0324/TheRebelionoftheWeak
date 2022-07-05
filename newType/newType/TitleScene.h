#pragma once
#include "SceneBase.h"

class TitleScene : public SceneBase
{
public:
	TitleScene();
	~TitleScene()override;

	TAG_SCENE Update()override;
	void Draw()override;

private:
	int m_BackGroundImg;
	int m_ArrowImg;
};