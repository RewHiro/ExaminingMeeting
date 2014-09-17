#pragma once
#include "Object.h"

//========================================
//弾クラス
//========================================

class CBullet : public Object{
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

	//pos:弾を出す場所
	//color：弾の色
	//theta：弾の角度
	//r：弾の大きさ(半径)
	//type：弾のタイプ
	//speed：弾の速度
	//obj：距離をはかる為の目的オブジェ(使用しない場合はVec2f(0,0))
	//scene：使用するシーン
	CBullet(const Vec2f &pos, const Color &color, const float theta, const Vec2f &r, 
		const Type type = Type::NORMAL, const float speed = 15, 
		const Vec2f &obj = Vec2f(0, 0), const Scene scene = Scene::TITLE);
	~CBullet();

	void Update(AppEnv &,Random &);		//　更新
	void Draw(AppEnv &);		//　描画

private:

	float m_theta;				//　弾の角度
	float m_speed;
	float m_d;					// 距離
	Color m_color;
	Scene m_scene;
	Type m_type;
	Vec2f m_diff;
	Vec2f m_copy_pos;

	std::list<std::unique_ptr<Object>>m_fireworks;

	void Move(AppEnv &);		//　移動処理
	void RunOut();				//　タスク終了処理
	void DeathEffect(Random &);			//　消滅したときのエフェクト
	void Effect(AppEnv &,Random &);		//　エフェクトの処理
};

