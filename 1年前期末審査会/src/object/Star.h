#pragma once
#include "Object.h"
class CStar : public Object{
public:
	CStar(Random &);
	~CStar();
	void Update(AppEnv &, Random &);
	void Draw(AppEnv &);

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
	void Move();								//　移動処理
	void Reset(Random &);						//　再設定
	void RunOut();								//　タスク終了処理
	void AlphaValUpdate();						//　アルファ値の更新
};

