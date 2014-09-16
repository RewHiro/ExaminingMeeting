#pragma once
#include "Object.h"
class CPlayer : public Object{
public:
	CPlayer();
	~CPlayer();

	void Update(AppEnv &, Random &);		//�@�X�V
	void Draw(AppEnv &);					//�@�`��

private:
	Color m_color;
	ArrayUpObj m_bullet;
	u_int m_shot_count;
	void Move(AppEnv &);					//�@�ړ�����
	void Death();							//�@���S����
	void CreateBullet();
	void ShotUpdate(AppEnv &, Random &);
	void Shot(AppEnv &);
};

