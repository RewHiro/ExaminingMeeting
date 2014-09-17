#include "Stage.h"
#include "../object/Player.h"
#include "../object/Star.h"
#include "../Load.h"
#include "../object/enemy/smallenemy/NormalEnemy.h"
#include "../CollisionManager.h"

std::unique_ptr<Object>CStage::m_player;
std::vector<std::unique_ptr<Object>>CStage::m_star;
std::list<std::unique_ptr<Object>>CStage::m_enemy;

const int STAR_NUM = 80;

CStage::CStage(Random &random){
	m_player = std::make_unique<CPlayer>();
	for (u_int i = 0; i < STAR_NUM; i++){
		m_star.emplace_back(std::make_unique<CStar>(random));
	}
	CLoad::stage_bgm[0]->looping(true);
	CLoad::stage_bgm[0]->play();
	count = 0;
}

CStage::~CStage(){
	CLoad::stage_bgm[0]->stop();
}

void CStage::Update(AppEnv &app_env,Random &random){
	count++;
	for (auto &Star : m_star){
		Star->Update(app_env, random);
	}
	for (auto &Enemy : m_enemy){
		Enemy->Update(app_env, random);
	}
	m_player->Update(app_env,random);
	CreateEnemy();
	if (app_env.isPushKey(GLFW_KEY_ENTER)){
		CSceneManager::SlectScene(CSceneManager::Scene::TITLE);
	}
}

void CStage::Draw(AppEnv &app_env){
	app_env.bgColor(color256(0, 103, 192));
	for (auto &Star : m_star){
		Star->Draw(app_env);
	}
	for (auto &Enemy : m_enemy){
		Enemy->Draw(app_env);
	}
	m_player->Draw(app_env);
}

void CStage::CreateEnemy(){
	if (count == 60){
		m_enemy.emplace_back(std::make_unique<CNormalEnemy>(Vec2f(0, 400)));
	}
}