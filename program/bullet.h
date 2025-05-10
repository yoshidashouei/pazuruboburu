#pragma once

#include "Float2.h"

//弾の変数
//	数
#define BULLET_MAX		300
#define BULLET_SIZE     20.0f
//弾の移動スピード
#define BULLET_SPEED		20.0f


class Bullet
{
public:


	float bullet_x[BULLET_MAX];
	float bullet_y[BULLET_MAX];
	int m_rot_;
	int m_image[6];

	void Init();	//	初期化処理
	void Update();	//	更新処理
	void Render();	//	描画処理
	void Exit();	//	終了処理
};