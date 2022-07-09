#include "Collider.h"

Collider::Collider()
{
}

Collider::~Collider()
{
	m_pCollisionArray.clear();
}

bool Collider::PCollision()
{
	auto PlayerX = m_pCollisionArray[0].m_pCollider->GetPosX();
	auto PlayerY = m_pCollisionArray[0].m_pCollider->GetPosY();
	auto EnemyX = m_pCollisionArray[1].m_pCollider->GetPosX();
	auto EnemyY = m_pCollisionArray[1].m_pCollider->GetPosY();

	if(((PlayerX > EnemyX + 600.0f && PlayerX < EnemyX + 1450.0f) || (EnemyX + 600.0f > PlayerX && EnemyX + 600.0f < PlayerX + 150.0f)) &&
		((PlayerY > EnemyY + 200.0f && PlayerY < EnemyY + 910.0f) || (EnemyY + 200.0f > PlayerY && EnemyY + 200.0f < PlayerY + 180.0f)))
	{
		return true;
	}
	return false;
}

bool Collider::ECollision()
{
	auto PlayerX = m_pCollisionArray[0].m_pCollider->GetPosX();
	auto PlayerY = m_pCollisionArray[0].m_pCollider->GetPosY();
	auto EnemyX = m_pCollisionArray[1].m_pCollider->GetPosX();
	auto EnemyY = m_pCollisionArray[1].m_pCollider->GetPosY();

	if (((PlayerX + 150.0f > EnemyX + 500.0f && PlayerX + 150.0f < EnemyX + 1450.0f) || (EnemyX + 500.0f > PlayerX + 150.0f && EnemyX + 500.0f < PlayerX + 200.0f)) &&
		((PlayerY > EnemyY + 300.0f && PlayerY < EnemyY + 910.0f) || (EnemyY + 300.0f > PlayerY && EnemyY + 300.0f < PlayerY + 130.0f)))
	{
		return true;
	}
	return false;
}

void Collider::Add(Collision_Tag _CDTag)
{
	m_pCollisionArray.push_back(_CDTag);
}
