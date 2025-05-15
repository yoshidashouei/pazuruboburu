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

int color_random[BULLET_MAX];

void Bullet::Init()
{
	m_image[0] = LoadGraph("data/ball01_red.png");
	m_image[1] = LoadGraph("data/ball02_blue.png");
	m_image[2] = LoadGraph("data/ball03_gold.png");
	m_image[3] = LoadGraph("data/ball04_purple.png");
	m_image[4] = LoadGraph("data/ball05_silber.png");
	line_image = LoadGraph("data/line.png");
	//�e
	for (int i = 0; i < BULLET_MAX; i++) {
		bullet_x[i] = 395.0f;
		bullet_y[i] = 870.0f;
		bullet_mode[i] = MODE_WAIT;	//	���ł��Ȃ���Ԃ���J�n
		m_rot[i] = 0.0f;
		color_random[i] = GetRand(4);


	}

	//	�O�Ԗڂ̃~�T�C����������n�߂܂�
	shot_num = 0;

	m_line.Set(395.0f, 870.0f);
	arrow_rot = 0;

}

void Bullet::Update()
{

	//���E�L�[�ŕ�����ς���
	if (CheckHitKey(KEY_INPUT_RIGHT))	arrow_rot += ROT_SPEED;
	if (CheckHitKey(KEY_INPUT_LEFT))	arrow_rot -= ROT_SPEED;
	if (arrow_rot > 75) {
		arrow_rot = 75;
	}  
	if (arrow_rot < -75) {	
		arrow_rot = -75;
	}

	//�e�̔��ˏ���
	//for (int i = 0; i < BULLET_MAX; i++) {

		//if (bullet_mode[i] == MODE_WAIT) {

			if (PushHitKey(KEY_INPUT_SPACE))
			{
				//WAIT�̎���rot�𖈉�ۑ�����
				m_rot[shot_num] = arrow_rot;

				bullet_mode[shot_num] = MODE_MOVE;		//	������Ԃɂ��܂�
				bullet_x[shot_num] = 395;			//	�v���C���[�̍��W�ɂ��܂�
				bullet_y[shot_num] = 870;

				shot_num++;								//	���̔ԍ��ɂ���
				if (shot_num >= BULLET_MAX) {			//	�Ō�܂ōs������
					shot_num = 0;						//	�ŏ�����
				}
			}
		//}
	//}
	//�e�̈ړ�����
	//	�S�e�̈ړ�����
	for (int i = 0; i < BULLET_MAX; i++) {
		//	�~�T�C���̈ړ������i���ł����Ԃ̎��j
		if (bullet_mode[i] == MODE_MOVE) {
			//	�����Ă�������Ɉړ�
			//	�w�����̈ړ��͈ړ��X�s�[�h���A�����ɉ����Ă��钷���ɕ������������ړ�
			//	�x�����̈ړ��͈ړ��X�s�[�h���A�����̌������̒����ɕ������������ړ�
			bullet_x[i] -= BULLET_SPEED * cosf(TO_RADIAN(m_rot[i] + 90 ));
			bullet_y[i] -= BULLET_SPEED * sinf(TO_RADIAN(m_rot[i] + 90 ));

			//	��ʂ̊O�ɍs��������ł��Ȃ���Ԃɂ��܂��i�ǂ̕����ɔ�Ԃ�������Ȃ��̂ŏ㉺���E�Ŕ��肵�܂��j
			if (bullet_x[i] < 0.0f + 120.0f) {
				m_rot[i] *= -1;
			}
			if (bullet_x[i] > SCREEN_W -120.0f) {
				m_rot[i] *= -1;
			}
			if (bullet_y[i] < 0.0f + 150.0f) {
				color_random[shot_num] = GetRand(4);
				bullet_mode[i] = MODE_WAIT;
			}
			if (bullet_y[i] > SCREEN_H) {
				bullet_mode[i] = MODE_WAIT;
			}
		}
		else if (bullet_mode[i] == MODE_WAIT)
		{	
			//bullet_x[i] = 395;
			//bullet_y[i] = 870;
		}
	}


}

void Bullet::Render()
{
	//���˃��C���̕`��
	DrawRotaGraphF(m_line.x, m_line.y, 2.0f, TO_RADIAN(arrow_rot), line_image, TRUE);

	// �e
	for (int i = 0; i < BULLET_MAX; i++) {

		//	�~�T�C���̍��W�ƌ�����n���ĕ`��
		DrawRotaGraphF(bullet_x[i], bullet_y[i], 0.5f, 0, m_image[color_random[i]], TRUE);

	}
	DrawRotaGraphF(395, 870, 0.5f, 0, m_image[color_random[shot_num]], TRUE);

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
