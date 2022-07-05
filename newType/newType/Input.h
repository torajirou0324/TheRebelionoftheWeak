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
	// コピー禁止
	Input(const Input&) = delete;
	Input& operator=(const Input&) = delete;

	Input();
	~Input();

	static void CreateInstance();	// Inpputクラスを生成

	static void DeleteInstance();	// m_pInputクラスを破壊

	static bool IsPress(TYPE t)		// 押した瞬間
	{
		if (m_pInput->keyNum[t].pressCount == 1) { return true; }
		else { return false; }
	}
	static bool IsPressed(TYPE t)	// 押している時
	{
		if (m_pInput->keyNum[t].pressCount > 1) { return true; }
		else { return false; }
	}
	static bool NoPress(TYPE t)		// 離した瞬間
	{
		if (m_pInput->keyNum[t].pressCount == 0) { return true; }
		else { return false; }
	}
	static bool NoPressed(TYPE t)	// 離している時
	{
		if (m_pInput->keyNum[t].pressCount < 0) { return true; }
		else { return false; }
	}

	static void Update()	// 更新処理
	{
		// ESCAPEキー
		if (CheckHitKey(KEY_INPUT_ESCAPE)) { m_pInput->keyNum[ESCAPE].pressCount = max(++m_pInput->keyNum[ESCAPE].pressCount, 1); }
		else { m_pInput->keyNum[ESCAPE].pressCount = min(--m_pInput->keyNum[ESCAPE].pressCount, 0); }
		// SPACEキー
		if (CheckHitKey(KEY_INPUT_SPACE)) { m_pInput->keyNum[SPACE].pressCount = max(++m_pInput->keyNum[SPACE].pressCount, 1); }
		else { m_pInput->keyNum[SPACE].pressCount = min(--m_pInput->keyNum[SPACE].pressCount, 0); }
		// LEFTキー
		if (CheckHitKey(KEY_INPUT_LEFT)) { m_pInput->keyNum[LEFT].pressCount = max(++m_pInput->keyNum[LEFT].pressCount, 1); }
		else { m_pInput->keyNum[LEFT].pressCount = min(--m_pInput->keyNum[LEFT].pressCount, 0); }
		// RIGHTキー
		if (CheckHitKey(KEY_INPUT_RIGHT)) { m_pInput->keyNum[RIGHT].pressCount = max(++m_pInput->keyNum[RIGHT].pressCount, 1); }
		else { m_pInput->keyNum[RIGHT].pressCount = min(--m_pInput->keyNum[RIGHT].pressCount, 0); }
		// Vキー
		if (CheckHitKey(KEY_INPUT_V)) { m_pInput->keyNum[V].pressCount = max(++m_pInput->keyNum[V].pressCount, 1); }
		else { m_pInput->keyNum[V].pressCount = min(--m_pInput->keyNum[V].pressCount, 0); }
	}
};
