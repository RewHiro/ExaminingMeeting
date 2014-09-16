#pragma once
#include "lib\appEnv.hpp"
class CMath{
public:
	static float GetAngle(const Vec2f &vec_a, const Vec2f &vec_b, const Vec2f &origin, bool is_degree = false);
	static double GetDistance(const Vec2f &vec);
	static double GetScalarProduct(const Vec2f &vec_a, const Vec2f &vec_b);
	static double Get2Distance(const Vec2f &vec_a, const Vec2f &vec_b);
	static float Get2Distancef(const Vec2f &vec_a, const Vec2f &vec_b);
	static Vec2f GetDiff(const Vec2f &vec_a, const Vec2f &vec_b);
};

