#include "SceneManager.h"
#include "Title.h"
#include "Stage.h"

CSceneManager *CSceneManager::m_instatnce = nullptr;
CSceneManager::Scene CSceneManager::m_now_scene = CSceneManager::Scene::STAGE;

CSceneManager::CSceneManager():m_state(State::INIT),m_scene(nullptr){
}

CSceneManager::~CSceneManager(){
	//　Escapeで閉じるとエラー
	//　deleteがおかしい？
	//　静的領域だからdelete要らない？→m_instance
}

//　遷移処理
void CSceneManager::Transition(){
	m_scene.reset();
	switch (m_now_scene){
	case Scene::TITLE:
		m_scene = std::make_unique<CTitle>();
		break;
	case Scene::STAGE:
		m_scene = std::make_unique<CStage>();
		break;
	case Scene::GAMECLEAR:
		break;
	case Scene::RESLUT:
		break;
	}

	m_old_scene = m_now_scene;
	m_state = State::UPDATE;
}

//　更新
void CSceneManager::Update(AppEnv &app_env,Random &random){
	switch (m_state){
	case State::INIT:
		Transition();
		break;

	case State::UPDATE:
		m_scene->Update(app_env,random);
		if (m_now_scene != m_old_scene){
			m_state = State::INIT;
		}
		break;
	}
}

//　描画
void CSceneManager::Draw(AppEnv &app_env){
	// 描画準備
	app_env.setupDraw();
	
	if (m_state == State::UPDATE){
		m_scene->Draw(app_env);
	}

	// 画面更新
	app_env.update();
}

//　遷移したいシーンを渡す関数
void CSceneManager::SlectScene(Scene next_scene){
	m_now_scene = next_scene;
}