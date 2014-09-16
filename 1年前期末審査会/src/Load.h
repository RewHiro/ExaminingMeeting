#pragma once
#include "lib\appEnv.hpp"
#include <memory>

//========================================
//ロードクラス
//========================================

class CLoad{
public:
	CLoad();
	~CLoad();
	//========================================
	//画像
	//========================================
	static const Texture *title_graph;
	static const Texture *enter_graph;
	static const Texture *title_bg;

	//========================================
	//音
	//========================================
	static const Media *title_bgm;
	static const Media *title_se;
	static const Media *fireworks_se[1];
};