#pragma once
#include "../lib/appEnv.hpp"
#include "../lib/random.hpp"
#include <memory>

//========================================
//�V�[���N���X(���N���X)
//========================================

class CScene{
public:
	CScene(){}
	virtual ~CScene(){}
	virtual void Update(AppEnv &,Random &) = 0;
	virtual void Draw(AppEnv &) = 0;

	static const int WIDTH = 1320;
	static const int HEIGHT = 720;
};

//========================================
//�V�[���}�l�[�W���[�N���X
//========================================

class CSceneManager{

public:
	//�@�V�[���̎��
	enum class Scene{
		TITLE,
		STAGE,
		GAMECLEAR,
		RESLUT
	};

	//�@�C���X�^���X�̐���
	static CSceneManager *GetInstance(){
		if (!m_instatnce){
			m_instatnce = new CSceneManager();
		}
		return m_instatnce;
	}
	~CSceneManager();
	void Update(AppEnv &, Random &);					//�@�X�V
	void Draw(AppEnv &);								//�@�`��
	static void SlectScene(Scene next_scene);			//�@�J�ڂ������V�[����n���֐�

	//�@�R�s�[�̋֎~
	CSceneManager(const CSceneManager&) = delete;
	CSceneManager &operator=(const CSceneManager&) = delete;


private:
	//�@��Ԃ̎��
	enum class State{
		INIT,
		UPDATE
	};

	std::shared_ptr<CScene> m_scene;		//�@�V�[�������锠
	static Scene m_now_scene;				//�@���݂̃V�[��(�ÓI�ɂ��đ��ł��ς�����悤�ɂȂ��Ă��܂��Ă�)
	Scene m_old_scene;						//�@�J�ڂ���O�̃V�[��
	State m_state;							//�@���݂̏��
	
	void Transition(Random &random);

	// �V���O���g��
	CSceneManager();
	static CSceneManager *m_instatnce;
};