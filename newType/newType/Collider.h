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
	// コピー禁止
	Collider(const Collider&) = delete;
	Collider& operator=(const Collider&) = delete;

	Collider();		// コンストラクタ
	~Collider();	// デストラクタ

	bool PCollision();
	bool ECollision();

	void Add(Collision_Tag _CDTag);
};