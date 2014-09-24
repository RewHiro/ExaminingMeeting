#pragma once
#include "Object.h"
class CPlayer : public Object{
public:
	CPlayer();
	~CPlayer();
	std::list<std::shared_ptr<Object>>m_bullet;

	void Update(AppEnv &, Random &);		//　更新
	void Draw(AppEnv &);					//　描画

private:
	Color m_color;
	u_int m_shot_count;
	void Move(AppEnv &);					//　移動処理
	void Death();							//　死亡処理
	void CreateBullet();					//　弾の生成
	void ShotUpdate(AppEnv &, Random &);	//　弾の更新
	void Shot(AppEnv &);					//　弾の発射処理
	void Hit();								//　当たったときの処理
};

