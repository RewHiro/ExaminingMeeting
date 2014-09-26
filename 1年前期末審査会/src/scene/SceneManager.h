#pragma once
#include "../lib/appEnv.hpp"
#include "../lib/random.hpp"
#include <memory>

//========================================
//シーンクラス(基底クラス)
//========================================

class CScene{
public:
	CScene() = default;
	virtual ~CScene() = default;
	virtual void Update(AppEnv &,Random &) = 0;
	virtual void Draw(AppEnv &) = 0;

	static const int WIDTH = 1320;
	static const int HEIGHT = 720;
};

//========================================
//シーンマネージャークラス
//========================================

class CSceneManager{

public:
	//　シーンの種類
	enum class Scene{
		TITLE,
		STAGE,
		GAMECLEAR,
		RESLUT
	};

	//　インスタンスの生成
	static CSceneManager *GetInstance(){
		if (!m_instatnce){
			m_instatnce = new CSceneManager();
		}
		return m_instatnce;
	}
	~CSceneManager();
	void Update(AppEnv &, Random &);					//　更新
	void Draw(AppEnv &);								//　描画
	static void SlectScene(Scene next_scene);			//　遷移したいシーンを渡す関数

	//　コピーの禁止
	CSceneManager(const CSceneManager&) = delete;
	CSceneManager &operator=(const CSceneManager&) = delete;


private:
	//　状態の種類
	enum class State{
		INIT,
		UPDATE
	};

	std::unique_ptr<CScene> m_scene;		//　シーンを入れる箱
	static Scene m_now_scene;				//　現在のシーン(静的にして他でも変えられるようになってしまってる)
	Scene m_old_scene;						//　遷移する前のシーン
	State m_state;							//　現在の状態
	
	void Transition(Random &random);

	// シングルトン
	CSceneManager();
	static CSceneManager *m_instatnce;
};