#pragma once
#include "../Enemy.h"
class CSmallEnemy : public CEnemy{
public:
	CSmallEnemy();
	~CSmallEnemy();
	void Update(AppEnv &,Random &);				//�@�X�V
	void Draw(AppEnv &);						//�@�`��
protected:
	float m_theta;
	int m_speed;
	std::list<std::unique_ptr<Object>>m_fireworks;
	std::list<std::unique_ptr<Object>>m_bullet;
	Color m_color;

	void Death();								//�@���S����
	void DeathEffect(Random &);					//�@���񂾂Ƃ��̃G�t�F�N�g
	void FireWorksUpdate(AppEnv &,Random &);
	void Hit();
	static const int FIREWORKS_NUM = 150;

};

