/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//�����ō쐬���鳨��޳�׽�̖��O

//�v���g�^�C�v�錾

LRESULT CALLBACK MY_WndProc(HWND , UINT , WPARAM , LPARAM );//�E�B���h�E�v���V�[�W��

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

	//�������E�B���h�E�N���X�̐ݒ�͂������火����
	winc.style = CS_HREDRAW | CS_VREDRAW;
	
	//�����������ō쐬��������޳��ۼ��ެ�ɕύX������
	winc.lpfnWndProc = MY_WndProc;

	winc.cbClsExtra = 0;
	winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = brush;
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT(MY_WIN_CLASS);
	//�������E�B���h�E�N���X�̐ݒ�͂����܂Ł�����

	//�E�B���h�E�N���X��o�^����
	if (!RegisterClass(&winc))
	{
		//�o�^���ł��Ȃ�������A�v���O�������I������
		return 0;
	}

	//�E�B���h�E�̍쐬(�E�B���h�E�N���X�̐���)
	hwnd = CreateWindow(
		TEXT(MY_WIN_CLASS),
		TEXT("�����œo�^�����E�B���h�E�N���X"),
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		600,
		600,
		NULL,
		NULL,
		hInstance,
		NULL);

	//�E�B���h�E����������Ȃ������Ƃ�
	if (hwnd == NULL)
	{
		return 0;//�������I��������
	}

	//�E�B���h�E��\��
	ShowWindow(
		hwnd,		//�\������E�C���h�E�n���h��
		SW_SHOW		//���݂̈ʒu�ƃT�C�Y�ŕ\��
	);

	//���b�Z�[�W��₦���󂯎�葱����
	while (TRUE)
	{
		GetMessage(&msg, NULL, 0, 0);
		DispatchMessage(&msg);
	}

	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++
//�E�B���h�E�v���V�[�W��(�֐�)���쐬
//�����ō쐬�ł���֐��Ȃ̂ŁA�֐��̖��O(WndProc)�͎��R�Ɍ��߂���
//+++++++++++++++++++++++++++++++++++++++++++++
//�߂�l�FLRESULT	���̊֐����Ԃ��A32�r�b�g�̒l
//���@���FHWND hwnd	���b�Z�[�W�����������E�B���h�E�̃n���h��
//���@���FUINT msg	���b�Z�[�W�����ʂ��鐮��
//���@���FWPARAM wp	���b�Z�[�W�̕t����񂻂̂P
//���@���FLPARAM lp	���b�Z�[�W�̕t����񂻂̂Q
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
		case WM_LBUTTONUP:
			//�}�E�X�̍��{�^�����������Ƃ�

			//���b�Z�[�W�{�b�N�X��\��
			MessageBox(
				hwnd,	//�쐬�����E�B���h�E����Ăяo���ꂽ���b�Z�[�W�{�b�N�X
				TEXT("�}�E�X�̍��{�^���������܂���"),
				TEXT("LEFT"),
				MB_OK);
			break;

		case WM_MBUTTONDOWN:
			//�}�E�X�̐^�񒆃{�^�����������Ƃ�

			//���b�Z�[�W�{�b�N�X��\��
			MessageBox(
				hwnd,	//�쐬�����E�B���h�E����Ăяo���ꂽ���b�Z�[�W�{�b�N�X
				TEXT("�}�E�X�̐^�񒆃{�^���������܂���"),
				TEXT("MIDDLE"),
				MB_OK);
			break;

		case WM_RBUTTONUP:
			//�}�E�X�̉E�{�^�����������Ƃ�

			//���b�Z�[�W�{�b�N�X��\��
			MessageBox(
				hwnd,	//�쐬�����E�B���h�E����Ăяo���ꂽ���b�Z�[�W�{�b�N�X
				TEXT("�}�E�X�̉E�{�^���������܂���"),
				TEXT("RIGHT"),
				MB_OK);
			break;

	}
	
	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	//���R�́A��{�I�ȃE�B���h�E�̓����������������
	return DefWindowProc(hwnd, msg, wp, lp);
}



//�R�����FMSG�\���̂̃����o
//typedef struct tagMSG
//{
//	HWND   hwnd;	//���b�Z�[�W�����������E�B���h�E�̃n���h��
//	UINT   message;	//���b�Z�[�W�����ʂ��鐮��
//	WPARAM wParam;	//���b�Z�[�W�̕t����񂻂̂P
//	LPARAM lParam;	//���b�Z�[�W�̕t����񂻂̂Q
//	DWORD  time;	//���b�Z�[�W������ꂽ����
//	POINT  pt;		//���b�Z�[�W������ꂽ�Ƃ��̃J�[�\���̈ʒu
//} MSG, *PMSG;

//�ۑ�F�E�B���h�E�v���V�[�W���̖��O��ύX����
//�ύX�O�FWndProc
//�ύX��FMY_WndProc

//�����F�ύX����ӏ�
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);		//�E�B���h�E�v���V�[�W��
//LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);	//�E�B���h�E�v���V�[�W��

//winc.lpfnWndProc = WndProc;		//�E�B���h�E�N���X�쐬��
//winc.lpfnWndProc = MY_WndProc;	//�E�B���h�E�N���X�쐬��

//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)		//�֐�
//LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)	//�֐�

*/