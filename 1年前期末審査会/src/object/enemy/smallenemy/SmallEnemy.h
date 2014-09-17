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
	std::vector<std::unique_ptr<Object>>m_fireworks;
	Color m_color;


	virtual void Death();						//�@���S����
	virtual void DeathEffect(Random &);					//�@���񂾂Ƃ��̃G�t�F�N�g
	virtual void FireWorksUpdate(AppEnv &,Random &);
	static const int FIREWORKS_NUM = 150;

};

