#include "Main.h"
#include "Game.h"
#include "Random.h"
#include "bullet.h"

//	���[�h
enum {
	MODE_WAIT,		//	�O�F���ł��Ȃ��i�҂���ԁj
	MODE_MOVE,		//	�P�F���ł���@�i�ړ���ԁj
};
//	�����[�h���i�O�F���ł��Ȃ��@�P�F���ł���j
int bullet_mode[BULLET_MAX];

//	���Ԗڂ�����
int shot_num;

int color_random;

void Bullet::Init()
{
	m_image[0]  = LoadGraph("data/ball01_red.png");
	m_image[1] = LoadGraph("data/ball02_blue.png");
	m_image[2] = LoadGraph("data/ball03_gold.png");
	m_image[3] = LoadGraph("data/ball04_purple.png");
	m_image[4] = LoadGraph("data/ball05_silber.png");
	//�e
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet_x[i] = 400.0f;
		bullet_y[i] = 850.0f;
		bullet_mode[i] = MODE_WAIT;	//	���ł��Ȃ���Ԃ���J�n
	}

	//	�O�Ԗڂ̃~�T�C����������n�߂܂�
	shot_num = 0;

	color_random = GetRand(4);
}

void Bullet::Update()
{
	//�e�̔��ˏ���
	for (int i = 0; i < BULLET_MAX; i++) {
		if (bullet_mode[i] == MODE_WAIT) {
			if (PushHitKey(KEY_INPUT_SPACE))
			{
				bullet_mode[shot_num] = MODE_MOVE;		//	������Ԃɂ��܂�
				bullet_x[shot_num] = 400;			//	�v���C���[�̍��W�ɂ��܂�
				bullet_y[shot_num] = 850;

				shot_num++;								//	���̔ԍ��ɂ���
				if (shot_num >= BULLET_MAX) {			//	�Ō�܂ōs������
					shot_num = 0;						//	�ŏ�����
				}
			}
		}
	}
	//�e�̈ړ�����
	//	�S�e�̈ړ�����
	for (int i = 0; i < BULLET_MAX; i++) {
		//	�~�T�C���̈ړ������i���ł����Ԃ̎��j
		if (bullet_mode[i] == MODE_MOVE) {
			//	�����Ă�������Ɉړ�
			//	�w�����̈ړ��͈ړ��X�s�[�h�i MISSILE_SPEED �j���A�����i missile_rot �j�ɉ����Ă��钷���ɕ������������ړ�
			//	�x�����̈ړ��͈ړ��X�s�[�h�i MISSILE_SPEED �j���A�����i missile_rot �j�̌������̒����ɕ������������ړ�
			bullet_y[i] -= BULLET_SPEED;

			//	��ʂ̊O�ɍs��������ł��Ȃ���Ԃɂ��܂��i�ǂ̕����ɔ�Ԃ�������Ȃ��̂ŏ㉺���E�Ŕ��肵�܂��j
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
			bullet_x[i] = 400;
			bullet_y[i] = 850;
		}
	}


}

void Bullet::Render()
{
	// �e
	for (int i = 0; i < BULLET_MAX; i++) {
			//	�~�T�C���̍��W�ƌ�����n���ĕ`��
		DrawRotaGraphF(bullet_x[i], bullet_y[i], 0.5f, 0, m_image[color_random], TRUE);
	}

}

void Bullet::Exit()
{
}
