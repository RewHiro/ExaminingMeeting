#pragma once
#include "lib\appEnv.hpp"
#include <memory>

//========================================
//���[�h�N���X
//========================================

class CLoad{
public:
	CLoad();
	~CLoad();
	//========================================
	//�摜
	//========================================
	static const Texture *title_graph;
	static const Texture *enter_graph;
	static const Texture *title_bg;

	//========================================
	//��
	//========================================
	static const Media *title_bgm;
	static const Media *title_se;
	static const Media *fireworks_se[1];
	static const Media *stage_bgm[1];
};