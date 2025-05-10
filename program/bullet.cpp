#include "Main.h"
#include "Game.h"
#include "Random.h"
#include "bullet.h"

//	モード
enum {
	MODE_WAIT,		//	０：飛んでいない（待ち状態）
	MODE_MOVE,		//	１：飛んでいる　（移動状態）
};
//	何モードか（０：飛んでいない　１：飛んでいる）
int bullet_mode[BULLET_MAX];

//	何番目を撃つか
int shot_num;

void Bullet::Init()
{
	m_image[0] = LoadGraph("data/ball01_red.png");

	//弾
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet_x[i] = 100.0f;
		bullet_y[i] = 100.0f;
		bullet_mode[i] = MODE_WAIT;	//	飛んでいない状態から開始
	}

	//	０番目のミサイルを撃つから始めます
	shot_num = 0;

}

void Bullet::Update()
{
	//弾の発射処理
	if (PushHitKey(KEY_INPUT_SPACE))
	{
		bullet_mode[shot_num] = MODE_MOVE;		//	動く状態にします
		bullet_x[shot_num] = 400;			//	プレイヤーの座標にします
		bullet_y[shot_num] = 900;

		shot_num++;								//	次の番号にする
		if (shot_num >= BULLET_MAX) {			//	最後まで行ったら
			shot_num = 0;						//	最初から
		}
	}
	//弾の移動処理
	//	全弾の移動処理
	for (int i = 0; i < BULLET_MAX; i++) {
		//	ミサイルの移動処理（飛んでいる状態の時）
		if (bullet_mode[i] == MODE_MOVE) {
			//	向いている方向に移動
			//	Ｘ方向の移動は移動スピード（ MISSILE_SPEED ）を、向き（ missile_rot ）に沿っている長さに分けた長さ分移動
			//	Ｙ方向の移動は移動スピード（ MISSILE_SPEED ）を、向き（ missile_rot ）の向かいの長さに分けた長さ分移動
			bullet_y[i] -= BULLET_SPEED;

			//	画面の外に行ったら飛んでいない状態にします（どの方向に飛ぶか分からないので上下左右で判定します）
			if (bullet_x[i] < 0.0f)		bullet_mode[i] = MODE_WAIT;
			if (bullet_x[i] > SCREEN_W)	bullet_mode[i] = MODE_WAIT;
			if (bullet_y[i] < 0.0f)	    bullet_mode[i] = MODE_WAIT;
			if (bullet_y[i] > SCREEN_H)	bullet_mode[i] = MODE_WAIT;
		}
		else if (bullet_mode[i] == MODE_WAIT)
		{
			bullet_x[i] = -100;
		}
	}


}

void Bullet::Render()
{
	// 弾
	for (int i = 0; i < BULLET_MAX; i++) {
			//	ミサイルの座標と向きを渡して描画
		DrawRotaGraphF(bullet_x[i], bullet_y[i], 0.3f, 1, m_image[0], TRUE);
	}

}

void Bullet::Exit()
{
}
