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

int color_random;

void Bullet::Init()
{
	m_image[0] = LoadGraph("data/ball01_red.png");
	m_image[1] = LoadGraph("data/ball02_blue.png");
	m_image[2] = LoadGraph("data/ball03_gold.png");
	m_image[3] = LoadGraph("data/ball04_purple.png");
	m_image[4] = LoadGraph("data/ball05_silber.png");
	line_image = LoadGraph("data/line.png");
	//弾
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet_x[i] = 390.0f;
		bullet_y[i] = 870.0f;
		bullet_mode[i] = MODE_WAIT;	//	飛んでいない状態から開始
	}

	//	０番目のミサイルを撃つから始めます
	shot_num = 0;

	color_random = GetRand(4);
	m_rot = 0.0f;
	m_line.Set(395.0f, 870.0f);

}

void Bullet::Update()
{

	//左右キーで方向を変える
	if (CheckHitKey(KEY_INPUT_RIGHT))	m_rot += ROT_SPEED;
	if (CheckHitKey(KEY_INPUT_LEFT))	m_rot -= ROT_SPEED;
	if (m_rot > 75) {
		m_rot = 75;
	}
	if (m_rot < -75) {

		m_rot = -75;
	}

	//弾の発射処理
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet_mode[i] == MODE_WAIT) {
			if (PushHitKey(KEY_INPUT_SPACE))
			{
				//WAITの時にrotを毎回保存する
				keep_rot = m_rot;

				bullet_mode[shot_num] = MODE_MOVE;		//	動く状態にします
				bullet_x[shot_num] = 395;			//	プレイヤーの座標にします
				bullet_y[shot_num] = 870;

				shot_num++;								//	次の番号にする
				if (shot_num >= BULLET_MAX) {			//	最後まで行ったら
					shot_num = 0;						//	最初から
				}
			}
		}
	}
	//弾の移動処理
	//	全弾の移動処理
	for (int i = 0; i < BULLET_MAX; i++) {
		//	ミサイルの移動処理（飛んでいる状態の時）
		if (bullet_mode[i] == MODE_MOVE) {
			//	向いている方向に移動
			//	Ｘ方向の移動は移動スピードを、向きに沿っている長さに分けた長さ分移動
			//	Ｙ方向の移動は移動スピードを、向きの向かいの長さに分けた長さ分移動
			bullet_x[i] -= BULLET_SPEED * cosf(TO_RADIAN(keep_rot + 90));
			bullet_y[i] -= BULLET_SPEED * sinf(TO_RADIAN(keep_rot + 90));

			//	画面の外に行ったら飛んでいない状態にします（どの方向に飛ぶか分からないので上下左右で判定します）
			if (bullet_x[i] < 0.0f) {
				bullet_mode[i] = MODE_WAIT;
				color_random = GetRand(4);
			}
			if (bullet_x[i] > SCREEN_W) {
				bullet_mode[i] = MODE_WAIT;
				color_random = GetRand(4);
			}
			if (bullet_y[i] < 0.0f) {
				bullet_mode[i] = MODE_WAIT;
				color_random = GetRand(4);
			}
			if (bullet_y[i] > SCREEN_H) {
				bullet_mode[i] = MODE_WAIT;
				color_random = GetRand(4);
			}
		}
		else if (bullet_mode[i] == MODE_WAIT)
		{
			bullet_x[i] = 395;
			bullet_y[i] = 870;
		}
	}


}

void Bullet::Render()
{
	// 弾
	for (int i = 0; i < BULLET_MAX; i++) {
		//発射ラインの描画
		DrawRotaGraphF(m_line.x, m_line.y, 2.0f, TO_RADIAN(m_rot), line_image, TRUE);
		//	ミサイルの座標と向きを渡して描画
		DrawRotaGraphF(bullet_x[i], bullet_y[i], 0.5f, 0, m_image[color_random], TRUE);

	}

}

void Bullet::Exit()
{
	DeleteGraph(m_image[0]);
	DeleteGraph(m_image[1]);
	DeleteGraph(m_image[2]);
	DeleteGraph(m_image[3]);
	DeleteGraph(m_image[4]);
	DeleteGraph(line_image);
}
