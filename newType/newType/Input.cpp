#include "Input.h"

Input* Input::m_pInput = nullptr; // 静的グローバル変数

Input::Input()
{
	key k;
	k.pressCount = 0;
	for (auto i = 0; i < NUM; i++)	// 使うボタンの数生成
	{ 
		keyNum.push_back(k);
	}
}

Input::~Input()
{
	m_pInput->keyNum.clear();		// 解放処理
}

void Input::CreateInstance()
{
	if (m_pInput == nullptr) { m_pInput = new Input; }	// 入力クラスの生成
}

void Input::DeleteInstance()
{
	if (m_pInput != nullptr) { delete m_pInput; m_pInput = nullptr; }	// 入力クラスの解放
}
