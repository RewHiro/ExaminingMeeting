#pragma once
#include "SceneManager.h"
#include "../lib/random.hpp"
#include <vector>
#include <memory>
#include <list>

#define TitleDebug FALSE

class Object;

//========================================
//�^�C�g���N���X
//========================================

class CTitle : public CScene{

public:
	CTitle();
	~CTitle();

	void Update(AppEnv &,Random &);			//�@�X�V
	void Draw(AppEnv &);			//�@�`��

private:
	bool m_is_enter;				//�@�G���^�[�������ꂽ��
	u_int m_scene_count;			//�@�J�ڂ���܂ł̃J�E���g
	float m_alpha;

	Vec2f m_mouse_pos;

#if TitleDebug
	//�@const�݂̂Œ�`������->�C���X�^���X�������Ȃ�����staic���Ȃ��Ƃ����Ȃ�
	//static const int BULLET_NUM = 40;
	//CBullet *bullet[BULLET_NUM];

#else
	std::list<std::unique_ptr<Object>>m_bullet;

#endif
	void ReadyScene();				//�@�J�ڂ���܂ł̏���
	void CreateBullet(Vec2f &,Vec2f &);			//�@�e�̐���
	void BulletUpdate(AppEnv &,Random &);	//�@�e�̍X�V
	void ReadySceneShot();			//�@�J�ڂ���܂ł̃G�t�F�N�g�̏���

	void ReadySceneSelectShot();	//�@�J�ڂ���܂ł̒e�����o����
};

