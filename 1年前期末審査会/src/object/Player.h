#pragma once
#include "Object.h"
class CPlayer : public Object{
public:
	CPlayer();
	~CPlayer();

	void Update(AppEnv &, Random &);		//　更新
	void Draw(AppEnv &);					//　描画

private:
	Color m_color;
	ArrayUpObj m_bullet;
	u_int m_shot_count;
	void Move(AppEnv &);					//　移動処理
	void Death();							//　死亡処理
	void CreateBullet();
	void ShotUpdate(AppEnv &, Random &);
	void Shot(AppEnv &);
};

