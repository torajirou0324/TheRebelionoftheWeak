#pragma once
#pragma warning(disable:26812)
#include <DxLib.h>
#include <vector>

enum TYPE
{
	ESCAPE,
	SPACE,
	LEFT,
	RIGHT,
	V,
	NUM
};

class Input
{
	static Input* m_pInput;
	struct key
	{
		int pressCount;
	};
	std::vector<key> keyNum;
public:
	// �R�s�[�֎~
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;

	Input();
	~Input();

	static void CreateInstance();	// Inpput�N���X�𐶐�

	static void DeleteInstance();	// m_pInput�N���X��j��

	static bool IsPress(TYPE t)		// �������u��
	{
		if (m_pInput->keyNum[t].pressCount == 1) { return true; }
		else { return false; }
	}
	static bool IsPressed(TYPE t)	// �����Ă��鎞
	{
		if (m_pInput->keyNum[t].pressCount > 1) { return true; }
		else { return false; }
	}
	static bool NoPress(TYPE t)		// �������u��
	{
		if (m_pInput->keyNum[t].pressCount == 0) { return true; }
		else { return false; }
	}
	static bool NoPressed(TYPE t)	// �����Ă��鎞
	{
		if (m_pInput->keyNum[t].pressCount < 0) { return true; }
		else { return false; }
	}

	static void Update()	// �X�V����
	{
		// ESCAPE�L�[
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { m_pInput->keyNum[ESCAPE].pressCount = max(++m_pInput->keyNum[ESCAPE].pressCount, 1); }
		else { m_pInput->keyNum[ESCAPE].pressCount = min(--m_pInput->keyNum[ESCAPE].pressCount, 0); }
		// SPACE�L�[
		if (CheckHitKey(KEY_INPUT_SPACE)) { m_pInput->keyNum[SPACE].pressCount = max(++m_pInput->keyNum[SPACE].pressCount, 1); }
		else { m_pInput->keyNum[SPACE].pressCount = min(--m_pInput->keyNum[SPACE].pressCount, 0); }
		// LEFT�L�[
		if (CheckHitKey(KEY_INPUT_LEFT)) { m_pInput->keyNum[LEFT].pressCount = max(++m_pInput->keyNum[LEFT].pressCount, 1); }
		else { m_pInput->keyNum[LEFT].pressCount = min(--m_pInput->keyNum[LEFT].pressCount, 0); }
		// RIGHT�L�[
		if (CheckHitKey(KEY_INPUT_RIGHT)) { m_pInput->keyNum[RIGHT].pressCount = max(++m_pInput->keyNum[RIGHT].pressCount, 1); }
		else { m_pInput->keyNum[RIGHT].pressCount = min(--m_pInput->keyNum[RIGHT].pressCount, 0); }
		// V�L�[
		if (CheckHitKey(KEY_INPUT_V)) { m_pInput->keyNum[V].pressCount = max(++m_pInput->keyNum[V].pressCount, 1); }
		else { m_pInput->keyNum[V].pressCount = min(--m_pInput->keyNum[V].pressCount, 0); }
	}
};
