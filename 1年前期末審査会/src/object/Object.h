#pragma once
#include "../lib/appEnv.hpp"
#include "../lib/random.hpp"
#include <vector>
#include <memory>



//========================================
//オブジェクトクラス
//========================================

class Object{
public:
	Object(){};
	virtual ~Object(){};
	enum class State{
		NONE,
		LIVE,
		INVINCIBLE,
		DEATH,
		EFFECT,
		MOVE
	};
	virtual void Update(AppEnv &,Random &) = 0;
	virtual void Draw(AppEnv &) = 0;
	virtual bool isRunOut(){
		if (m_state == State::NONE){
			return true;
		}
		else {
			return false;
		}
	};

protected:
	int m_alpha;
	int m_hp;
	float m_alphaf;

	Vec2f m_pos;
	Vec2f m_vec;
	Vec2f m_r;					//　半径
	State m_state;
};

typedef std::vector<std::unique_ptr<Object>> ArrayUpObj;