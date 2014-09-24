#include "NormalEnemy.h"

CNormalEnemy::CNormalEnemy(const Vec2f &pos){
	m_pos = pos;
	m_theta = static_cast<float>(-M_PI_2);
	m_speed = 2;
	m_vec.x() = cos(m_theta)*m_speed;
	m_vec.y() = sin(m_theta)*m_speed;
}

CNormalEnemy::~CNormalEnemy(){
}

void CNormalEnemy::Update(AppEnv &app_env,Random &random){
	Move();
	CSmallEnemy::Hit();
	CSmallEnemy::Death();
	CSmallEnemy::DeathEffect(random);
	CSmallEnemy::FireWorksUpdate(app_env, random);
}

void CNormalEnemy::Draw(AppEnv &app_env){
	CSmallEnemy::Draw(app_env);
}

void CNormalEnemy::Move(){
	if (m_pos.y() <= 300){
		m_vec = Vec2f(0, 0);
	}
	m_pos += m_vec;
}