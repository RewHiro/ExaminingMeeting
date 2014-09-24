#pragma once
#include "Object.h"
class CPlayer : public Object{
public:
	CPlayer();
	~CPlayer();
	std::list<std::shared_ptr<Object>>m_bullet;

	void Update(AppEnv &, Random &);		//�@�X�V
	void Draw(AppEnv &);					//�@�`��

private:
	Color m_color;
	u_int m_shot_count;
	void Move(AppEnv &);					//�@�ړ�����
	void Death();							//�@���S����
	void CreateBullet();					//�@�e�̐���
	void ShotUpdate(AppEnv &, Random &);	//�@�e�̍X�V
	void Shot(AppEnv &);					//�@�e�̔��ˏ���
	void Hit();								//�@���������Ƃ��̏���
};

