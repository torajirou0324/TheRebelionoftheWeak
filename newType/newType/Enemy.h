#pragma once

class Enemy
{
public:
	Enemy();	// コンストラクタ
	~Enemy();	// デストラクタ

	void Update();
	void Draw();

private:
	struct Position
	{
		float x;
		float y;
	};
	Position m_Pos;				// プレイヤーの座標（x,y）
	int m_ImgNum;				// 現在の画像番号保存用
	int m_ImgCount;				// 画像の番号を更新するためのカウント用

	int m_DragonAttack1Img[80];	// ドラゴン攻撃1画像ハンドルの配列
	int m_DragonAttack2Img[100];	// ドラゴン攻撃2画像ハンドルの配列
	int m_DragonDeathImg[100];		// ドラゴン死亡画像ハンドルの配列
	int m_DragonHurtImg[62];				// ドラゴン被ダメ画像ハンドルの配列
	int m_DragonIdleImg[80];				// ドラゴン待機画像ハンドルの配列
	//int m_IdleBattleImg[140];		// ドラゴンバトル時の待機画像ハンドルの配列
	//int m_WalkingImg[161];			// ドラゴン歩き画像ハンドルの配列

	float m_Speed;		// 移動速度
};