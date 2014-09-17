#pragma once
class CollisionManager{
public:
	~CollisionManager();
	void Update();

	//　インスタンスの生成
	static CollisionManager *GetInstance(){
		if (!m_instatnce){
			m_instatnce = new CollisionManager();
		}
		return m_instatnce;
	}

	//　コピーの禁止
	CollisionManager(const CollisionManager&) = delete;
	CollisionManager &operator=(const CollisionManager&) = delete;

private:

	// シングルトン
	CollisionManager();
	static CollisionManager *m_instatnce;
};

