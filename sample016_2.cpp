/*����T�����Q�[�����쐬���悤��
���L����ƒ��ӎ����͈ȉ��̒��ɂ���܂��B�Q�l�ɂ��Ă��������B
  �w�����L�T�[�o\�S��\41.G1_Win32API

 �P�D�O���[�o���ϐ��Ɉȉ���ǉ�����
	int otakara_MAX = 3;				//����̐�MAX
	int otakara_cnt = 0;				//����̐����J�E���g

	POINT pt_otakara1 = { 250,250 };	//����̍��W�P
	POINT pt_otakara2 = { 300,300 };	//����̍��W�Q
	POINT pt_otakara3 = { 400,400 };	//����̍��W�R

	int otakara_find1 = 0;				//����������������f�P
	int otakara_find2 = 0;				//����������������f�Q
	int otakara_find3 = 0;				//����������������f�R

�Q�D�`�悷��֐��y���܂��z��ǉ�����
	//------------------------------------------------
	//�`�悷��֐��y���܂��z
	//------------------------------------------------
	void MY_DRAW_OMAKE(HDC hdc,HWND hwnd)
	{
		//��ʂ̑傫���̕����������ϐ�
		TCHAR Str_otakara[64];

		//TEXTMETRIC�F�t�H���g�̏ڍ׏��������g���b�N�X�\����
		TEXTMETRIC tm;

		//�t�H���g�̏ڍ׏����擾
		GetTextMetrics(hdc, &tm);

		//������`�敔���̔w�i����������
		SetBkMode(hdc, OPAQUE);					//�w�i��h��Ԃ�

		SetTextColor(hdc, RGB(0, 0, 0));		//�����F�𔒂ɂ���
		SetBkColor(hdc, RGB(255, 255, 255));	//�w�i�F�����ɂ���

		//����̐��𐮌`
		wsprintf(
			Str_otakara,
			TEXT("����̐��F�c��%02d��"),
			otakara_MAX - otakara_cnt);

		//��ʂ̑傫����`��
		TextOut(hdc, 0, tm.tmHeight * 2, Str_otakara, lstrlen(Str_otakara));

		//����P�̏ꏊ�𔻒�
		int basho1 = 10;	//����̏ꏊ�𒲐�
		if (otakara_find1 == 0 &&					//�܂�������Q�b�g���Ă��Ȃ��Ƃ�
			pt_Start.x > pt_otakara1.x - basho1 &&	//ϳ����ق�X���W > ������W�̉E
			pt_Start.x < pt_otakara1.x + basho1 &&	//ϳ����ق�X���W < ������W�̍�
			pt_Start.y > pt_otakara1.y - basho1 &&	//ϳ����ق�X���W > ������W�̏�
			pt_Start.y < pt_otakara1.y + basho1)	//ϳ����ق�X���W < ������W�̉�
		{
			//������Q�b�g�ς݂ɂ���
			otakara_find1 = 1;







			//���b�Z�[�W�{�b�N�X��\��
			MessageBox(
				hwnd,
				TEXT("�y����P�z���Q�b�g�I"),
				TEXT("GET!!"),
				MB_OK);

			//����̐����P�J�E���g�A�b�v����
			otakara_cnt++;
		}

		//����Q�̏ꏊ�𔻒�
		int basho2 = 10;	//����̏ꏊ�𒲐�
		if (otakara_find2 == 0 &&					//�܂�������Q�b�g���Ă��Ȃ��Ƃ�
			pt_Start.x > pt_otakara2.x - basho2 &&	//ϳ����ق�X���W > ������W�̉E
			pt_Start.x < pt_otakara2.x + basho2 &&	//ϳ����ق�X���W < ������W�̍�
			pt_Start.y > pt_otakara2.y - basho2 &&	//ϳ����ق�X���W > ������W�̏�
			pt_Start.y < pt_otakara2.y + basho2)	//ϳ����ق�X���W < ������W�̉�
		{
			//������Q�b�g�ς݂ɂ���
			otakara_find2 = 1;

			//���b�Z�[�W�{�b�N�X��\��
			MessageBox(
				hwnd,
				TEXT("�y����Q�z���Q�b�g�I"),
				TEXT("GET!!"),
				MB_OK);

			//����̐����P�J�E���g�A�b�v����
			otakara_cnt++;
		}

		//����R�̏ꏊ�𔻒�
		int basho3 = 10;	//����̏ꏊ�𒲐�
		if (otakara_find3 == 0 &&					//�܂�������Q�b�g���Ă��Ȃ��Ƃ�
			pt_Start.x > pt_otakara3.x - basho3 &&	//ϳ����ق�X���W > ������W�̉E
			pt_Start.x < pt_otakara3.x + basho3 &&	//ϳ����ق�X���W < ������W�̍�
			pt_Start.y > pt_otakara3.y - basho3 &&	//ϳ����ق�X���W > ������W�̏�
			pt_Start.y < pt_otakara3.y + basho3)	//ϳ����ق�X���W < ������W�̉�
		{
			//������Q�b�g�ς݂ɂ���
			otakara_find3 = 1;

			//���b�Z�[�W�{�b�N�X��\��
			MessageBox(
				hwnd,
				TEXT("�y����R�z���Q�b�g�I"),
				TEXT("GET!!"),
				MB_OK);

			//����̐����P�J�E���g�A�b�v����
			otakara_cnt++;
		}

		//���ׂĂ̂�����������Ƃ�
		if (otakara_MAX == otakara_cnt)
		{
			//���b�Z�[�W�{�b�N�X�̖߂�l(����)������ϐ�
			int Kekka;

			//���b�Z�[�W�{�b�N�X��\��
			Kekka = MessageBox(
				hwnd,
				TEXT("�����S�ăQ�b�g���܂���\n���Z�b�g���܂����H"),
				TEXT("Complete"),
				MB_YESNO);

			//�u�͂��v�{�^�����������Ƃ�
			if (Kekka == IDYES)
			{
				//���b�Z�[�W�{�b�N�X��\��
				MessageBox(
					hwnd,
					TEXT("����������Z�b�g���܂�"),
					TEXT("ReSet"),
					MB_OK);

				//��������Z�b�g����
				otakara_cnt = 0;
				otakara_find1 = 0;
				otakara_find2 = 0;
				otakara_find3 = 0;

			}
			//�u�������v�{�^�����������Ƃ�
			else if (Kekka == IDNO)
			{
				//���b�Z�[�W�{�b�N�X��\��
				MessageBox(
					hwnd,
					TEXT("�A�v���P�[�V�������I�����܂��B"),
					TEXT("Quit"),
					MB_OK);

				//���b�Z�[�W�𑗂�
				SendMessage(
					hwnd,		//�E�B���h�E�n���h��
					WM_CLOSE,	//���郁�b�Z�[�W�FWM_CLOSE
					0,			//���b�Z�[�W�̏�񂻂̂P
					0);			//���b�Z�[�W�̏�񂻂̂Q
			}
		}

	}

�R�D�v���g�^�C�v�錾��ǉ�����
	//��ʂɕ`�悷��
	void MY_DRAW(HDC);

	//��ʂɕ`�悷��(���܂�)
	void MY_DRAW_OMAKE(HDC, HWND);

�S�D�yWM_PAINT�z���b�Z�[�W���֒ǉ�����
	��MY_DRAW(hdc);�̉��ɒǉ�����

	//�`��(���܂�)
	MY_DRAW_OMAKE(hdc,hwnd);

 ���v���O���������͂ł�����A���s�����悤�I��*/


/*
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
#define WIN_X		100		//���̈ʒu
#define WIN_Y		100		//�c�̈ʒu
#define WIN_WIDTH	500		//��
#define WIN_HEIGHT	500		//����

//�G���[���b�Z�[�W
#define ERR_MSG_TITLE			TEXT("ERROR")
#define ERR_MSG_NO_WIN_CLASS	TEXT("�E�B���h�E�N���X���o�^�ł��܂���ł���\n�v���O�������I�����܂�")
#define ERR_MSG_NO_WIN_CREATE	TEXT("�E�B���h�E���쐬�ł��܂���ł���\n�v���O�������I�����܂�")

//�E�B���h�E�̃T�C�Y��ύX�ł��Ȃ�����
//���́AWS_OVERLAPPEDWINDOW����AWS_THICKFRAME �� WS_MAXIMIZEBOX�𔲂�������
#define WS_STATIC_WINDOW	WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//�E�B���h�E�̃^�C�g�����Ȃ���
#define WS_NOT_TITLE WS_POPUP | WS_BORDER

//+++++++++++++++++++++++++++++++++++++++++++++
//�񋓌^
//+++++++++++++++++++++++++++++++++++++++++++++
//�E�B���h�E�̃T�C�Y��ύX�ł��邩
enum WIN_MODE {
	WIN_RESZ_OK,	//0�F�E�B���h�E�T�C�Y�̕ύX���ł���
	WIN_RESZ_NG,	//1�F�E�B���h�E�T�C�Y�̕ύX���ł��Ȃ�
	WIN_NO_TITLE	//2�F�E�B���h�E�̃^�C�g�����Ȃ���
};

//+++++++++++++++++++++++++++++++++++++++++++++
//�v���g�^�C�v�錾
//+++++++++++++++++++++++++++++++++++++++++++++
//�E�B���h�E�v���V�[�W��
LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);

//�����̃E�B���h�E�N���X���쐬����
WNDCLASS MY_CreateWindowClass(HINSTANCE);

//�E�B���h�E�𐶐�����
HWND MY_CreateWindow(HINSTANCE, int);

//�N���C�A���g�̈��ݒ肷��
VOID MY_SetClientSize(HWND);

//�����������R�D�v���g�^�C�v�錾��ǉ����遥��������

//��ʂɕ`�悷��
void MY_DRAW(HDC);

//��ʂɕ`�悷��(���܂�)
void MY_DRAW_OMAKE(HDC, HWND);

//�����������R�D�v���g�^�C�v�錾��ǉ����遣��������

//+++++++++++++++++++++++++++++++++++++++++++++
//�O���[�o���ϐ��̐錾�Ə�����
//+++++++++++++++++++++++++++++++++++++++++++++
//�}�E�X�̍��W���Ǘ�����\����
POINT pt_Start = { 0,0 };

//�E�B���h�E�T�C�Y���Ǘ�����\����
RECT window_Size = { 0, 0, 0, 0 };

//�̈���Ǘ�����\����
RECT rect_w;	//�E�B���h�E�̈���Ǘ�
RECT rect_c;	//�N���C�A���g�̈���Ǘ�

//�E�B���h�E�̃��[�h��ݒ�
int win_mode = (int)WIN_RESZ_OK;

//���������� �P�D�O���[�o���ϐ��Ɉȉ���ǉ����遥��������

int otakara_MAX = 3;				//����̐�MAX
int otakara_cnt = 0;				//����̐����J�E���g

POINT pt_otakara1 = { 250,250 };	//����̍��W�P
POINT pt_otakara2 = { 300,300 };	//����̍��W�Q
POINT pt_otakara3 = { 400,400 };	//����̍��W�R

int otakara_find1 = 0;				//����������������f�P
int otakara_find2 = 0;				//����������������f�Q
int otakara_find3 = 0;				//����������������f�R

//���������� �P�D�O���[�o���ϐ��Ɉȉ���ǉ����遣��������

//+++++++++++++++++++++++++++++++++++++++++++++
//�v���O�����ōŏ��Ɏ��s�����֐�
//+++++++++++++++++++++++++++++++++++++++++++++
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{

	//�X�̃E�B���h�E�����ʂ���l(�E�B���h�E�n���h��)
	HWND hwnd;

	//�E�B���h�E�N���X���Ǘ�����\����
	WNDCLASS winc;

	//���b�Z�[�W��ۑ�����\����
	MSG msg;

	//�����̃E�B���h�E�N���X���쐬����֐�
	winc = MY_CreateWindowClass(hInstance);

	//�E�B���h�E�N���X��o�^����
	if (!RegisterClass(&winc))
	{
		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(NULL, ERR_MSG_NO_WIN_CLASS, ERR_MSG_TITLE, MB_OK);

		//�o�^���ł��Ȃ�������A�v���O�������I������
		return 0;
	}

	//�E�B���h�E�𐶐�����(�T�C�Y�ύX�Ȃ�)
	hwnd = MY_CreateWindow(hInstance, win_mode);

	//�E�B���h�E����������Ȃ������Ƃ�
	if (hwnd == NULL)
	{
		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(NULL, ERR_MSG_NO_WIN_CREATE, ERR_MSG_TITLE, MB_OK);

		//�������I��������
		return 0;
	}

	//�N���C�A���g�̈���Đݒ肷��
	MY_SetClientSize(hwnd);

	//�E�B���h�E��\��
	ShowWindow(hwnd, SW_SHOW);

	//���b�Z�[�W���󂯎�葱����
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//+++++++++++++++++++++++++++++++++++++++++++++
//�����̃E�B���h�E�N���X���쐬����֐�
//+++++++++++++++++++++++++++++++++++++++++++++
WNDCLASS MY_CreateWindowClass(HINSTANCE hInstance)
{
	//�E�B���h�E�N���X���쐬
	WNDCLASS winc;

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

	//�E�B���h�E�N���X��Ԃ�
	return winc;
}

//+++++++++++++++++++++++++++++++++++++++++++++
//�E�B���h�E�𐶐�����֐�
//+++++++++++++++++++++++++++++++++++++++++++++
HWND MY_CreateWindow(HINSTANCE hInstance, int mode)
{
	//�X�̃E�B���h�E�����ʂ���l(�E�B���h�E�n���h��)
	HWND hwnd;

	switch (mode)
	{
	case WIN_RESZ_OK:
		//�E�B���h�E�̃T�C�Y�ύX���ł���

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
		break;

	case WIN_RESZ_NG:
		//�E�B���h�E�̃T�C�Y�ύX���ł��Ȃ�

		hwnd = CreateWindow(
			TEXT(MY_WIN_CLASS),
			TEXT("�����œo�^�����E�B���h�E�N���X"),
			WS_STATIC_WINDOW,
			WIN_X,
			WIN_Y,
			WIN_WIDTH,
			WIN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
		break;

	case WIN_NO_TITLE:
		//�E�B���h�E�̃^�C�g����\�����Ȃ�

		hwnd = CreateWindow(
			TEXT(MY_WIN_CLASS),
			TEXT("�����œo�^�����E�B���h�E�N���X"),
			WS_NOT_TITLE,
			WIN_X,
			WIN_Y,
			WIN_WIDTH,
			WIN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
		break;
	}

	//�E�B���h�E�n���h����Ԃ�
	return hwnd;
}

//------------------------------------------------
//�N���C�A���g�̈�̐ݒ�
//���N���C�A���g�̈�́A�^�C�g����E�B���h�E�̐��Ȃǂ�
//�@�ݒ肵�������l���猸�����l�̑傫���ŕ\������Ă��܂�
//------------------------------------------------
VOID MY_SetClientSize(HWND hWnd)
{
	//�̈���Ǘ�����\����
	RECT rect_set;

	//�ŏ��̃N���C�A���g�̗̈��ݒ�
	rect_set.top = WIN_Y;
	rect_set.left = WIN_X;
	rect_set.bottom = WIN_HEIGHT;
	rect_set.right = WIN_WIDTH;

	//�E�B���h�E�̈���擾
	GetWindowRect(hWnd, &rect_w);

	//�N���C�A���g�̈���擾
	GetClientRect(hWnd, &rect_c);

	//�N���C�A���g�̈�̕����C��
	//�@�@�@�@�@�@�@�@((�E�C���h�E�̉��T�C�Y)       - (�N���C�A���g�̉��T�C�Y));
	//�E�C���h�E�̉��T�C�Y - �N���C�A���g�̉��T�C�Y �� �E�C���h�E�g�̉��������܂�
	//���߂��E�C���h�E�g�̕����A���X�̕��ɉ��Z����
	rect_set.right += ((rect_w.right - rect_w.left) - (rect_c.right - rect_c.left));

	//�N���C�A���g�̈�̍������C��
	//                 ((�E�C���h�E�̏c�T�C�Y)       - (�N���C�A���g�̏c�T�C�Y));
	//�E�C���h�E�̏c�T�C�Y - �N���C�A���g�̏c�T�C�Y �� �E�C���h�E�g�̏c�������܂�
	//���߂��E�C���h�E�g�̍������A���X�̍����ɉ��Z����
	rect_set.bottom += ((rect_w.bottom - rect_w.top) - (rect_c.bottom - rect_c.top));

	//�N���C�A���g�̈�̏ꏊ�ƃT�C�Y���Đݒ�
	SetWindowPos(
		hWnd,					//�E�B���h�E�n���h��
		HWND_TOP,				//�E�B���h�E��O�̖ʂɂ���
		rect_set.left,			//�E�B���h�E��X���W
		rect_set.top,			//�E�B���h�E��Y���W
		rect_set.right,			//�E�B���h�E�̕�
		rect_set.bottom,		//�E�B���h�E�̍���
		SWP_SHOWWINDOW);		//�E�B���h�E��\��
}

//------------------------------------------------
//�`�悷��֐�
//------------------------------------------------
void MY_DRAW(HDC hdc)
{
	//�}�E�X�̍��W�̕����������ϐ�
	TCHAR Str_X_Y[64];

	//��ʂ̑傫���̕����������ϐ�
	TCHAR Str_CX_CY[64];

	//TEXTMETRIC�F�t�H���g�̏ڍ׏��������g���b�N�X�\����
	TEXTMETRIC tm;

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm);

	//�����̕`�敔���ɂ��̂܂܏㏑������
	//SetBkMode(hdc, TRANSPARENT);			//�w�i��h��Ԃ��Ȃ�

	//������`�敔���̔w�i����������
	SetBkMode(hdc, OPAQUE);					//�w�i��h��Ԃ�

	SetTextColor(hdc, RGB(0, 0, 0));		//�����F�𔒂ɂ���
	SetBkColor(hdc, RGB(255, 255, 255));	//�w�i�F�����ɂ���

	//�}�E�X�̍��W�𐮌`
	wsprintf(Str_X_Y, TEXT("�}�E�X�̈ʒu(X:%03d,Y:%03d)"), pt_Start.x, pt_Start.y);

	//�}�E�X�̍��W��`��
	TextOut(hdc, 0, tm.tmHeight * 0, Str_X_Y, lstrlen(Str_X_Y));

	//��ʂ̑傫���𐮌`
	wsprintf(Str_CX_CY, TEXT("��ʂ̑傫��(X:%03d,Y:%03d)"), window_Size.right, window_Size.bottom);

	//��ʂ̑傫����`��
	TextOut(hdc, 0, tm.tmHeight * 1, Str_CX_CY, lstrlen(Str_CX_CY));
}

//�����������Q�D�`�悷��֐��y���܂��z��ǉ����遥��������
//------------------------------------------------
//�`�悷��֐��y���܂��z
//------------------------------------------------
void MY_DRAW_OMAKE(HDC hdc, HWND hwnd)
{
	//��ʂ̑傫���̕����������ϐ�
	TCHAR Str_otakara[64];

	//TEXTMETRIC�F�t�H���g�̏ڍ׏��������g���b�N�X�\����
	TEXTMETRIC tm;

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm);

	//������`�敔���̔w�i����������
	SetBkMode(hdc, OPAQUE);					//�w�i��h��Ԃ�

	SetTextColor(hdc, RGB(0, 0, 0));		//�����F�𔒂ɂ���
	SetBkColor(hdc, RGB(255, 255, 255));	//�w�i�F�����ɂ���

	//����̐��𐮌`
	wsprintf(
		Str_otakara,
		TEXT("����̐��F�c��%02d��"),
		otakara_MAX - otakara_cnt);

	//����̐���`��
	TextOut(hdc, 0, tm.tmHeight * 2, Str_otakara, lstrlen(Str_otakara));

	//����P�̏ꏊ�𔻒�
	int basho1 = 10;	//����̏ꏊ�𒲐�
	if (otakara_find1 == 0 &&					//�܂�������Q�b�g���Ă��Ȃ��Ƃ�
		pt_Start.x > pt_otakara1.x - basho1 &&	//�}�E�X�J�[�\����X���W > ������W�̉E
		pt_Start.x < pt_otakara1.x + basho1 &&	//�}�E�X�J�[�\����X���W < ������W�̍�
		pt_Start.y > pt_otakara1.y - basho1 &&	//�}�E�X�J�[�\����X���W > ������W�̏�
		pt_Start.y < pt_otakara1.y + basho1)	//�}�E�X�J�[�\����X���W < ������W�̉�
	{
		//������Q�b�g�ς݂ɂ���
		otakara_find1 = 1;

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�y����P�z���Q�b�g�I"),
			TEXT("GET!!"),
			MB_OK);

		//����̐����P�J�E���g�A�b�v����
		otakara_cnt++;
	}

	//����Q�̏ꏊ�𔻒�
	int basho2 = 10;	//����̏ꏊ�𒲐�
	if (otakara_find2 == 0 &&					//�܂�������Q�b�g���Ă��Ȃ��Ƃ�
		pt_Start.x > pt_otakara2.x - basho2 &&	//�}�E�X�J�[�\����X���W > ������W�̉E
		pt_Start.x < pt_otakara2.x + basho2 &&	//�}�E�X�J�[�\����X���W < ������W�̍�
		pt_Start.y > pt_otakara2.y - basho2 &&	//�}�E�X�J�[�\����X���W > ������W�̏�
		pt_Start.y < pt_otakara2.y + basho2)	//�}�E�X�J�[�\����X���W < ������W�̉�
	{
		//������Q�b�g�ς݂ɂ���
		otakara_find2 = 1;

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�y����Q�z���Q�b�g�I"),
			TEXT("GET!!"),
			MB_OK);

		//����̐����P�J�E���g�A�b�v����
		otakara_cnt++;
	}

	//����R�̏ꏊ�𔻒�
	int basho3 = 10;	//����̏ꏊ�𒲐�
	if (otakara_find3 == 0 &&					//�܂�������Q�b�g���Ă��Ȃ��Ƃ�
		pt_Start.x > pt_otakara3.x - basho3 &&	//�}�E�X�J�[�\����X���W > ������W�̉E
		pt_Start.x < pt_otakara3.x + basho3 &&	//�}�E�X�J�[�\����X���W < ������W�̍�
		pt_Start.y > pt_otakara3.y - basho3 &&	//�}�E�X�J�[�\����X���W > ������W�̏�
		pt_Start.y < pt_otakara3.y + basho3)	//�}�E�X�J�[�\����X���W < ������W�̉�
	{
		//������Q�b�g�ς݂ɂ���
		otakara_find3 = 1;

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�y����R�z���Q�b�g�I"),
			TEXT("GET!!"),
			MB_OK);

		//����̐����P�J�E���g�A�b�v����
		otakara_cnt++;
	}

	//���ׂĂ̂�����������Ƃ�
	if (otakara_MAX = otakara_cnt)
	{
		//���b�Z�[�W�{�b�N�X�̖߂�l(����)������ϐ�
		int Kekka;

		//���b�Z�[�W�{�b�N�X��\��
		Kekka = MessageBox(
			hwnd,
			TEXT("�����S�ăQ�b�g���܂���\n���Z�b�g���܂����H"),
			TEXT("Complete"),
			MB_YESNO);

		//�u�͂��v�{�^�����������Ƃ�
		if (Kekka == IDYES)
		{
			//���b�Z�[�W�{�b�N�X��\��
			MessageBox(
				hwnd,
				TEXT("����������Z�b�g���܂�"),
				TEXT("ReSet"),
				MB_OK);

			//��������Z�b�g����
			otakara_cnt = 0;
			otakara_find1 = 0;
			otakara_find2 = 0;
			otakara_find3 = 0;

		}
		//�u�������v�{�^�����������Ƃ�
		else if (Kekka == IDNO)
		{
			//���b�Z�[�W�{�b�N�X��\��
			MessageBox(
				hwnd,
				TEXT("�A�v���P�[�V�������I�����܂��B"),
				TEXT("Quit"),
				MB_OK);

			//���b�Z�[�W�𑗂�
			SendMessage(
				hwnd,		//�E�B���h�E�n���h��
				WM_CLOSE,	//���郁�b�Z�[�W�FWM_CLOSE
				0,			//���b�Z�[�W�̏�񂻂̂P
				0);			//���b�Z�[�W�̏�񂻂̂Q
		}
	}
}


//�����������Q�D�`�悷��֐��y���܂��z��ǉ����遣��������

//------------------------------------------------
//�E�B���h�E�v���V�[�W���֐�
//------------------------------------------------
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//HDC�F�f�o�C�X�R���e�L�X�g�̃n���h��
	HDC hdc;

	//PAINTSTRUCT�F�E�B���h�E���Ƃ̕`������Ǘ�����\����
	PAINTSTRUCT ps;

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

		//�`��
		MY_DRAW(hdc);

		//�����������S�D�yWM_PAINT�z���b�Z�[�W���֒ǉ����遥��������

		//�`��(���܂�)
		MY_DRAW_OMAKE(hdc, hwnd);

		//�����������S�D�yWM_PAINT�z���b�Z�[�W���֒ǉ����遣��������

		//�ۑ������f�o�C�X�R���e�L�X�𕜌�����
		RestoreDC(hdc, -1);

		//�f�o�C�X�R���e�L�X�g�̃n���h�����J������
		EndPaint(hwnd, &ps);

		return 0;

	case WM_LBUTTONDOWN:
		//�}�E�X�̍��{�^���������Ă���Ƃ�

		//�^�C�g���o�[���Ȃ��Ƃ�
		if (win_mode == WIN_NO_TITLE)
		{
			//���b�Z�[�W��������
			PostMessage(
				hwnd,				//�E�B���h�E�n���h��
				WM_NCLBUTTONDOWN,	//��N���C�A���g�̈�����N���b�N����
				HTCAPTION,			//�^�C�g���o�[���N���b�N����
				MAKELPARAM(0, 0));	//�}�E�X�̍��W�F0,0

			return 0;
		}

		//�N���C�A���g�̈�O�ł��}�E�X�̓����̊Ď����J�n
		SetCapture(hwnd);

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

		//�^�C�g���o�[���Ȃ��Ƃ�
		if (win_mode == WIN_NO_TITLE)
		{
			return 0;
		}

		//�N���C�A���g�̈�O�ł��}�E�X�̓����̊Ď����I��
		ReleaseCapture();

		//�������[�W�����𔭐�
		InvalidateRect(hwnd, NULL, FALSE);

		//��ʂ��A�����ɍĕ`�悷��
		UpdateWindow(hwnd);

		break;

	case WM_RBUTTONDOWN:
		//�}�E�X�̉E�{�^�����������Ƃ�

		//�^�C�g���o�[���Ȃ��Ƃ�
		if (win_mode == WIN_NO_TITLE)
		{
			//���b�Z�[�W�𑗂�
			SendMessage(
				hwnd,		//�E�B���h�E�n���h��
				WM_CLOSE,	//���郁�b�Z�[�W�FWM_CLOSE
				0,			//���b�Z�[�W�̏�񂻂̂P
				0);			//���b�Z�[�W�̏�񂻂̂Q

			return 0;
		}

		break;

	case WM_RBUTTONUP:
		//�}�E�X�̉E�{�^�����グ���Ƃ�

		break;

	case WM_MOUSEMOVE:
		//�}�E�X�J�[�\�����ړ������Ƃ�

		//�}�E�X�̍��W���擾
		//LPARAM lp�ɂ́A�}�E�X�̍��W�������Ă���
		//���̒��ŁA���16�r�b�g�ɂ́Ay���W�������Ă���
		//���̒��ŁA����16�r�b�g�ɂ́Ax���W�������Ă���

		//DWORD�^(32�r�b�g)�̉���WORD(16�r�b�g)�����o��
		pt_Start.x = LOWORD(lp);
		//DWORD�^(32�r�b�g)�̏��WORD(16�r�b�g)�����o��
		pt_Start.y = HIWORD(lp);

		//�N���C�A���g�̈�O�̑Ώ�
		if (pt_Start.x < window_Size.left)
			pt_Start.x = window_Size.left;

		if (pt_Start.x >= window_Size.right)
			pt_Start.x = window_Size.right - 1;

		if (pt_Start.y < window_Size.top)
			pt_Start.y = window_Size.top;

		if (pt_Start.y >= window_Size.bottom)
			pt_Start.y = window_Size.bottom - 1;

		//�������[�W�����𔭐�
		//OS(Windows)���AWM_PAINT�𒼐ڃE�B���h�E�v���V�[�W���ɑ���
		//�������[�W����(�̈�)�͍ĕ`�悳���
		InvalidateRect(hwnd, NULL, FALSE);

		//��ʂ��A�����ɍĕ`�悷��
		//WM_PAINT�𒼐ڃE�B���h�E�v���V�[�W���ɑ���֐�
		UpdateWindow(hwnd);

		break;
	case WM_SIZE:
		//��ʂ̃T�C�Y���ς�����Ƃ�

		//�E�B���h�E�̃T�C�Y���擾
		//LPARAM lp�ɂ́A�E�C���h�E�̃T�C�Y�������Ă���
		//���̒��ŁA���16�r�b�g�ɂ́A�����̃T�C�Y�������Ă���
		//���̒��ŁA����16�r�b�g�ɂ́A���̃T�C�Y�������Ă���

		//DWORD�^(32�r�b�g)�̏��WORD(16�r�b�g)�����o��
		window_Size.bottom = HIWORD(lp);
		//DWORD�^(32�r�b�g)�̉���WORD(16�r�b�g)�����o��
		window_Size.right = LOWORD(lp);

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

		break;

	case WM_CLOSE:
		//����{�^�����������Ƃ�

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�E�B���h�E���I�������܂�"),
			TEXT("CLOSE"),
			MB_OK);

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
*/