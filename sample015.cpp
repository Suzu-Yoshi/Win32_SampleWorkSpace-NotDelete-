/*
#include<windows.h>

#include<math.h>
#define PAI 3.14159


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
	brush = CreateSolidBrush(RGB(255, 255, 255));

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

	//�̈���Ǘ�����\����
	RECT rect_c;		//�N���C�A���g�̈�

	//PAINTSTRUCT�F�E�B���h�E���Ƃ̕`������Ǘ�����\����
	PAINTSTRUCT ps;

	//�F�����Ǘ����鐮��
	COLORREF get_col;	//�w�肵�����W�̐F���擾

	int cnt_x;
	int cnt_y;
	int cnt_c;
	double cnt_c_x;
	double cnt_c_y;

	int KANKAKU = 30;	//���̊Ԋu��ݒ�
	int haba = 20;		//�Q�����̕���ݒ�

	switch (msg)
	{

	case WM_CREATE:
		//�E�B���h�E�̐�����������

		//�E�B���h�E�𐶐�����Ƃ��́A0��Ԃ�
		return 0;












		
		
		
		
	case WM_PAINT:
		//�E�B���h�E�����ĕ`�悷��Ƃ�

		//�f�o�C�X�R���e�L�X�g�̃n���h�����擾
		hdc = BeginPaint(hwnd, &ps);

		//���݂̃f�o�C�X�R���e�L�X�g��ۑ�����
		SaveDC(hdc);

		//�N���C�A���g�̈���擾
		GetClientRect(hwnd, &rect_c);

		//��ʂ̕������ς��ɓ_��`�悷��
		for (cnt_x = 0; cnt_x < rect_c.right; cnt_x++)
		{
			//�_��`��
			SetPixel(hdc, cnt_x, KANKAKU, RGB(0, 0, 0));
		}

		//��ʂ̍��������ς��ɓ_��`�悷��
		for (cnt_y = 0; cnt_y < rect_c.bottom; cnt_y++)
		{
			//�_��`��
			SetPixel(hdc, KANKAKU, cnt_y, RGB(0, 0, 0));
		}

		//�g�ݍ��킹�Ċi�q����`��
		//���̐�
		for (cnt_y = 0; cnt_y < rect_c.bottom; cnt_y += KANKAKU)
		{
			for (cnt_x = 0; cnt_x < rect_c.right; cnt_x++)
			{
				//�_��`��
				SetPixel(hdc, cnt_x, cnt_y, RGB(0, 0, 0));
			}
		}
		//�c�̐�
		for (cnt_x = 0; cnt_x < rect_c.right; cnt_x += KANKAKU)
		{
			for (cnt_y = 0; cnt_y < rect_c.bottom; cnt_y++)
			{
				//�_��`��
				SetPixel(hdc, cnt_x, cnt_y, RGB(0, 0, 0));
			}
		}

		//�g�ݍ��킹�ăh�b�g����`��
		for (cnt_y = 0; cnt_y < rect_c.bottom; cnt_y += KANKAKU)
		{
			for (cnt_x = 0; cnt_x < rect_c.right; cnt_x += KANKAKU)
			{
				//�_��`��
				SetPixel(hdc, cnt_x, cnt_y, RGB(255, 255, 255));
			}
		}

		//�~��`��
		for (cnt_c = 0; cnt_c < 360; cnt_c++)
		{
			cnt_c_x = rect_c.right / 2 + KANKAKU * sin(cnt_c * PAI / 45);
			cnt_c_y = rect_c.bottom / 2 - KANKAKU * cos(cnt_c * PAI / 45);

			//�_��`��
			SetPixel(hdc, (int)cnt_c_x, (int)cnt_c_y, RGB(255, 0, 0));
		}

		
		
		
		
		
		//�����܂���`��
		for (cnt_c = 0; cnt_c < 360 * 15; cnt_c++)
		{
			cnt_c_x = rect_c.right / 2 + (cnt_c / haba)* sin(cnt_c * PAI / 180);
			cnt_c_y = rect_c.bottom / 2 - (cnt_c / haba)* cos(cnt_c * PAI / 180);

			//�_��`��
			SetPixel(hdc, (int)cnt_c_x, (int)cnt_c_y, RGB(0, 0, 255));
		}

		//�w�肵�����W�̐F���擾
		get_col = GetPixel(hdc, 0, 0);

		//�ۑ������f�o�C�X�R���e�L�X�𕜌�����
		RestoreDC(hdc, -1);

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