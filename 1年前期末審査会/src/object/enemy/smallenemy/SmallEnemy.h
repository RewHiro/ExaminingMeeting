#pragma once
#include "../Enemy.h"
class CSmallEnemy : public CEnemy{
public:
	CSmallEnemy();
	~CSmallEnemy();
	void Update(AppEnv &,Random &);				//　更新
	void Draw(AppEnv &);						//　描画
protected:
	float m_theta;
	int m_speed;
	std::list<std::unique_ptr<Object>>m_fireworks;
	std::list<std::unique_ptr<Object>>m_bullet;
	Color m_color;

	void Death();								//　死亡処理
	void DeathEffect(Random &);					//　死んだときのエフェクト
	void FireWorksUpdate(AppEnv &,Random &);
	void Hit();
	static const int FIREWORKS_NUM = 150;

};

