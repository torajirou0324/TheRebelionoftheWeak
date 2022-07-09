#pragma once
#include "GameObject.h"

// ステート管理をする構造体
enum class STATE
{
	ATTACK_1,
	ATTACK_2,
	IDLE,
	IDLE_BATTLE,
	WALKING,
	DEATH,
	HURT
};

// エネミークラス
class Enemy : public GameObject
{
public:
	Enemy();	// コンストラクタ
	~Enemy();	// デストラクタ

	void Update()override;		// 更新処理
	void Attack_1();
	void Attack_2();
	void Death();
	void Hurt();
	void Idle();
	void Idle_Battle();
	void Walking();
	void Draw()override;		// 描画処理

	// セッター
	void SetDamageFlag(const bool& _flag) { m_DamageFlag = _flag; }

	// ゲッター
	const bool& GetDamageFlag() const { return m_DamageFlag; }
	const bool& GetDeathFlag() const { return m_DeathFlag; }
private:

	STATE m_DragonState;		// ドラゴンの行動ステート

	unsigned char m_Alpha;		// 透明度

	int m_ImgNum;				// 現在の画像番号保存用
	int m_ImgCount;				// 画像の番号を更新するためのカウント用
	int m_DamageCount;

	int m_DragonAttack1Img[160];	// ドラゴン攻撃1画像ハンドルの配列
	int m_DragonAttack2Img[200];	// ドラゴン攻撃2画像ハンドルの配列
	int m_DragonDeathImg[300];		// ドラゴン死亡画像ハンドルの配列
	int m_DragonHurtImg[62];				// ドラゴン被ダメ画像ハンドルの配列
	int m_DragonIdleImg[160];				// ドラゴン待機画像ハンドルの配列
	int m_DragonIdleBattleImg[140];		// ドラゴンバトル時の待機画像ハンドルの配列
	int m_DragonWalkingImg[160];			// ドラゴン歩き画像ハンドルの配列

	float m_Speed;		// 移動速度
	float m_HPLength;	
	float m_HP;

	bool m_VecFlag;		// 向きフラグ
	bool m_DamageFlag;	// 被ダメフラグ
	bool m_DeathFlag;	// 死亡フラグ
};