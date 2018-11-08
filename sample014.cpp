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

	//�w�i���[�h��ۑ�
	int bk_mode = 0;

	//�̈���Ǘ�����\����
	RECT rect_c;		//�N���C�A���g�̈�
	RECT rect_w;		//�E�B���h�E�̈�
	RECT rect_str;	//�\�����镶���̗̈�

	//TEXTMETRIC�F�t�H���g�̏ڍ׏��������g���b�N�X�\����
	TEXTMETRIC tm;

	//HDC�F�f�o�C�X�R���e�L�X�g�̃n���h��
	HDC hdc;

	//PAINTSTRUCT�F�E�B���h�E���Ƃ̕`������Ǘ�����\����
	PAINTSTRUCT ps;

	//�\�����镶����̃|�C���^
	LPCTSTR DrawStr1 = TEXT("�\������\n������P");
	LPCTSTR DrawStr2 = TEXT("�\������\n������Q");
	LPCTSTR DrawStr3 = TEXT("�\������\n������R");
	LPCTSTR DrawStr4 = TEXT("�\������\n������S�\������\n������S�\������\n������S�\������\n������S");

	switch (msg)
	{

	case WM_CREATE:
		//�E�B���h�E�̐�����������

		//�E�B���h�E�𐶐�����Ƃ��́A0��Ԃ�
		return 0;

		
		
		
		
		
		
		
		
		
		
		
	case WM_PAINT:
		//�E�B���h�E�����ĕ`�悷��Ƃ�

		//+++++++++++++++++++++++++++++++++++++++++++++
		//�E�B���h�E�ɕ������ĕ`�悷��
		//+++++++++++++++++++++++++++++++++++++++++++++

		//�f�o�C�X�R���e�L�X�g�̃n���h�����擾
		hdc = BeginPaint(hwnd, &ps);

		//�t�H���g�̏ڍ׏����擾
		GetTextMetrics(hdc, &tm);

		//+++++++++++++++++++++++++++++++++++++++++++++
		//���������s���ɕ`�悷��
		//+++++++++++++++++++++++++++++++++++++++++++++

		//������`��itm.tmHeight�́A�����̍�����\���j
		TextOut(hdc, 50, tm.tmHeight * 0 + 50, DrawStr1, lstrlen(DrawStr1));
		TextOut(hdc, 50, tm.tmHeight * 1 + 50, DrawStr2, lstrlen(DrawStr2));
		TextOut(hdc, 50, tm.tmHeight * 2 + 50, DrawStr3, lstrlen(DrawStr3));
		TextOut(hdc, 50, tm.tmHeight * 3 + 50, DrawStr4, lstrlen(DrawStr4));

		//������`��
		//tm.tmAveCharWidth�́A�������̕��ϓI�ȕ���\��
		TextOut(hdc, tm.tmAveCharWidth * lstrlen(DrawStr1) + 50, tm.tmHeight * 0 + 50, DrawStr1, lstrlen(DrawStr1));
		TextOut(hdc, tm.tmAveCharWidth * lstrlen(DrawStr2) + 50, tm.tmHeight * 1 + 50, DrawStr2, lstrlen(DrawStr2));
		//tm.tmMaxCharWidth�́A������̒��ōł��L������\��
		TextOut(hdc, tm.tmMaxCharWidth * lstrlen(DrawStr3) + 50, tm.tmHeight * 2 + 50, DrawStr3, lstrlen(DrawStr3));
		TextOut(hdc, tm.tmMaxCharWidth * lstrlen(DrawStr4) + 50, tm.tmHeight * 3 + 50, DrawStr4, lstrlen(DrawStr4));

		//+++++++++++++++++++++++++++++++++++++++++++++
		//�����F��ς���
		//+++++++++++++++++++++++++++++++++++++++++++++
		SetTextColor(hdc, RGB(255, 0, 0));	//�����F��Ԃɂ���
		TextOut(hdc, 50, tm.tmHeight * 4 + 50, DrawStr1, lstrlen(DrawStr1));

		SetTextColor(hdc, RGB(0, 255, 0));	//�����F��΂ɂ���
		TextOut(hdc, 50, tm.tmHeight * 5 + 50, DrawStr2, lstrlen(DrawStr2));
		TextOut(hdc, 50, tm.tmHeight * 6 + 50, DrawStr3, lstrlen(DrawStr3));

		SetTextColor(hdc, RGB(0, 0, 255));	//�����F��ɂ���
		TextOut(hdc, 50, tm.tmHeight * 7 + 50, DrawStr4, lstrlen(DrawStr4));

		//+++++++++++++++++++++++++++++++++++++++++++++
		//�w�i�F��ς���
		//+++++++++++++++++++++++++++++++++++++++++++++
		SetBkColor(hdc, RGB(255, 0, 0));	//�w�i�F��Ԃɂ���
		TextOut(hdc, 50, tm.tmHeight * 8 + 50, DrawStr1, lstrlen(DrawStr1));

		SetBkMode(hdc, OPAQUE);				//�w�i��h��Ԃ�
		SetBkColor(hdc, RGB(0, 255, 0));	//�w�i�F��΂ɂ���
		TextOut(hdc, 50, tm.tmHeight * 9 + 50, DrawStr2, lstrlen(DrawStr2));
		TextOut(hdc, 50, tm.tmHeight * 10 + 50, DrawStr3, lstrlen(DrawStr3));

		bk_mode = GetBkMode(hdc);			//���݂̔w�i���[�h���擾

		SetBkMode(hdc, TRANSPARENT);		//�w�i��h��Ԃ��Ȃ�
		SetBkColor(hdc, RGB(0, 0, 255));	//�w�i�F��ɂ���
		TextOut(hdc, 50, tm.tmHeight * 11 + 50, DrawStr4, lstrlen(DrawStr4));

		SetBkColor(hdc, RGB(127, 127, 127));//�w�i�F���D�F�ɂ���
		TextOut(hdc, 50, tm.tmHeight * 12 + 50, DrawStr4, lstrlen(DrawStr4));

		
		
		
		//+++++++++++++++++++++++++++++++++++++++++++++
		//�̈�ɕ�����`�悷��
		//+++++++++++++++++++++++++++++++++++++++++++++
		//�N���C�A���g�̈���擾
		GetClientRect(hwnd, &rect_c);

		//�E�B���h�E�̈���擾
		GetWindowRect(hwnd, &rect_w);

		//�@�@�E�C���h�E�̈�FPC�̉�ʂ̗̈�(�傫��)
		//�@�N���C�A���g�̈�F�A�v���P�[�V�����ŁA�`�悪�ł���̈�(�傫��)
		//��N���C�A���g�̈�F�^�C�g���o�[�ȂǁA�`��ł��Ȃ��̈�(�傫��)

		rect_str.left = 0;				//�����X���W(��)
		rect_str.top = 400;				//�����Y���W(�c)
		rect_str.right = 0 + 200;		//�E����X���W(��)
		rect_str.bottom = 400 + 200;	//�E����Y���W(�c)

		SetBkMode(hdc, OPAQUE);					//�w�i��h��Ԃ�
		SetTextColor(hdc, RGB(0, 0, 0));		//�����F�����ɂ���
		SetBkColor(hdc, RGB(255, 255, 255));	//�w�i�F�𔒂ɂ���

		//�������\��
		DrawText(
			hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
			DrawStr4,			//�`�悷�镶��
			-1,					//������̕������F-1�Ȃ玩���I�Ɍv�Z
			&rect_str,			//�`�悷��̈�
			DT_LEFT				//������
			| DT_WORDBREAK);	//�����񂪕\���ł��Ȃ��Ȃ�Ή��s

		//+++++++++++++++++++++++++++++++++++++++++++++
		//���݂̃f�o�C�X�R���e�L�X�g��ۑ��E��������
		//+++++++++++++++++++++++++++++++++++++++++++++

		//���݂̃f�o�C�X�R���e�L�X�g��ۑ�����
		SaveDC(hdc);
		
		SetTextColor(hdc, RGB(255, 255, 255));		//�����F�𔒂ɂ���
		SetBkColor(hdc, RGB(0, 0, 0));				//�w�i�F�����ɂ���

		//������`��
		TextOut(hdc, 0, 0, TEXT("HOZON_HOZON_HOZON"), lstrlen(TEXT("HOZON_HOZON_HOZON")));

		//�ۑ������f�o�C�X�R���e�L�X�𕜌�����
		RestoreDC(hdc, -1);	//-1�Ȃ�A1��O�ɕۑ������f�o�C�X�R���e�L�X�g�𕜌�

		//������`��
		TextOut(hdc, 0, tm.tmHeight * 1, TEXT("HUKUGEN_HUKUGEN"), lstrlen(TEXT("HUKUGEN_HUKUGEN")));

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