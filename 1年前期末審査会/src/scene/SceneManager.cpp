#include "SceneManager.h"
#include "Title.h"
#include "Stage.h"

CSceneManager *CSceneManager::m_instatnce = nullptr;
CSceneManager::Scene CSceneManager::m_now_scene = CSceneManager::Scene::STAGE;

CSceneManager::CSceneManager():m_state(State::INIT),m_scene(nullptr){
}

CSceneManager::~CSceneManager(){
	//�@Escape�ŕ���ƃG���[
	//�@delete�����������H
	//�@�ÓI�̈悾����delete�v��Ȃ��H��m_instance
}

//�@�J�ڏ���
void CSceneManager::Transition(Random &random){
	m_scene.reset();
	switch (m_now_scene){
	case Scene::TITLE:
		m_scene = std::make_unique<CTitle>();
		break;
	case Scene::STAGE:
		m_scene = std::make_unique<CStage>(random);
		break;
	case Scene::GAMECLEAR:
		break;
	case Scene::RESLUT:
		break;
	}

	m_old_scene = m_now_scene;
	m_state = State::UPDATE;
}

//�@�X�V
void CSceneManager::Update(AppEnv &app_env,Random &random){
	switch (m_state){
	case State::INIT:
		Transition(random);
		break;

	case State::UPDATE:
		m_scene->Update(app_env,random);
		if (m_now_scene != m_old_scene){
			m_state = State::INIT;
		}
		break;
	}
}

//�@�`��
void CSceneManager::Draw(AppEnv &app_env){
	// �`�揀��
	app_env.setupDraw();
	
	if (m_state == State::UPDATE){
		m_scene->Draw(app_env);
	}

	// ��ʍX�V
	app_env.update();
}

//�@�J�ڂ������V�[����n���֐�
void CSceneManager::SlectScene(Scene next_scene){
	m_now_scene = next_scene;
}