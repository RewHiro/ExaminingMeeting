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
	std::vector<std::unique_ptr<Object>>m_fireworks;
	Color m_color;


	virtual void Death();						//　死亡処理
	virtual void DeathEffect(Random &);					//　死んだときのエフェクト
	virtual void FireWorksUpdate(AppEnv &,Random &);
	static const int FIREWORKS_NUM = 150;

};

