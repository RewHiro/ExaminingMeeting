#include "Bullet.h"
#include "../scene/SceneManager.h"
#include "../Math.h"
#include "../object/Particle.h"
#include "../Load.h"

const int FIREWORKS_NUM = 30;

//====================================================================================================
//pos:�e���o���ꏊ�Acolor�F�e�̐F�Atheta�F�e�̊p�x�Ar�F�e�̑傫��(���a)�Atype�F�e�̃^�C�v�Aspeed�F�e�̑��x�A
//		obj�F�������͂���ׂ̖ړI�I�u�W�F�Ascene�F�g�p����V�[��
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

//�@�X�V
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


//�@�`��
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

//�@�ړ�
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
		m_pos.x() += m_vec.x();
		m_pos.y() += m_vec.y();
	}
}

//�@�e�̏���
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

//�@���ł����Ƃ��̃G�t�F�N�g
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

//�@�G�t�F�N�g�̏���
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