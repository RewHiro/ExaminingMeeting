#pragma once
#include "SceneManager.h"
#include <memory>

class Object;

//========================================
//ステージクラス
//========================================

class CStage : public CScene{
public:
	CStage();
	~CStage();
	void Update(AppEnv &,Random &);
	void Draw(AppEnv &);
private:
	std::unique_ptr<Object>m_player;
};

