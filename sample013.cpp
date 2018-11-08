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

	//HDC�F�f�o�C�X�R���e�L�X�g�̃n���h��
	HDC hdc;

	//PAINTSTRUCT�F�E�B���h�E���Ƃ̕`������Ǘ�����\����
	PAINTSTRUCT ps;

	//�\�����镶����̃|�C���^
	LPCTSTR DrawStr1 = TEXT("�\�����镶����P");
	LPCTSTR DrawStr2 = TEXT("�\�����镶����Q");
	LPCTSTR DrawStr3 = TEXT("�\�����镶����R");
	LPCTSTR DrawStr4 = TEXT("�\�����镶����S");

	switch (msg)
	{

	case WM_CREATE:
		//�E�B���h�E�̐�����������

		//�E�B���h�E�𐶐�����Ƃ��́A0��Ԃ�
		return 0;

	case WM_LBUTTONDOWN:
		//�}�E�X�̍��{�^�����������Ƃ�

		//�f�o�C�X�R���e�L�X�g�̃n���h�����擾
		hdc = GetDC(hwnd);

		//������`��
		TextOut(hdc,50,50, DrawStr1,lstrlen(DrawStr1));
		TextOut(hdc, 150, 150, DrawStr2, lstrlen(DrawStr2));

		//�f�o�C�X�R���e�L�X�g�̃n���h�������
		ReleaseDC(hwnd, hdc);

		break;

		
		
		
		
		
		
		
		
		
	case WM_PAINT:
		//+++++++++++++++++++++++++++++++++++++++++++++
		//�E�B���h�E�ɕ������ĕ`�悷��
		//+++++++++++++++++++++++++++++++++++++++++++++

		//��O�̃v���O�����ŁA��ʂ��ŏ����A�ő剻�����Ƃ��ɕ������������̂́A
		//��ʂ��������Ƃ��ɁA��ʂ̏�񂪏����Ă��܂�����B
		//��ʂ̏�񂪏�������Ԃ��u�������[�W�����v�ƌĂ�
		//�������[�W�������E�B���h�E�ɂ���ꍇ�A
		//Windows(OS) �� WM_PAINT ���b�Z�[�W�𔭍s����
		//WM_PAINT�ŁA�����̏ꏊ(�^�C�g����w�i�Ȃ�)�́u�����ȗ̈悾���v���ĕ`�悵�Ă���邪�A
		//�ׂ��ȂƂ���́A�v���O�����ł��ĕ`�悷�邱�Ƃ������K�v������
		//�������āA�������[�W�������ĕ`�悵�A��ʂ�L���ȏ�Ԃɂ���

		//�����ȏꏊ���Ăѕ`���Ȃ����āA�L��������(�f�o�C�X�R���e�L�X�g�̃n���h�����擾)
		hdc = BeginPaint(hwnd, &ps);

		//������`��
		TextOut(hdc, 10, 10, DrawStr3, lstrlen(DrawStr4));
		TextOut(hdc, 100, 100, DrawStr4, lstrlen(DrawStr4));

		//�f�o�C�X�R���e�L�X�g�̃n���h�����J������
		EndPaint(hwnd, &ps);
		
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