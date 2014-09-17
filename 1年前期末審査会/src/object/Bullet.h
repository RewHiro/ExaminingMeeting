#pragma once
#include "Object.h"

//========================================
//�e�N���X
//========================================

class CBullet : public Object{
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

	//pos:�e���o���ꏊ
	//color�F�e�̐F
	//theta�F�e�̊p�x
	//r�F�e�̑傫��(���a)
	//type�F�e�̃^�C�v
	//speed�F�e�̑��x
	//obj�F�������͂���ׂ̖ړI�I�u�W�F(�g�p���Ȃ��ꍇ��Vec2f(0,0))
	//scene�F�g�p����V�[��
	CBullet(const Vec2f &pos, const Color &color, const float theta, const Vec2f &r, 
		const Type type = Type::NORMAL, const float speed = 15, 
		const Vec2f &obj = Vec2f(0, 0), const Scene scene = Scene::TITLE);
	~CBullet();

	void Update(AppEnv &,Random &);		//�@�X�V
	void Draw(AppEnv &);		//�@�`��

private:

	float m_theta;				//�@�e�̊p�x
	float m_speed;
	float m_d;					// ����
	Color m_color;
	Scene m_scene;
	Type m_type;
	Vec2f m_diff;
	Vec2f m_copy_pos;

	std::list<std::unique_ptr<Object>>m_fireworks;

	void Move(AppEnv &);		//�@�ړ�����
	void RunOut();				//�@�^�X�N�I������
	void DeathEffect(Random &);			//�@���ł����Ƃ��̃G�t�F�N�g
	void Effect(AppEnv &,Random &);		//�@�G�t�F�N�g�̏���
};

