#pragma once
#include "GameObject.h"

// プレイヤークラス
class Player : public GameObject
{
public:
	Player(float _x);	// コンストラクタ
	~Player();	// デストラクタ

	void Update()override;	// 更新処理
	void Draw()override;	// 描画処理

	// セッター
	void SetDamageFlag(const bool& _flag) { m_DamageFlag = _flag; }

	// ゲッター
	const float& GetHPLength() const { return m_HPLength; }
	const bool& GetDamageFlag() const { return m_DamageFlag; }
	const bool& GetAttackFlag() const { return m_AttackFlag; }
private:

	unsigned char m_Alpha;		// 透明度

	int m_PlayerImg[8];			// プレイヤーの画像ハンドル保存配列
	int m_PlayerAttackImg[6];	// プレイヤーの攻撃時の画像ハンドル保存配列
	int m_PotionImg;			// ポーションの画像ハンドル
	int m_ImgNum;				// 現在の画像番号保存用
	int m_ImgCount;				// 画像の番号を更新するためのカウント用
	int m_DamageCount;			// 無敵時間のカウント
	int m_RecoveryCount;		// 回復アイテムのクールタイムカウント

	float m_Speed;		// プレイヤーの移動速度
	float m_VelocityX;	// プレイヤーのX軸の加速度
	float m_VelocityY;	// プレイヤーのY軸の加速度
	float m_HPLength;
	float m_HP;

	bool m_PlayVecFlag;	// プレイヤーが右左どちらを向いているかの判定用
	bool m_JumpFlag;	// プレイヤーが空中にいるかいないかの判定用
	bool m_AttackFlag;	// プレイヤーが攻撃しているかしていないかの判定用
	bool m_DamageFlag;	// プレイヤーがダメージを受けているかいないかの判定用
	bool m_RecoveryFlag;// 回復アイテムが使用できるかの判定用
};
