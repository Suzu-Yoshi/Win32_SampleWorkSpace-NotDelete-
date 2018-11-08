/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//�����ō쐬���鳨��޳�׽�̖��O

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

	//�������E�B���h�E�N���X�̐ݒ�͂������火����
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
	//�������E�B���h�E�N���X�̐ݒ�͂����܂Ł�����

	//�E�B���h�E�N���X��o�^����
	if (!RegisterClass(&winc))
	{
		//�o�^���ł��Ȃ�������A�v���O�������I������
		return 0;
	}



	
	//�E�B���h�E�̐���(�E�B���h�E�N���X�̐���)
	// �E�B���h�E�𐶐�����O�� WM_CREATE ��
	// ���b�Z�[�W�L���[�ɓ��邱�ƂȂ��E�B���h�E�v���V�[�W���ɑ���
	// �E�B���h�E����������Ȃ������Ƃ��ACreateWindow��NULL��Ԃ�
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
	switch (msg)
	{

	case WM_CREATE:
		//+++++++++++++++++++++++++++++++++++++++++++++
		//�E�B���h�E���쐬���������Ȃ��Ƃ�
		//+++++++++++++++++++++++++++++++++++++++++++++
		int ret_kekka;

		ret_kekka = MessageBox(
			hwnd,
			TEXT("�E�B���h�E�𐶐����܂����H"),
			TEXT("CREATE WINDOW ?"),
			MB_YESNO | MB_ICONQUESTION);

		if (ret_kekka == IDYES)
		{
			//�E�B���h�E�𐶐�����Ƃ��́A0��Ԃ�
			return 0;
		}
		else if (ret_kekka == IDNO)
		{
			//�E�B���h�E�𐶐����Ȃ��Ƃ��́A-1��Ԃ�
			return -1;
		}

	case WM_LBUTTONUP:
		//�}�E�X�̍��{�^�����������Ƃ�

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�}�E�X�̍��{�^���������܂���"),
			TEXT("LEFT"),
			MB_OK);
		break;

	case WM_MBUTTONDOWN:
		//�}�E�X�̐^�񒆃{�^�����������Ƃ�

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�}�E�X�̐^�񒆃{�^���������܂���"),
			TEXT("MIDDLE"),
			MB_OK);
		break;

	case WM_RBUTTONUP:
		//�}�E�X�̉E�{�^�����������Ƃ�

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�}�E�X�̉E�{�^���������܂���"),
			TEXT("RIGHT"),
			MB_OK);
		break;
		case WM_CLOSE:
		//����{�^�����������Ƃ�

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
		hwnd,
		TEXT("�E�B���h�E���I�������܂���"),
		TEXT("NOT CLOSE"),
		MB_OK);

		return 0;

		case WM_DESTROY:
		//�E�B���h�E���j�����ꂽ(�Ȃ��Ȃ���)�Ƃ�

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
		hwnd,
		TEXT("�E�B���h�E��j�����܂���"),
		TEXT("DESTROY"),
		MB_OK);

		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�
		PostQuitMessage(0);
		return 0;
	}
	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}
*/