//+++++++++++++++++++++++++++++++++++++++++++++
//
//+++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++
//�w�b�_�[�t�@�C���ǂݍ���
//+++++++++++++++++++++++++++++++++++++++++++++
#include <windows.h>

//+++++++++++++++++++++++++++++++++++++++++++++
//�}�N����`
//+++++++++++++++++++++++++++++++++++++++++++++

//�����ō쐬���鳨��޳�׽�̖��O
#define MY_WIN_CLASS "MY_WIN_CLASS"	

//�E�B���h�E�̏ꏊ��傫����ݒ�
#define WIN_X 100		//���̈ʒu
#define WIN_Y 100		//�c�̈ʒu
#define WIN_WIDTH 500	//��
#define WIN_HEIGHT 500	//����

//+++++++++++++++++++++++++++++++++++++++++++++
//�v���g�^�C�v�錾
//+++++++++++++++++++++++++++++++++++++++++++++

//�E�B���h�E�v���V�[�W��
LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);

//+++++++++++++++++++++++++++++++++++++++++++++
//�O���[�o���ϐ��̐錾�Ə�����
//+++++++++++++++++++++++++++++++++++++++++++++

//�}�E�X�̃{�^���������Ă��邩������ϐ�
BOOL isDrag = FALSE;

//�}�E�X�̍��W���Ǘ�����\����
POINT pt_Start = { 0,0 };

//�E�B���h�E�T�C�Y���Ǘ�����\����
SIZE window_Size = { 0,0 };

//�̈���Ǘ�����\����
RECT rect_c;	//�N���C�A���g�̈���Ǘ�

				//+++++++++++++++++++++++++++++++++++++++++++++
				//�v���O�����ōŏ��Ɏ��s�����֐�
				//+++++++++++++++++++++++++++++++++++++++++++++
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
	HBRUSH brush;

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
	//�E�B���h�E�X�^�C����WS_VISIBLE���w�肵����AWM_PAINT�𑗂�
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

	//�N���C�A���g�̈���擾
	GetClientRect(hwnd, &rect_c);

	//�E�B���h�E��\��
	//SW_SHOW���w�肵����AWM_PAINT�𑗂�
	ShowWindow(
		hwnd,		//�\������E�C���h�E�n���h��
		SW_SHOW		//���݂̈ʒu�ƃT�C�Y�ŕ\��
	);

	//WM_PAINT�𒼐ڃE�B���h�E�v���V�[�W���ɑ���
	//UpdateWindow(hwnd);

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

	//�}�E�X�̍��W�̕����������ϐ�
	TCHAR StrBuf[64];

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


		//�_��`��
		SetPixel(hdc, pt_Start.x, pt_Start.y, RGB(0, 0, 0));

		//�}�E�X�̍��W�𐮌`
		wsprintf(StrBuf, TEXT("�}�E�X�̈ʒu(X:%03d,Y:%03d)"), pt_Start.x, pt_Start.y);

		//�����̕`�敔���ɂ��̂܂܏㏑������
		//SetBkMode(hdc, TRANSPARENT);			//�w�i��h��Ԃ��Ȃ�

		//������`�敔���̔w�i����������
		SetBkMode(hdc, OPAQUE);					//�w�i��h��Ԃ�

		SetTextColor(hdc, RGB(0, 0, 0));		//�����F�𔒂ɂ���
		SetBkColor(hdc, RGB(255, 255, 255));	//�w�i�F�����ɂ���

												//�}�E�X�̍��W��`��
		DrawText(hdc, StrBuf, -1, &rect_c, DT_LEFT);

		//�ۑ������f�o�C�X�R���e�L�X�𕜌�����
		RestoreDC(hdc, -1);

		//�f�o�C�X�R���e�L�X�g�̃n���h�����J������
		EndPaint(hwnd, &ps);

		return 0;
	case WM_LBUTTONDOWN:
		//�}�E�X�̍��{�^���������Ă���Ƃ�

		//�}�E�X�̍��W���擾
		//LPARAM lp�ɂ́A�}�E�X�̍��W�������Ă���
		//���̒��ŁA���16�r�b�g�ɂ́Ay���W�������Ă���
		//���̒��ŁA����16�r�b�g�ɂ́Ax���W�������Ă���

		//DWORD�^(32�r�b�g)�̏��WORD(16�r�b�g)�����o��
		pt_Start.y = HIWORD(lp);
		//DWORD�^(32�r�b�g)�̉���WORD(16�r�b�g)�����o��
		pt_Start.x = LOWORD(lp);

		//�}�E�X�̃{�^�����u�������v���������
		if (isDrag == FALSE)
		{
			isDrag = TRUE;
		}

		//�������[�W�����𔭐�
		InvalidateRect(
			hwnd,	//�������[�W�����𔭐�������E�B���h�E�n���h��
			NULL,	//����������̈�FNULL�Ȃ�N���C�A���g�̈�S��
			FALSE);	//TRUE�F�w�i������/FALSE�F�w�i�����̂܂܎c��

					//��ʂ��A�����ɍĕ`�悷��
					//WM_PAINT�𒼐ڃE�B���h�E�v���V�[�W���ɑ���֐�
		UpdateWindow(hwnd);

		break;






	case WM_LBUTTONUP:
		//�}�E�X�̍��{�^�����グ���Ƃ�

		//�}�E�X�̃{�^�����u�グ���v���������
		if (isDrag == TRUE)
		{
			isDrag = FALSE;
		}

		//�������[�W�����𔭐�
		//OS(Windows)���AWM_PAINT�𒼐ڃE�B���h�E�v���V�[�W���ɑ���
		//�������[�W����(�̈�)�͍ĕ`�悳���
		InvalidateRect(hwnd, NULL, FALSE);

		//��ʂ��A�����ɍĕ`�悷��
		//WM_PAINT�𒼐ڃE�B���h�E�v���V�[�W���ɑ���֐�
		UpdateWindow(hwnd);

		break;

	case WM_MOUSEMOVE:
		//�}�E�X�J�[�\�����ړ������Ƃ�

		//DWORD�^(32�r�b�g)�̉���WORD(16�r�b�g)�����o��
		pt_Start.x = LOWORD(lp);
		//DWORD�^(32�r�b�g)�̏��WORD(16�r�b�g)�����o��
		pt_Start.y = HIWORD(lp);

		//�������[�W�����𔭐�
		InvalidateRect(hwnd, NULL, FALSE);

		//��ʂ��A�����ɍĕ`�悷��
		UpdateWindow(hwnd);

		break;
	case WM_SIZE:
		//��ʂ̃T�C�Y���ς�����Ƃ�

		//�E�B���h�E�̃T�C�Y���擾
		//LPARAM lp�ɂ́A�E�C���h�E�̃T�C�Y�������Ă���
		//���̒��ŁA���16�r�b�g�ɂ́A�����̃T�C�Y�������Ă���
		//���̒��ŁA����16�r�b�g�ɂ́A���̃T�C�Y�������Ă���

		//DWORD�^(32�r�b�g)�̏��WORD(16�r�b�g)�����o��
		window_Size.cy = HIWORD(lp);
		//DWORD�^(32�r�b�g)�̉���WORD(16�r�b�g)�����o��
		window_Size.cx = LOWORD(lp);

		//��ʂ��ǂ̂悤�ɕω����������f
		switch (wp)
		{
		case SIZE_RESTORED:
			//�E�B���h�E�T�C�Y���ς�����Ƃ�



			break;
		case SIZE_MINIMIZED:
			//�E�B���h�E���ŏ������ꂽ�Ƃ�

			break;

		case SIZE_MAXIMIZED:
			//�E�B���h�E���ő剻���ꂽ�Ƃ�

			break;
		}

		//��ʂ��ύX���ꂽ��AWM_PAINT�𒼐ڃE�B���h�E�v���V�[�W���ɑ��邽��
		//�ĕ`��̏����͕s�v�ł���

		//�������[�W�����𔭐�
		//InvalidateRect(hwnd, NULL, FALSE);

		//��ʂ��A�����ɍĕ`�悷��
		//UpdateWindow(hwnd);

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