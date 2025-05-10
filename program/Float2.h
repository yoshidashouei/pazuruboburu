#pragma once

//---------------------------------------------------------------------------------
//	Float2 �N���X
//---------------------------------------------------------------------------------
class Float2
{
public:
	float x;
	float y;

	Float2();									//	�R���X�g���N�^
	Float2( float x, float y );

	void Clear();								//	�[��������
	void Set( float x, float y );				//	�l�̃Z�b�g
	void Set( Float2 &f2 );

	Float2& operator = ( const Float2 &f2 );	//	= ���Z�q�̃I�[�o�[���[�h

	Float2& operator += ( const Float2 &f2 );	//	+= ���Z�q�̃I�[�o�[���[�h
	Float2& operator -= ( const Float2 &f2 );	//	-= ���Z�q�̃I�[�o�[���[�h
	Float2& operator *= ( const float f );		//	*= ���Z�q�̃I�[�o�[���[�h
	Float2& operator /= ( const float f );		//	/= ���Z�q�̃I�[�o�[���[�h
};

//	+ ���Z�q�̃I�[�o�[���[�h
Float2 operator + ( const Float2 &f2_1, const Float2 &f2_2 );
//	- ���Z�q�̃I�[�o�[���[�h
Float2 operator - ( const Float2 &f2_1, const Float2 &f2_2 );
//	* ���Z�q�̃I�[�o�[���[�h
Float2 operator * ( const Float2 &f2, const float f );
//	/ ���Z�q�̃I�[�o�[���[�h
Float2 operator / ( const Float2 &f2, const float f );

//	�}�E�X���W�� Float2 �Ŏ擾
Float2 GetMouseFloat2();
//	�Q�� Float2 �̋��������߂�
float GetFloat2Distance( Float2 &pos1, Float2 &pos2 );
