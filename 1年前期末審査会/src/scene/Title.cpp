#include "Title.h"
#include "../Load.h"
#include "../object/Bullet.h"
#include "../Math.h"
#include "../object/Object.h"
#include "../Load.h"
#include <algorithm>

const int SHOT_POSX = 0;
const int SHOT_POSY = -CScene::HEIGHT / 2;

CTitle::CTitle(){
	m_scene_count = 0;
	m_alpha = 0;
	m_is_enter = false;
	CLoad::fireworks_se[0]->gain(10.0f);
	CLoad::title_bgm->looping(true);
	CLoad::title_bgm->play();
}

CTitle::~CTitle(){
	CLoad::title_bgm->stop();
}

//　更新
void CTitle::Update(AppEnv &app_env,Random &random){
	m_mouse_pos = app_env.mousePosition();

	if (!m_is_enter){
		m_alpha += static_cast<float>(M_PI / 120);
		if (app_env.isPushKey(GLFW_KEY_ENTER)){
			CLoad::title_se->play();
			m_is_enter = true;
		}
		if (app_env.isPushButton(Mouse::LEFT)){
			CreateBullet(m_mouse_pos, Vec2f(SHOT_POSX,SHOT_POSY));
		}
	}
	else{
		ReadyScene();
	}
	BulletUpdate(app_env,random);
}

//　描画
void CTitle::Draw(AppEnv &app_env){
	drawTextureBox(-WIDTH/2, -HEIGHT / 2, WIDTH, HEIGHT, 0, 0, 512, 512, *CLoad::title_bg, Color(1, 1, 1));

	for (auto &Bullet : m_bullet){
		Bullet->Draw(app_env);
	}

	drawTextureBox(0 - 300 + 5, 50, 600, 300, 0, 0, 1024, 512,
		*CLoad::title_graph, Color(0, 0, 0));
	drawTextureBox(0-300, 50, 600, 300, 0, 0, 1024, 512,
		*CLoad::title_graph, Color(1, 1, 1));

	drawTextureBox(0-250, -300, 500, 250, 0, 0, 1024, 512, 
		*CLoad::enter_graph, Color(1, 1, 1, std::abs(sin(m_alpha))));
}

//　遷移するまでの処理
void CTitle::ReadyScene(){
	m_scene_count++;
	m_alpha += static_cast<float>(M_PI / 4);
	ReadySceneSelectShot();
	if (m_scene_count == 60 * 4){
		CSceneManager::SlectScene(CSceneManager::Scene::STAGE);
	}
}

//　弾の生成
void CTitle::CreateBullet(Vec2f &target_pos,Vec2f &shot_pos){
	float theta = CMath::GetAngle(Vec2f(WIDTH / 2, -HEIGHT / 2), target_pos, shot_pos);
	m_bullet.emplace_back(std::make_unique<CBullet>(shot_pos, Color(1, 1, 1), theta, Vec2f(8.0f, 8.0f), CBullet::Type::NORMAL, 8.0f,target_pos, CBullet::Scene::TITLE));
}

//　弾の更新
void CTitle::BulletUpdate(AppEnv &app_env,Random &random){
	for (auto &Bullet : m_bullet){
		//m_bullet.erase(std::remove_if(m_bullet.begin(), m_bullet.end(), is_None()), m_bullet.end());
		Bullet->Update(app_env,random);
	}
	for (auto it = m_bullet.begin(); it != m_bullet.end();){
		if ((*it)->isRunOut()){
			it = m_bullet.erase(it);
		}
		else{
			++it;
		}
	}
}

//　遷移するまでのエフェクトの処理
void CTitle::ReadySceneShot(){
	CreateBullet(Vec2f(-400, 300), Vec2f(SHOT_POSX, SHOT_POSY));
	CreateBullet(Vec2f(-100, 100), Vec2f(SHOT_POSX, SHOT_POSY));
	CreateBullet(Vec2f(300, 200), Vec2f(SHOT_POSX, SHOT_POSY));
}

//　遷移するまでの弾をいつ出すか
void CTitle::ReadySceneSelectShot(){
	switch (m_scene_count){
	case 20:
		ReadySceneShot();
		break;
	case 30:
		ReadySceneShot();
		break;
	case 40:
		ReadySceneShot();
		break;
	case 50:
		ReadySceneShot();
		break;
	case 60:
		ReadySceneShot();
		break;
	}
}