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
	//+++++++++++++++++++++++++++++++++++++++++++++
	//�f�t�H���g�̒l���g�p���ăE�B���h�E�𐶐�
	//+++++++++++++++++++++++++++++++++++++++++++++
	hwnd = CreateWindow(
		TEXT(MY_WIN_CLASS),
		TEXT("�����œo�^�����E�B���h�E�N���X"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,	//�f�t�H���g�̒l���g�p
		CW_USEDEFAULT,	//�f�t�H���g�̒l���g�p
		CW_USEDEFAULT,	//�f�t�H���g�̒l���g�p
		CW_USEDEFAULT,	//�f�t�H���g�̒l���g�p
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
		//�E�B���h�E�쐬���A�ŏ��ɍs���u�������v�ɂ��g����
		//+++++++++++++++++++++++++++++++++++++++++++++
		
		LPCREATESTRUCT lpcsWnd;			//�쐬����E�B���h�E�̏�񂪓���\���̂̃|�C���^���쐬
		lpcsWnd = (LPCREATESTRUCT)lp;	//�쐬����E�B���h�E�̏����擾

		//�E�B���h�E�̃^�C�g����\��
		MessageBoxW(NULL,TEXT("�����ŕϐ��̒l�Ȃǂ��������ł���"), lpcsWnd->lpszName,MB_OK);
		
		//�E�B���h�E�𐶐�����Ƃ��́A0��Ԃ�
		return 0;

	case WM_DESTROY:
		//�E�B���h�E���j�����ꂽ(�Ȃ��Ȃ���)�Ƃ�

		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�
		PostQuitMessage(0);
		return 0;
	}

	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}
*/