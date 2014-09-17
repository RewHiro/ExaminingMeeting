#include "Bullet.h"
#include "../scene/SceneManager.h"
#include "../Math.h"
#include "../object/Particle.h"
#include "../Load.h"

const int FIREWORKS_NUM = 30;

//====================================================================================================
//pos:弾を出す場所、color：弾の色、theta：弾の角度、r：弾の大きさ(半径)、type：弾のタイプ、speed：弾の速度、
//		obj：距離をはかる為の目的オブジェ、scene：使用するシーン
//====================================================================================================
CBullet::CBullet(const Vec2f &pos, const Color &color, const float theta, const Vec2f &r,
	const Type type, const float speed, 
	const Vec2f &obj, const Scene scene) :
	m_color(color), m_theta(theta), m_type(type), m_speed(speed), m_scene(scene),
	m_d(CMath::Get2Distancef(pos, obj)), m_diff(CMath::GetDiff(obj, pos)), m_copy_pos(obj){

	m_pos = pos;
	m_r = r;
	m_state = State::LIVE;
	switch (m_scene){
	case Scene::TITLE:
		m_vec.x() = (m_diff.x() / m_d)*m_speed;
		m_vec.y() = (m_diff.y() / m_d)*m_speed;
		break;
	case Scene::STAGE:
		m_vec.x() = cos(m_theta)*m_speed;
		m_vec.y() = sin(m_theta)*m_speed;
		break;
	}
}

CBullet::~CBullet(){
}

//　更新
void CBullet::Update(AppEnv &app_env,Random &random){
	switch (m_scene){
	case Scene::TITLE:
		Effect(app_env,random);
		DeathEffect(random);
		break;
	}
	Move(app_env);
	RunOut();

}


//　描画
void CBullet::Draw(AppEnv &app_env){
	if (m_state == State::LIVE){
		drawFillCircle(m_pos.x(), m_pos.y(), m_r.x(), m_r.y(), 30,
			m_color);
	}
	if (m_scene == Scene::TITLE){
		for (auto & FireWorks : m_fireworks){
			FireWorks->Draw(app_env);
		}
	}
}

//　移動
void CBullet::Move(AppEnv &app_env){
	if (m_state != State::LIVE){ return; }
	else if (m_state == State::LIVE){
		switch (m_scene){
		case Scene::TITLE:
			m_d = CMath::Get2Distancef(m_copy_pos, m_pos);
			if (m_d <= 10){
				m_state = State::DEATH;
			}
			break;
		}
		m_pos += m_vec;
	}
}

//　弾の消滅
void CBullet::RunOut(){
	if (m_state != State::LIVE){ return; }
	else if (m_state == State::LIVE){
		if (m_pos.x() - m_r.x() > CScene::WIDTH / 2 + 100 ||
			m_pos.x() + m_r.x() < -CScene::WIDTH / 2 - 100){
			m_state = State::NONE;
		}
		if (m_pos.y() - m_r.y() > CScene::HEIGHT / 2 + 100 ||
			m_pos.y() + m_r.y() < -CScene::HEIGHT / 2 - 100){
			m_state = State::NONE;
		}
	}
}

//　消滅したときのエフェクト
void CBullet::DeathEffect(Random &random){
	if (m_scene != Scene::TITLE){ return; }
	else{
		if (m_state == State::DEATH){
			int red = random.fromFirstToLast(0, 255);
			int green = random.fromFirstToLast(0, 255);
			int blue = random.fromFirstToLast(0, 255);
			for (float theta = 0; theta < static_cast<float>(M_PI * 2 - M_PI / 100); theta += static_cast<float>((M_PI) / (FIREWORKS_NUM / 2))){
				m_fireworks.emplace_back(std::make_unique<CFireWorks>(m_pos, Vec2f(6.0f, 6.0f), theta, 2.0f, CFireWorks::Scene::TITLE, CFireWorks::Type::NORMAL, red, green, blue));
			}
			m_state = State::EFFECT;
			CLoad::fireworks_se[0]->play();
		}
	}
}

//　エフェクトの処理
void CBullet::Effect(AppEnv &app_env,Random &random){
	if (m_scene != Scene::TITLE){ return; }
	else {
		for (auto & FireWorks : m_fireworks){
			FireWorks->Update(app_env, random);
			if (FireWorks->Object::isRunOut()){
				m_state = State::NONE;
			}
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
}