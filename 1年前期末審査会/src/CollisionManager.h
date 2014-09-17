#pragma once
class CollisionManager{
public:
	~CollisionManager();
	void Update();

	//�@�C���X�^���X�̐���
	static CollisionManager *GetInstance(){
		if (!m_instatnce){
			m_instatnce = new CollisionManager();
		}
		return m_instatnce;
	}

	//�@�R�s�[�̋֎~
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager &operator=(const CollisionManager&) = delete;

private:

	// �V���O���g��
	CollisionManager();
	static CollisionManager *m_instatnce;
};

