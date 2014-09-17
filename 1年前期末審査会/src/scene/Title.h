#pragma once
#include "SceneManager.h"
#include "../lib/random.hpp"
#include <vector>
#include <memory>
#include <list>

#define TitleDebug FALSE

class Object;

//========================================
//タイトルクラス
//========================================

class CTitle : public CScene{

public:
	CTitle();
	~CTitle();

	void Update(AppEnv &,Random &);			//　更新
	void Draw(AppEnv &);			//　描画

private:
	bool m_is_enter;				//　エンターが押されたか
	u_int m_scene_count;			//　遷移するまでのカウント
	float m_alpha;

	Vec2f m_mouse_pos;

#if TitleDebug
	//　constのみで定義したい->インスタンス生成しないからstaicしないといけない
	//static const int BULLET_NUM = 40;
	//CBullet *bullet[BULLET_NUM];

#else
	std::list<std::unique_ptr<Object>>m_bullet;

#endif
	void ReadyScene();				//　遷移するまでの処理
	void CreateBullet(Vec2f &,Vec2f &);			//　弾の生成
	void BulletUpdate(AppEnv &,Random &);	//　弾の更新
	void ReadySceneShot();			//　遷移するまでのエフェクトの処理

	void ReadySceneSelectShot();	//　遷移するまでの弾をいつ出すか
};

