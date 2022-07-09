#pragma once
#include <vector>
#include "GameObject.h"

enum class TAG
{
	PLAYER,
	ENEMY,
	NUM
};

struct Collision_Tag
{
	GameObject* m_pCollider;
	TAG m_tag;
};

class Collider
{
	std::vector<Collision_Tag>m_pCollisionArray;

public:
	// �R�s�[�֎~
	Collider(const Collider&) = delete;
	Collider& operator=(const Collider&) = delete;

	Collider();		// �R���X�g���N�^
	~Collider();	// �f�X�g���N�^

	bool PCollision();
	bool ECollision();

	void Add(Collision_Tag _CDTag);
};