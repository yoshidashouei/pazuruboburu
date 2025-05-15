#include "Main.h"
#include "Game.h"
#include "Random.h"
#include "Float2.h"
#include "Hit.h"
#include "bullet.h"
int screen_image; //�w�i�̕ϐ�

float game_w;
float game_h;
#define CIRCLE_SIZE 25


//���N���X�̕ϐ�
Bullet bullet;
//---------------------------------------------------------------------------------
//	����������
//---------------------------------------------------------------------------------
void GameInit()
{
	screen_image = LoadGraph("data/screen.png");

	bullet.Init();
}
//---------------------------------------------------------------------------------
//	�X�V����
//---------------------------------------------------------------------------------
void GameUpdate()
{
	bullet.Update();
}

//---------------------------------------------------------------------------------
//	�`�揈��
//---------------------------------------------------------------------------------
void GameRender()
{
	DrawGraph(0,0,screen_image, TRUE);

	for (int h = 0; h < 10; h++) {
		for (int w = 0; w < 11; w++) {
			int x = (130 + (CIRCLE_SIZE * 2) * w) + CIRCLE_SIZE * (h % 2);
			int y = 150 + (CIRCLE_SIZE * 2) * h;
			DrawCircle(x, y, CIRCLE_SIZE, GetColor(255, 255, 255), 0, 1);
		}
	}


	bullet.Render();
}
//---------------------------------------------------------------------------------
//	�I������
//---------------------------------------------------------------------------------
void GameExit()
{
	DeleteGraph(screen_image);
	bullet.Exit();
}
