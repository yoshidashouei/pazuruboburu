#pragma once

#include "Float2.h"

//�e�̕ϐ�
//	��
#define BULLET_MAX		300
#define BULLET_SIZE     20.0f
//�e�̈ړ��X�s�[�h
#define BULLET_SPEED		20.0f


class Bullet
{
public:


	float bullet_x[BULLET_MAX];
	float bullet_y[BULLET_MAX];
	int m_rot_;
	int m_image[6];

	void Init();	//	����������
	void Update();	//	�X�V����
	void Render();	//	�`�揈��
	void Exit();	//	�I������
};