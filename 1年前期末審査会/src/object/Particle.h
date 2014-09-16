#pragma once
#include "Object.h"
#include "../lib/random.hpp"

//========================================
//花火エフェクトクラス
//========================================
class CFireWorks : public Object{
public:
	//　シーンの種類
	enum class Scene{
		TITLE,
		STAGE,
		GAMECLEAR,
		RESULT
	};
	//　弾の種類
	enum class Type{
		NORMAL
	};
	//　花火エフェクト
	//　pos：飛び出すポジジョン
	//　r：半径
	//　theta：飛び散る角度
	//　speed：飛び散る速度
	//　scene：どのシーンで使用するか
	//　type：種類
	//　red：赤(0~255)
	//　green：緑(0~255)
	//　blue：青(0~255)
	//　alpha：アルファ値(0~255)
	CFireWorks(const Vec2f &pos, const Vec2f &r, const float theta, const float speed, const Scene scene, const Type type, const int red, const int green, const int blue, const int alpha = 255);
	~CFireWorks();

	void Update(AppEnv &,Random &);	//　更新
	void Draw(AppEnv &);	//　描画

private:
	int m_red;
	int m_green;
	int m_blue;
	float m_theta;			//　飛び散る角度
	float m_speed;
	Scene m_scene;
	Type m_type;
	Color m_color;

	void Move();			//　移動処理
	void RunOut();			//　タスク終了判定
};

