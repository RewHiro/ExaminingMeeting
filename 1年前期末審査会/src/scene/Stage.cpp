#include "Stage.h"
#include "../object/Player.h"

CStage::CStage(){
	m_player = std::make_unique<CPlayer>();
}


CStage::~CStage(){
}

void CStage::Update(AppEnv &app_env,Random &random){
	m_player->Update(app_env,random);
	if (app_env.isPushKey(GLFW_KEY_ENTER)){
		CSceneManager::SlectScene(CSceneManager::Scene::TITLE);
	}
}

void CStage::Draw(AppEnv &app_env){
	app_env.bgColor(color256(0, 103, 192));
	m_player->Draw(app_env);
}