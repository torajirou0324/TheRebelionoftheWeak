#include <DxLib.h>
#include "PlayScene.h"
#include "Player.h"
#include "Enemy.h"
#include "MapManager.h"
#include "Input.h"

PlayScene::PlayScene()
	: m_StatusImg(LoadGraph("data/BackGround/StatusImg.png"))
{
	m_pPlayer = new Player(0.0f);
	m_pEnemy = new Enemy;
}

PlayScene::~PlayScene()
{
	delete m_pPlayer;
	delete m_pEnemy;
}

TAG_SCENE PlayScene::Update()
{
	m_pPlayer->Update();
	m_pEnemy->Update();
	return TAG_SCENE::TAG_NONE;
}

void PlayScene::Draw()
{
	MapManager::Draw();
	DrawGraph(0, 0, m_StatusImg, FALSE);
	DrawFormatString(0, 0, GetColor(255, 255, 255), "PlayScene");	// •¶Žš—ñ•`‰æ
	m_pPlayer->Draw();
	m_pEnemy->Draw();
}
