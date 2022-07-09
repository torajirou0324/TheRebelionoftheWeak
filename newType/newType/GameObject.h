#pragma once

// プレイヤーとエネミーの基底クラス
class GameObject
{
public:
	GameObject(){}
	virtual ~GameObject(){}

	virtual void Update() = 0;
	virtual void Draw() = 0;

	// ゲッター
	const float& GetPosX() const { return m_Pos.x; }
	const float& GetPosY() const { return m_Pos.y; }
protected:
	struct Position // float型のx,y
	{
		float x;
		float y;
	};
	Position m_Pos;				// プレイヤーの座標（x,y）
};