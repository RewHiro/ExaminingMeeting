#pragma once
#include "lib\appEnv.hpp"

//=======================================
//当たり判定クラス
//=======================================

class CCollision{
public:
	static bool isCollision(Vec2f &obja, Vec2f &objb, Vec2f &ra, Vec2f &rb);
};