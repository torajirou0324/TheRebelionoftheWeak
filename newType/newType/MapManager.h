#pragma once
#define WIDTH_MAX 16
#define HEIGHT_MAX 12
#define WIDTH_SIZE 120
#define HEIGHT_SIZE 90

#include <string>
#include <fstream>
#include <sstream>
#include <DxLib.h>

// �}�b�v�̃V�[���ԍ�
enum class MapScene
{
	MAP_TITLE,
	MAP_BATTLE,
	MAP_VICTORY,
	MAP_DEFEAT
};

// �}�b�v�Ǘ��N���X
class MapManager
{
	static MapManager* m_pMap;

	int m_MapArray[HEIGHT_MAX][WIDTH_MAX];
	int m_MapTip[12];
	int m_BackGroundImg;
	int m_BackGroundY;
public:
	// �R�s�[�֎~
	MapManager(const MapManager&) = delete;
	MapManager& operator=(const MapManager&) = delete;

	MapManager();	// �R���X�g���N�^
	~MapManager();	// �f�X�g���N�^

	// �}�b�v�N���X�̐���
	static void CreateInstance() { if (m_pMap == nullptr) { m_pMap = new MapManager; } }
	// �}�b�v�N���X�̉��
	static void DeleteInstance() { if (m_pMap != nullptr) { delete m_pMap; m_pMap = nullptr; } }

	// �}�b�v�̏���������
	static void Init(MapScene map)
	{
		switch (map)
		{
		case MapScene::MAP_TITLE:
			m_pMap->m_BackGroundImg = LoadGraph("data/BackGround/TitleImg.png");
			m_pMap->CreateMap("data/csv/map0.csv");
			m_pMap->m_BackGroundY = 0;
			break;
		case MapScene::MAP_BATTLE:
			m_pMap->m_BackGroundImg = LoadGraph("data/BackGround/BattleImg.png");
			m_pMap->CreateMap("data/csv/map1.csv");
			m_pMap->m_BackGroundY = 180;
			break;
		case MapScene::MAP_VICTORY:
			break;
		case MapScene::MAP_DEFEAT:
			break;
		default:
			break;
		}
	}

	// �}�b�v�����[�h����
	static void CreateMap(std::string str)
	{
		std::ifstream ifs(str);	// �t�@�C���ǂݎ���p�X�g���[��

		std::string file = "";	// �f�[�^�̈ꎞ�ۊǗp�����z��
		int numY = 0;
		while (std::getline(ifs, file))
		{
			int numX = 0;
			std::string tmp = "";
			std::istringstream i_stream(file);		// ��s����file�֕ۑ�
			// ��؂蕶���������Ȃ�܂ŕ��������؂��Ă���
			while (std::getline(i_stream, tmp, ','))
			{
				// ��؂�ꂽ������tmp�ɓ���
				m_pMap->m_MapArray[numY][numX] = std::atoi(tmp.c_str());
				numX++;
			}
			numY++;
		}
	}

	// �}�b�v�`��
	static void Draw()
	{
		// �w�i
		DrawGraph(0, m_pMap->m_BackGroundY, m_pMap->m_BackGroundImg, FALSE);

		// �}�b�v�`�b�v
		for (auto y = 0; y < HEIGHT_MAX; y++)
		{
			for (auto x = 0; x < WIDTH_MAX; x++)
			{
				auto numImg = m_pMap->m_MapArray[y][x];
				if (numImg != 0) { DrawGraph(x * 120, y * 90, m_pMap->m_MapTip[numImg], TRUE); }
			}
		}
	}

	// �}�b�v�`�b�v�̓����蔻��Ǘ�
	static bool CollisionManager(int _PosX, int _PosY)
	{
		for (auto y = 0; y < HEIGHT_MAX; y++)
		{
			for (auto x = 0; x < WIDTH_MAX; x++)
			{
				auto MapNum = m_pMap->m_MapArray[y][x];
				if (MapNum == 1 || MapNum == 4 || MapNum == 10)
				{
					if (MapCollision(_PosX, _PosY, x, y))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	// ���̃I�u�W�F�N�g�ƃ}�b�v�`�b�v�̓����蔻��
	static bool MapCollision(int _PosX, int _PosY, int _MapX, int _MapY)
	{
		if (((_MapX * WIDTH_SIZE > _PosX && _MapX * WIDTH_SIZE < _PosX + 150) ||
			(_PosX > _MapX * WIDTH_SIZE && _PosX < _MapX * WIDTH_SIZE + WIDTH_SIZE)) &&
			((_MapY * HEIGHT_SIZE > _PosY && _MapY * HEIGHT_SIZE < _PosY + 180) ||
				(_PosY > _MapY * HEIGHT_SIZE && _PosY < _MapY * HEIGHT_SIZE + HEIGHT_SIZE)))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
};