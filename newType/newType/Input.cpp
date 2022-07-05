#include "Input.h"

Input* Input::m_pInput = nullptr; // �ÓI�O���[�o���ϐ�

Input::Input()
{
	key k;
	k.pressCount = 0;
	for (auto i = 0; i < NUM; i++)	// �g���{�^���̐�����
	{ 
		keyNum.push_back(k);
	}
}

Input::~Input()
{
	m_pInput->keyNum.clear();		// �������
}

void Input::CreateInstance()
{
	if (m_pInput == nullptr) { m_pInput = new Input; }	// ���̓N���X�̐���
}

void Input::DeleteInstance()
{
	if (m_pInput != nullptr) { delete m_pInput; m_pInput = nullptr; }	// ���̓N���X�̉��
}
