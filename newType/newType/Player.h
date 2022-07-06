#pragma once

// プレイヤークラス
class Player
{
public:
	Player(float _x);	// コンストラクタ
	~Player();	// デストラクタ

	void Update();	// 更新処理
	void Draw();	// 描画処理

	// ゲッター
	const float& GetPosX() const { return m_Pos.x; }
private:
	struct Position // float型のx,y
	{
		float x;
		float y;
	};
	Position m_Pos;				// プレイヤーの座標（x,y）

	int m_PlayerImg[8];			// プレイヤーの画像ハンドル保存配列
	int m_PlayerAttackImg[6];	// プレイヤーの攻撃時の画像ハンドル保存配列
	int m_ImgNum;				// 現在の画像番号保存用
	int m_ImgCount;				// 画像の番号を更新するためのカウント用

	float m_Speed;		// プレイヤーの移動速度
	float m_VelocityX;	// プレイヤーのX軸の加速度
	float m_VelocityY;	// プレイヤーのY軸の加速度

	bool m_PlayVecFlag;	// プレイヤーが右左どちらを向いているかの判定用
	bool m_JumpFlag;	// プレイヤーが空中にいるかいないかの判定用
	bool m_AttackFlag;	// プレイヤーが攻撃しているかしていないかの判定用
	bool m_DamageFlag;	// プレイヤーがダメージを受けているかいないかの判定用
};