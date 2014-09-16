#include "Star.h"
#include "../scene/SceneManager.h"


CStar::CStar(Random &random) : m_count(random.fromFirstToLast(0, 60*2)),m_theta(static_cast<float>(-M_PI_2-M_PI_4)),m_alpha_change_value(0.01f),m_speed_type(static_cast<SpeedType>(random.fromFirstToLast(0,3))){
	m_pos = Vec2f(random.fromFirstToLast(-CScene::WIDTH/2,CScene::WIDTH),random.fromFirstToLast(-CScene::HEIGHT/2,CScene::HEIGHT));
	m_state = State::LIVE;
	m_alphaf = random.fromFirstToLast(0, 1);
	m_color = Color(1, 1, 1, m_alphaf);
	switch (m_speed_type){
	case SpeedType::VERY_SLOWLY:
		m_r = Vec2f(1,1);
		m_speed = 1;
		break;
	case SpeedType::SLOWLY:
		m_r = Vec2f(2,2);
		m_speed = 2;
		break;
	case SpeedType::NORMAL:
		m_r = Vec2f(3,3);
		m_speed = 3;
		break;
	case SpeedType::FASTER:
		m_r = Vec2f(5,5);
		m_speed = 4;
		break;
	}
	m_vec.x() = cos(m_theta)*m_speed;
	m_vec.y() = sin(m_theta)*m_speed;
}


CStar::~CStar(){
}

void  CStar::Update(AppEnv &app_env,Random &random){
	Move();
}

void CStar::Draw(AppEnv &app_env){
	if (m_state != State::LIVE){ return; }
	else if (m_state == State::LIVE){
		drawFillCircle(m_pos.x(), m_pos.y(), m_r.x(), m_r.y(), 30, m_color);
	}
}

void CStar::Move(){
	m_alphaf += m_alpha_change_value;
	m_count++;
	if (m_count >= 60 * 2){
		m_state = State::MOVE;
	}
	if (m_alphaf >= 1.0f){
		m_alpha_change_value *= -1;
	}
	else if (m_alphaf <= 0){
		m_alpha_change_value *= -1;
	}
	if (m_state == State::MOVE){
		m_pos += m_vec;
	}
	else if (m_state == State::LIVE){
		m_pos += Vec2f(0, 0);
	}
	if (m_pos.x() < -CScene::WIDTH / 2 || m_pos.y() < -CScene::HEIGHT / 2){
		m_state = State::NONE;
	}
}