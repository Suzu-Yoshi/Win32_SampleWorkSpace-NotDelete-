/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//�����ō쐬���鳨��޳�׽�̖��O

//�E�B���h�E�̏ꏊ��傫����ݒ�
#define WIN_X 100		//���̈ʒu
#define WIN_Y 100		//�c�̈ʒu
#define WIN_WIDTH 500	//��
#define WIN_HEIGHT 500	//����

//�v���g�^�C�v�錾

LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);//�E�B���h�E�v���V�[�W��

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{
	//���b�Z�[�W��ۑ�����\����
	MSG msg;

	//�E�B���h�E�N���X���Ǘ�����\����
	WNDCLASS winc;

	//�X��Window�����ʂ���l(�E�B���h�E�n���h��)
	HWND hwnd;

	//�u���V���쐬
	static HBRUSH brush;

	//�u���V�̐F��ݒ�
	brush = CreateSolidBrush(RGB(0, 255, 0));

	//�E�B���h�E�N���X�̐ݒ�͂�������
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = MY_WndProc;
	winc.cbClsExtra = 0;
	winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = brush;
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT(MY_WIN_CLASS);

	//�E�B���h�E�N���X��o�^����
	if (!RegisterClass(&winc))
	{
		//�o�^���ł��Ȃ�������A�v���O�������I������
		return 0;
	}

	//�E�B���h�E�̐���(�E�B���h�E�N���X�̐���)
	hwnd = CreateWindow(
		TEXT(MY_WIN_CLASS),
		TEXT("�����œo�^�����E�B���h�E�N���X"),
		WS_OVERLAPPEDWINDOW,
		WIN_X,
		WIN_Y,
		WIN_WIDTH,
		WIN_HEIGHT,
		NULL,
		NULL,
		hInstance,
		NULL);




	//�E�B���h�E����������Ȃ������Ƃ�
	if (hwnd == NULL)
	{
		//�������I��������
		return 0;
	}

	//�E�B���h�E��\��
	ShowWindow(
		hwnd,		//�\������E�C���h�E�n���h��
		SW_SHOW		//���݂̈ʒu�ƃT�C�Y�ŕ\��
	);

	//���b�Z�[�W���󂯎�葱����
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//�E�B���h�E�v���V�[�W��(�֐�)���쐬
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//+++++++++++++++++++++++++++++++++++++++++++++
	//�E�B���h�E�ɕ�����`�悷��
	//+++++++++++++++++++++++++++++++++++++++++++++
	//Windows �ł́A�E�B���h�E�╶�����܂߁A�S�Ă��u�摜�v�Ƃ��Ĉ���
	//���̂��߁A�Ⴆ�΁A�����\���������Ȃ�u�o�́v�ł͂Ȃ��u�`��v���ĕ\������
	//�u�`��v����ɂ́A GDI �t�@���N�V�������g�p����
	//GDI�FGraphics Device Interface�F�O���t�B�b�N�֘A�̃v���O����

	//HDC�F�f�o�C�X�R���e�L�X�g�̃n���h��
	//�f�o�C�X�R���e�L�X�g�FGDI�Ŏg�p����\���́F�`����s���Ƃ��Ɏg�p����
	HDC hdc;
	
	//�\�����镶����̃|�C���^
	LPCTSTR DrawStr = TEXT("�\�����镶����P");
	LPCTSTR DrawStr2 = TEXT("�\�����镶����Q");

	switch (msg)
	{
	case WM_CREATE:
		//�E�B���h�E�̐�����������

		//�E�B���h�E�𐶐�����Ƃ��́A0��Ԃ�
		return 0;

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	case WM_LBUTTONDOWN:
		//�}�E�X�̍��{�^�����������Ƃ�

		//�f�o�C�X�R���e�L�X�g�̃n���h�����擾
		hdc = GetDC(hwnd);	//�`�悷��E�B���h�E�n���h���������ɂ���

		//������\��
		TextOut(
			hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
			10,					//�����̊J�n�ʒu(X���W�F��)
			10,					//�����̊J�n�ʒu(Y���W�F�c)
			DrawStr,			//�\�����镶����̃|�C���^
			lstrlen(DrawStr));	//������̕������F(lstrlen�F�������𐔂���)

		TextOut(hdc,100,100, DrawStr2,lstrlen(DrawStr2));

		//�f�o�C�X�R���e�L�X�g�̃n���h�������
		ReleaseDC(hwnd, hdc);

		break;

	case WM_DESTROY:
		//�E�B���h�E���j�����ꂽ(�Ȃ��Ȃ���)�Ƃ�

		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�
		PostQuitMessage(0);
		return 0;
	}

	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}

//�����F�����̍ĕ`��
//1.��x�A��ʂ��ŏ��������Ă݂�
//2.���̌�A��ʂ��ő剻����ƁA�����͂ǂ��Ȃ邾�낤�H
*/