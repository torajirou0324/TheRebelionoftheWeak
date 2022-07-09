#pragma once

// �v���C���[�ƃG�l�~�[�̊��N���X
class GameObject
{
public:
	GameObject(){}
	virtual ~GameObject(){}

	virtual void Update() = 0;
	virtual void Draw() = 0;

	// �Q�b�^�[
	const float& GetPosX() const { return m_Pos.x; }
	const float& GetPosY() const { return m_Pos.y; }
protected:
	struct Position // float�^��x,y
	{
		float x;
		float y;
	};
	Position m_Pos;				// �v���C���[�̍��W�ix,y�j
};