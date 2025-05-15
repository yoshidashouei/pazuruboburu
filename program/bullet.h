#pragma once

#include "Float2.h"

//�e�̕ϐ�
//	��
#define BULLET_MAX		300
#define BULLET_SIZE     20.0f
//�e�̈ړ��X�s�[�h
#define BULLET_SPEED		20.0f

#define ROT_SPEED 3.0f

class Bullet
{
public:

	float m_speed;

	float bullet_x[BULLET_MAX];
	float bullet_y[BULLET_MAX];
	int m_rot[BULLET_MAX];
	int m_image[5];
	Float2 m_line;
	int line_image;
	int arrow_rot;




	void Init();	//	����������
	void Update();	//	�X�V����
	void Render();	//	�`�揈��
	void Exit();	//	�I������
};