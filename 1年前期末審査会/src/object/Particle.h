#pragma once
#include "Object.h"
#include "../lib/random.hpp"

//========================================
//�ԉ΃G�t�F�N�g�N���X
//========================================
class CFireWorks : public Object{
public:
	//�@�V�[���̎��
	enum class Scene{
		TITLE,
		STAGE,
		GAMECLEAR,
		RESULT
	};
	//�@�e�̎��
	enum class Type{
		NORMAL
	};
	//�@�ԉ΃G�t�F�N�g
	//�@pos�F��яo���|�W�W����
	//�@r�F���a
	//�@theta�F��юU��p�x
	//�@speed�F��юU�鑬�x
	//�@scene�F�ǂ̃V�[���Ŏg�p���邩
	//�@type�F���
	//�@red�F��(0~255)
	//�@green�F��(0~255)
	//�@blue�F��(0~255)
	//�@alpha�F�A���t�@�l(0~255)
	CFireWorks(const Vec2f &pos, const Vec2f &r, const float theta, const float speed, const Scene scene, const Type type, const int red, const int green, const int blue, const int alpha = 255);
	~CFireWorks();

	void Update(AppEnv &,Random &);	//�@�X�V
	void Draw(AppEnv &);	//�@�`��

private:
	int m_red;
	int m_green;
	int m_blue;
	float m_theta;			//�@��юU��p�x
	float m_speed;
	Scene m_scene;
	Type m_type;
	Color m_color;

	void Move();			//�@�ړ�����
	void RunOut();			//�@�^�X�N�I������
};

