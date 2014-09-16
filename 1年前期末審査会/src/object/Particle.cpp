#include "Particle.h"


//========================================
//�ԉ΃G�t�F�N�g
//========================================
CFireWorks::CFireWorks(const Vec2f &pos, const Vec2f &r, const float theta, const float speed, const Scene scene, const Type type, const int red, const int green, const int blue, const int alpha) :m_theta(theta), m_speed(speed), m_scene(scene), m_type(type), m_color(Color(red, green, blue, alpha)), m_red(red), m_green(green), m_blue(blue){
	m_pos = pos;
	m_r = r;
	m_state = State::LIVE;
	m_vec.x() = cos(m_theta)*m_speed;
	m_vec.y() = sin(m_theta)*m_speed;
	m_alpha = alpha;
}

CFireWorks::~CFireWorks(){
}

//�@�X�V
void CFireWorks::Update(AppEnv &app_env, Random &random){
	if (m_state == State::NONE){ return; }
	else if (m_state == State::LIVE){
		m_alpha-=2;
		Move();
		RunOut();
	}
}

//�@�`��
void CFireWorks::Draw(AppEnv &app_env){
	if (m_state == State::NONE){ return; }
	else if (m_state == State::LIVE){
		drawFillCircle(m_pos.x(), m_pos.y(), m_r.x(), m_r.y(), 30, color256(m_red,m_green,m_blue,m_alpha));
	}
}

//�@�ړ�����
void CFireWorks::Move(){
	m_pos.x() += m_vec.x();
	m_pos.y() += m_vec.y();
}

//�@�^�X�N�I������
void CFireWorks::RunOut(){
	if (m_alpha <= 0){
		m_state = State::NONE;
	}
}