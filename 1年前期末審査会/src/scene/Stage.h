#pragma once
#include "SceneManager.h"
#include <vector>
#include <memory>
#include <list>

class Object;
class CPlayer;
class CollisionManager;

//========================================
//�X�e�[�W�N���X
//========================================

class CStage : public CScene{
public:
	CStage(Random &random);
	~CStage();
	void Update(AppEnv &,Random &);
	void Draw(AppEnv &);

	//�@�ÓI�̈�̓v���O�����I�����ɕK����������H
	//�@�X�}�[�g�|�C���^�ŃX�R�[�v�𔲂��Ă��������Ȃ��H
	std::unique_ptr<CPlayer>m_player;
	std::vector<std::unique_ptr<Object>>m_star;
	std::list<std::shared_ptr<Object>>m_enemy;

private:
	u_int count;
	void CreateEnemy();										//�@�G�̐���
	void Collision();
};

