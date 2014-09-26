#include "SmallEnemy.h"
#include "../../Particle.h"

CSmallEnemy::CSmallEnemy(){
	m_state = State::LIVE;
	m_alpha = 255;
	m_color = color256(0, 0, 0, m_alpha);
	m_score = 100;
	m_hp = 20;
	m_r = Vec2f(32, 32);
}

CSmallEnemy::~CSmallEnemy(){
}

//　更新
void CSmallEnemy::Update(AppEnv &app_env,Random &random){
	Death();
	DeathEffect(random);
	FireWorksUpdate(app_env, random);
}

//　描画
void CSmallEnemy::Draw(AppEnv &app_env){
	if (m_state == State::NONE){ return; }
	else if(m_state == State::LIVE){
		drawFillCircle(m_pos.x(), m_pos.y(), m_r.x(), m_r.y(), 30, m_color);
	}
	for (auto &FireWorks : m_fireworks){
		FireWorks->Draw(app_env);
	}
}

//　死亡処理
void CSmallEnemy::Death(){
	if (m_state == State::NONE){ return; }
	else{
		if (m_hp <= 0){
			m_state = State::DEATH;
		}
	}
}

//　死んだときのエフェクト
void CSmallEnemy::DeathEffect(Random &random){
	if (m_state != State::DEATH){ return; }
	else if (m_state == State::DEATH){
		for (u_int i = 0; i < FIREWORKS_NUM; i++){
			m_fireworks.emplace_back(std::make_unique<CFireWorks>(m_pos, Vec2f(3, 3), static_cast<float>(random.fromFirstToLast(0, M_PI * 2)), random.fromFirstToLast(0.1f, 3.0f), CFireWorks::Scene::STAGE, CFireWorks::Type::NORMAL, 255, 255, 0));
		}
		m_state = State::NONE;
	}
}

void CSmallEnemy::FireWorksUpdate(AppEnv &app_env,Random &random){
	for (auto &FireWorks : m_fireworks){
		FireWorks->Update(app_env, random);
	}
	for (auto it = m_fireworks.begin(); it != m_fireworks.end();){
		if ((*it)->isRunOut()){
			it = m_fireworks.erase(it);
		}
		else{
			++it;
		}
	}
}

void CSmallEnemy::Hit(){
	if (!m_ishit){ return; }
	else if (m_ishit){
		m_hp -= 20;
		m_ishit = false;
	}
}