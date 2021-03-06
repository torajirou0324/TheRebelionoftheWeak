#include "MapManager.h"

MapManager* MapManager::m_pMap = nullptr;

MapManager::MapManager()
{
	// 文字列を使った読み込み
	for (auto i = 0; i < 12; i++)
	{
		std::stringstream fname;
		fname << "data/MapTip/" << "mapTip" << i << ".png";
		m_MapTip[i] = LoadGraph(fname.str().c_str());
	}
	m_MapTip[0] = 0;
	m_BackGroundY = 0;
}

MapManager::~MapManager()
{
}
