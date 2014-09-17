#pragma once
#include "SmallEnemy.h"
class CNormalEnemy : public CSmallEnemy{
public:
	CNormalEnemy(const Vec2f &pos);
	~CNormalEnemy();

	void Update(AppEnv&,Random &);
	void Draw(AppEnv &);
private:
	void Move();
};

