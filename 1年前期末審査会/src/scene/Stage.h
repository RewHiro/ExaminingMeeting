#pragma once
#include "SceneManager.h"
#include <vector>
#include <memory>
#include <list>

class Object;
class CollisionManager;

//========================================
//ステージクラス
//========================================

class CStage : public CScene{
public:
	CStage(Random &random);
	~CStage();
	void Update(AppEnv &,Random &);
	void Draw(AppEnv &);

	static std::unique_ptr<Object>m_player;
	static std::vector<std::unique_ptr<Object>>m_star;
	static std::list<std::unique_ptr<Object>>m_enemy;

private:
	u_int count;
	void CreateEnemy();										//　敵の生成
};

