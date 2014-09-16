#include "Player.h"
#include "../scene/SceneManager.h"
#include "Bullet.h"

const int SPEED = 10;
const int SHOT_TIME = 10;

CPlayer::CPlayer() :m_color(color256(128, 0, 128)),m_shot_count(0){
	m_state = State::LIVE;
	m_hp = 20;
	m_r = Vec2f(32, 32);
	m_pos = Vec2f(0, -200);
}


CPlayer::~CPlayer(){
}

//　更新
void CPlayer::Update(AppEnv &app_env,Random &random){
	Move(app_env);
	Shot(app_env);
	ShotUpdate(app_env,random);
}

//　描画
void CPlayer::Draw(AppEnv &app_env){
	for (auto &Bullet : m_bullet){
		Bullet->Draw(app_env);
	}
	if (m_state == State::LIVE){
		drawFillCircle(m_pos.x(), m_pos.y(), m_r.x(), m_r.y(), 30, m_color);
	}
}

//　移動処理
void CPlayer::Move(AppEnv &app_env){
	if (m_state == State::NONE){ return; }
	else if (m_state == State::LIVE){
		if (app_env.isPressKey(GLFW_KEY_RIGHT)){
			m_vec.x() = SPEED;
			if (m_pos.x() > CScene::WIDTH / 2){
				m_vec.x() = 0;
			}
		}

		else if (app_env.isPressKey(GLFW_KEY_LEFT)){
			m_vec.x() = -SPEED;
			if (m_pos.x() < -CScene::WIDTH / 2){
				m_vec.x() = 0;
			}
		}
		else{
			m_vec.x() = 0;
		}
		if (app_env.isPressKey(GLFW_KEY_UP)){
			m_vec.y() = SPEED;
			if (m_pos.y() > CScene::HEIGHT / 2){
				m_vec.y() = 0;
			}
		}
		else if (app_env.isPressKey(GLFW_KEY_DOWN)){
			m_vec.y() = -SPEED;
			if (m_pos.y() < -CScene::HEIGHT / 2){
				m_vec.y() = 0;
			}
		}

		else{
			m_vec.y() = 0;
		}
		m_pos.x() += m_vec.x();
		m_pos.y() += m_vec.y();
	}
}

//　死亡処理
void CPlayer::Death(){
	if (m_state == State::NONE){ return; }
	else if (m_state == State::LIVE){
		if (m_hp <= 0){
			m_state = State::DEATH;
		}
	}
}

void CPlayer::CreateBullet(){
	if (m_state == State::NONE){ return; }
	else if (m_state == State::LIVE){
		m_bullet.emplace_back(std::make_unique<CBullet>(m_pos, color256(255,255,0), static_cast<float>(M_PI_2), Vec2f(8.0f, 8.0f), CBullet::Type::NORMAL, 15.0f, Vec2f(0, 0), CBullet::Scene::STAGE));
	}
}

void CPlayer::ShotUpdate(AppEnv &app_env,Random &random){
	for (auto &Bullet : m_bullet){
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

void CPlayer::Shot(AppEnv &app_env){
	if (m_state == State::NONE){ return; }
	else if (m_state == State::LIVE){
		if (app_env.isPressKey(GLFW_KEY_SPACE)){
			if (m_shot_count % SHOT_TIME == 0){
				CreateBullet();
			}
			m_shot_count++;
		}
		else{
			m_shot_count = 0;
		}
	}
}