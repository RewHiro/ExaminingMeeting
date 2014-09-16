#pragma once
#include "Object.h"
class CStar : public Object{
public:
	CStar(Random &);
	~CStar();

private:
	int m_speed;
	u_int m_count;
	float m_theta;
	float m_alpha_change_value;
	Color m_color;
	enum class SpeedType{
		VERY_SLOWLY,
		SLOWLY,
		NORMAL,
		FASTER
	};
	SpeedType m_speed_type;

	void Update(AppEnv &, Random &);
	void Draw(AppEnv &);
	void Move();
};

