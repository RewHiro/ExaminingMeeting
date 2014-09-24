#pragma once
#include "SceneManager.h"
#include <vector>
#include <memory>
#include <list>

class Object;
class CPlayer;
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

	//　静的領域はプログラム終了時に必ず解放される？
	//　スマートポインタでスコープを抜けても解放されない？
	std::unique_ptr<CPlayer>m_player;
	std::vector<std::unique_ptr<Object>>m_star;
	std::list<std::shared_ptr<Object>>m_enemy;

private:
	u_int count;
	void CreateEnemy();										//　敵の生成
	void Collision();
};

