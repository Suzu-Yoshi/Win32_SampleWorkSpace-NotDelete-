/*�������Őݒ肵���t�H���g�ŁA������`�悵�悤��
/*���ӁF�v�����g��\(�o�b�N�X���b�V��)�́A���p�́��}�[�N�ł�*/
/*���L����ƒ��ӎ����͈ȉ��̒��ɂ���܂��B�Q�l�ɂ��Ă��������B
  �w�����L�T�[�o\�S��\41.G1_Win32API
  */
 /* 
�P�D�t�H���g�̃t�@�C�����v���W�F�N�g���ɒǉ�
	1-1.�\�����[�V�����G�N�X�v���[���[����
		�����̃v���W�F�N�g���E�N���b�N���A
		�G�N�X�v���[���[�Ńt�H���_���J�� ���N���b�N
	
	1-2.�w�����L�T�[�o\�S��\41.G1_Win32API�̒��ɂ���
		MY_FONT �Ƃ����t�H���_�� �R�s�[����
	
	1-3.�����̃v���W�F�N�g���ۑ�����Ă���t�H���_��
		MY_FONT �Ƃ����t�H���_�� �\��t����
		
	������͂Q��ނ�p�ӂ��܂���
	������A�����Ŏg�p�������t�H���g������ꍇ�́A���̃t�H���_�Ƀf�[�^�����ĉ�����
	�������āA�v���O������ǉ����Ȃ��ƁA�t�H���g���g�p�ł��Ȃ����Ƃ�Y��Ȃ��ŉ�����
	
�Q�D�}�N����`�Ɉȉ���ǉ�����

	#define ERR_MSG_NO_READ_FONT TEXT("�t�H���g��
	\�ǂݍ��߂܂���ł���\n�v���O�������I�����܂�")		//\(���p�́��}�[�N�ŁA�}�N����`�̉��s)
	
	//���ł�PC�ɃC���X�g�[������Ă���t�H���g
	#define FNT_MS_GOTHIC TEXT("�l�r �S�V�b�N")		//�l�r�͑S�p�A�󔒂͔��p�A�S�V�b�N�͑S�p
	#define FNT_MS_MINCHO TEXT("�l�r ����")			//�l�r�͑S�p�A�󔒂͔��p�A�����͑S�p
	
	//�ꎞ�I�ɓǂݍ��ރt�H���g
	#define FNT_JUD_PASS	TEXT(".\\MY_FONT\\JUDGE2.TTF")		//�t�H���g�̏ꏊ
	#define FNT_JUD_NAME	TEXT("Judge Hard")					//�t�H���g�̖��O

	#define FNT_TANU_PASS	TEXT(".\\MY_FONT\\TanukiMagic.ttf")	//�t�H���g�̏ꏊ
	#define FNT_TANU_NAME	TEXT("���ʂ������}�W�b�N")			//�t�H���g�̖��O

�R�D�y�v���g�^�C�v�錾�z��ǉ�����
	//�t�H���g��ݒ肷��
	HFONT MY_CreateFont(HDC, LPCTSTR, int, int, int);

	//�t�H���g��ݒ肵�ĕ`�悷��
	void MY_SetFontDraw(HDC);
	
�S�D�t�H���g��ݒ肵�ĕ�����`�悷��y�֐��z��ǉ�����
	//------------------------------------------------
	//�t�H���g��ݒ肵�ĕ�����`�悷��
	//------------------------------------------------
	void MY_SetFontDraw(HDC hdc)
	{
		//TEXTMETRIC�F�t�H���g�̏ڍ׏��������g���b�N�X�\����
		TEXTMETRIC tm_d;

		//�\�����镶����
		TCHAR STR1[] = TEXT("����ɂ��́B");
		TCHAR STR2[] = TEXT("Hello,123*");
		TCHAR STR3[] = TEXT("�X���̃I�X�X���I");

		//�`�悷�镶���̈ʒu(X���W)
		int Str_X = 0;

		//�`�悷�镶���̈ʒu(Y���W)
		int Str_Y = 50;

		//�t�H���g�̏ڍ׏����擾
		GetTextMetrics(hdc, &tm_d);
		
		//------------------------------------------------
		//PC�ɃC���X�g�[���ς̃t�H���g���g�p����
		//------------------------------------------------

		//�t�H���g�̏����Ǘ�
		HFONT hfnt_Ins;

		//�t�H���g���쐬
		hfnt_Ins = MY_CreateFont(
			hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
			FNT_MS_MINCHO,		//�t�H���g�̖��O
			32,					//�t�H���g�̃T�C�Y
			0,					//�`�悷��Ƃ��̊p�x
			SHIFTJIS_CHARSET	//�����R�[�h
		);

		//�t�H���g��ݒ肷��
		SelectObject(hdc, hfnt_Ins);

		//������\��
		TextOut(hdc, Str_X, Str_Y, STR1, lstrlen(STR1));

		//�t�H���g�̏ڍ׏����擾
		GetTextMetrics(hdc, &tm_d);

		//�`�悷�镶���̍������擾
		Str_Y += tm_d.tmHeight;

		//�t�H���g���f�t�H���g�ɖ߂�
		SelectObject(hdc, GetStockObject(SYSTEM_FONT));

		//�s�v�ȃt�H���g���폜
		DeleteObject(hfnt_Ins);

		//------------------------------------------------
		//PC�ɖ��C���X�g�[���ς̃t�H���g���g�p����(ANSI:�p���̂�)
		//------------------------------------------------

		//�t�H���g�̏����Ǘ�
		HFONT hfnt_Not_ANSI;

		//�t�H���g���쐬
		hfnt_Not_ANSI = MY_CreateFont(hdc, FNT_JUD_NAME, 100, 0, ANSI_CHARSET);

		//�t�H���g��ݒ肷��
		SelectObject(hdc, hfnt_Not_ANSI);

		//������\��
		TextOut(hdc, Str_X, Str_Y, STR2, lstrlen(STR2));

		//�t�H���g�̏ڍ׏����擾
		GetTextMetrics(hdc, &tm_d);

		//�`�悷�镶���̍������擾
		Str_Y += tm_d.tmHeight;

		
		//�t�H���g���f�t�H���g�ɖ߂�
		SelectObject(hdc, GetStockObject(SYSTEM_FONT));

		//�s�v�ȃt�H���g���폜
		DeleteObject(hfnt_Not_ANSI);

		//------------------------------------------------
		//PC�ɖ��C���X�g�[���ς̃t�H���g���g�p����(Shift-JIS:���{��)
		//------------------------------------------------

		//�t�H���g�̏����Ǘ�
		HFONT hfnt_Not_SJIS;

		//�t�H���g���쐬
		hfnt_Not_SJIS = MY_CreateFont(hdc, FNT_TANU_NAME, 32, 0, SHIFTJIS_CHARSET);

		//�t�H���g��ݒ肷��
		SelectObject(hdc, hfnt_Not_SJIS);

		//������\��
		TextOut(hdc, Str_X, Str_Y, STR3, lstrlen(STR3));

		//�t�H���g�̏ڍ׏����擾
		GetTextMetrics(hdc, &tm_d);

		//�`�悷�镶���̍������擾
		Str_Y += tm_d.tmHeight;

		//�t�H���g���f�t�H���g�ɖ߂�
		SelectObject(hdc, GetStockObject(SYSTEM_FONT));

		//�s�v�ȃt�H���g���폜
		DeleteObject(hfnt_Not_SJIS);

		return;
	}
	
�T�D�t�H���g��ݒ肷��y�֐��z��ǉ�����
	//------------------------------------------------
	//�t�H���g��ݒ肷��֐�
	//------------------------------------------------
	HFONT MY_CreateFont(HDC hdc, LPCTSTR fontName, int size, int angle, int charset)
	{

		HFONT hFont;
		hFont = CreateFont(
			size,					//�t�H���g�̍��� / 0�Ȃ�f�t�H���g(�傫��)
			0,						//������		 / 0�Ȃ玩���v�Z

			angle,					//�e�L�X�g�̊p�x
									//�������甽���v���� 1/10 �x�P�ʂŊp�x���w��
									//   0(  0�x) �Ȃ�� ������E�֕`��
									// 900( 90�x) �Ȃ�� �������֕`��
									//1800(180�x) �Ȃ�� �E���獶�֕`��
									//2700(270�x) �Ȃ�� �ォ�牺�֕`��
									
			0,						//�x�[�X���C���Ƃ����Ƃ̊p�x
			FW_REGULAR,				//�t�H���g�̏d���i�����j
			FALSE,					//�C�^���b�N��
			FALSE,					//�A���_�[���C��
			FALSE,					//�ł�������

			charset,				//�����Z�b�g
									//ANSI      ���g���Ȃ�� ANSI_CHARSET 
									//Shift-JIS ���g���Ȃ�� SHIFTJIS_CHARSET
									//�f�t�H���g���g���Ȃ�� DEFAULT_CHARSET

			OUT_DEFAULT_PRECIS,		//�o�͐��x
			CLIP_DEFAULT_PRECIS,	//�N���b�s���O���x
			PROOF_QUALITY,			//�o�͕i��
			FIXED_PITCH | FF_MODERN,//�s�b�`�ƃt�@�~���[
			fontName);				//�t�H���g�̏��̖�

		return hFont;
	}
	
�U�D�yWM_CREATE�z���b�Z�[�W���֒ǉ�����
	//judge hard�t�H���g���ꎞ�I�ɓǂݍ���
	if (AddFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL) == 0)
	{
		//�t�H���g���ǂݍ��߂Ȃ������Ƃ�	
		MessageBox(hwnd, ERR_MSG_NO_READ_FONT, ERR_MSG_TITLE, MB_OK);

		return -1;
	}

	//���ʂ������}�W�b�N�t�H���g���ꎞ�I�ɓǂݍ���
	if (AddFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL) == 0)
	{
		//�t�H���g���ǂݍ��߂Ȃ������Ƃ�	
		MessageBox(hwnd, ERR_MSG_NO_READ_FONT, ERR_MSG_TITLE, MB_OK);

		return -1;
	}
	
�V�D�yWM_PAINT�z���b�Z�[�W���֒ǉ�����
	��MY_DRAW(hdc);�̉��ɒǉ�����

	//�t�H���g��ݒ肵�ĕ`�� 
	MY_SetFontDraw(hdc);
	
�W�D�yWM_DESTROY�z���b�Z�[�W���ɒǉ�����
	��PostQuitMessage(0);�̏�ɒǉ�����

	//�ꎞ�I�ɓǂݍ��� judge hard�t�H���g���폜
	RemoveFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL);

	//�ꎞ�I�ɓǂݍ��� ���ʂ������}�W�b�N�t�H���g���폜
	RemoveFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL);

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

//�����������Q�D�}�N����`�Ɉȉ���ǉ����遥��������

#define ERR_MSG_NO_READ_FONT TEXT("�t�H���g��\
�ǂݍ��߂܂���ł���\n�v���O�������I�����܂�")

//�����������Q�D�}�N����`�Ɉȉ���ǉ����遣��������

//�E�B���h�E�̃T�C�Y��ύX�ł��Ȃ�����
//���́AWS_OVERLAPPEDWINDOW����AWS_THICKFRAME �� WS_MAXIMIZEBOX�𔲂�������
#define WS_STATIC_WINDOW	WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//�E�B���h�E�̃^�C�g�����Ȃ���
#define WS_NOT_TITLE WS_POPUP | WS_BORDER

//�����������Q�D�}�N����`�Ɉȉ���ǉ����遥��������

//���ł�PC�ɃC���X�g�[������Ă���t�H���g
#define FNT_MS_GOTHIC TEXT("�l�r �S�V�b�N")
#define FNT_MS_MINCHO TEXT("�l�r ����")

//�ꎞ�I�ɓǂݍ��ރt�H���g
#define FNT_JUD_PASS	TEXT(".\\MY_FONT\\JUDGE2.TTF")		//�t�H���g�̏ꏊ
#define FNT_JUD_NAME	TEXT("Judge Hard")

#define FNT_TANU_PASS	TEXT(".\\MY_FONT\\TanukiMagic.ttf")	//�t�H���g�̏ꏊ
#define FNT_TANU_NAME	TEXT("���ʂ������}�W�b�N")

//�����������Q�D�}�N����`�Ɉȉ���ǉ����遣��������

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
VOID MY_SetClientSize(HWND hWnd);

//�����������T�D�y�v���g�^�C�v�錾�z��ǉ����遥��������

//�t�H���g��ݒ肷��
HFONT MY_CreateFont(HDC, LPCTSTR, int, int, int);

//�t�H���g��ݒ肵�ĕ`�悷��
void MY_SetFontDraw(HDC);

//�����������T�D�y�v���g�^�C�v�錾�z��ǉ����遣��������

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

//+++++++++++++++++++++++++++++++++++++++++++++
//�E�B���h�E�̃��[�h��ݒ�
//+++++++++++++++++++++++++++++++++++++++++++++
int win_mode = (int)WIN_RESZ_OK;

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
//  �ݒ肵�������l���猸�����l�̑傫���ŕ\������Ă��܂�
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
//�摜��`�悷��֐�
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
	TextOut(hdc, 100, tm.tmHeight * 0, Str_X_Y, lstrlen(Str_X_Y));

	//��ʂ̑傫���𐮌`
	wsprintf(Str_CX_CY, TEXT("��ʂ̑傫��(X:%03d,Y:%03d)"), window_Size.right, window_Size.bottom);

	//��ʂ̑傫����`��
	TextOut(hdc, 100, tm.tmHeight * 1, Str_CX_CY, lstrlen(Str_CX_CY));
}

//�����������R�D�t�H���g��ݒ肵�ĕ�����`�悷��y�֐��z��ǉ����遥��������
//------------------------------------------------
//�t�H���g��ݒ肵�ĕ�����`�悷��
//------------------------------------------------
void MY_SetFontDraw(HDC hdc)
{
	//TEXTMETRIC�F�t�H���g�̏ڍ׏��������g���b�N�X�\����
	TEXTMETRIC tm_d;

	//�\�����镶����
	TCHAR STR1[] = TEXT("����ɂ��́B");
	TCHAR STR2[] = TEXT("Hello,123*");
	TCHAR STR3[] = TEXT("�X���̃I�X�X���I");

	//�`�悷�镶���̈ʒu(X���W)
	int Str_X = 0;

	//�`�悷�镶���̈ʒu(Y���W)
	int Str_Y = 50;

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm_d);

	//------------------------------------------------
	//PC�ɃC���X�g�[���ς̃t�H���g���g�p����
	//------------------------------------------------

	//�t�H���g�̏����Ǘ�
	HFONT hfnt_Ins;

	//�t�H���g���쐬
	hfnt_Ins = MY_CreateFont(
		hdc,				//�f�o�C�X�R���e�L�X�g�̃n���h��
		FNT_MS_MINCHO,		//�t�H���g�̖��O
		32,					//�t�H���g�̃T�C�Y
		0,					//�`�悷��Ƃ��̊p�x
		SHIFTJIS_CHARSET	//�����R�[�h
	);

	//�t�H���g��ݒ肷��
	SelectObject(hdc, hfnt_Ins);

	//������\��
	TextOut(hdc, Str_X, Str_Y, STR1, lstrlen(STR1));

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm_d);

	//�`�悷�镶���̍������擾
	Str_Y += tm_d.tmHeight;

	//�t�H���g���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//�s�v�ȃt�H���g���폜
	DeleteObject(hfnt_Ins);

	//------------------------------------------------
	//PC�ɖ��C���X�g�[���ς̃t�H���g���g�p����(ANSI:�p���̂�)
	//------------------------------------------------

	//�t�H���g�̏����Ǘ�
	HFONT hfnt_Not_ANSI;

	//�t�H���g���쐬
	hfnt_Not_ANSI = MY_CreateFont(hdc, FNT_JUD_NAME, 100, 0, ANSI_CHARSET);

	//�t�H���g��ݒ肷��
	SelectObject(hdc, hfnt_Not_ANSI);

	//������\��
	TextOut(hdc, Str_X, Str_Y, STR2, lstrlen(STR2));

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm_d);

	//�`�悷�镶���̍������擾
	Str_Y += tm_d.tmHeight;

	//�t�H���g���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//�s�v�ȃt�H���g���폜
	DeleteObject(hfnt_Not_ANSI);

	//------------------------------------------------
	//PC�ɖ��C���X�g�[���ς̃t�H���g���g�p����(Shift-JIS:���{��)
	//------------------------------------------------

	//�t�H���g�̏����Ǘ�
	HFONT hfnt_Not_SJIS;

	//�t�H���g���쐬
	hfnt_Not_SJIS = MY_CreateFont(hdc, FNT_TANU_NAME, 32, 0, SHIFTJIS_CHARSET);

	//�t�H���g��ݒ肷��
	SelectObject(hdc, hfnt_Not_SJIS);

	//������\��
	TextOut(hdc, Str_X, Str_Y, STR3, lstrlen(STR3));

	//�t�H���g�̏ڍ׏����擾
	GetTextMetrics(hdc, &tm_d);

	//�`�悷�镶���̍������擾
	Str_Y += tm_d.tmHeight;

	//�t�H���g���f�t�H���g�ɖ߂�
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//�s�v�ȃt�H���g���폜
	DeleteObject(hfnt_Not_SJIS);

	return;
}
//�����������R�D�t�H���g��ݒ肵�ĕ�����`�悷��y�֐��z��ǉ����遣��������

//�����������S�D�t�H���g��ݒ肷��y�֐��z��ǉ����遥��������
//------------------------------------------------
//�t�H���g��ݒ肷��֐�
//------------------------------------------------
HFONT MY_CreateFont(HDC hdc, LPCTSTR fontName, int size, int angle, int charset)
{

	HFONT hFont;
	hFont = CreateFont(
		size,					//�t�H���g�̍��� / 0�Ȃ�f�t�H���g(�傫��)
		0,						//������		 / 0�Ȃ玩���v�Z

		angle,					//�e�L�X�g�̊p�x
								//�������甽���v���� 1/10 �x�P�ʂŊp�x���w��
								//   0(  0�x) �Ȃ�� ������E�֕`��
								// 900( 90�x) �Ȃ�� �������֕`��
								//1800(180�x) �Ȃ�� �E���獶�֕`��
								//2700(270�x) �Ȃ�� �ォ�牺�֕`��

		0,						//�x�[�X���C���Ƃ����Ƃ̊p�x
		FW_REGULAR,				//�t�H���g�̏d���i�����j
		FALSE,					//�C�^���b�N��
		FALSE,					//�A���_�[���C��
		FALSE,					//�ł�������

		charset,				//�����Z�b�g
								//ANSI      ���g���Ȃ�� ANSI_CHARSET 
								//Shift-JIS ���g���Ȃ�� SHIFTJIS_CHARSET
								//�f�t�H���g���g���Ȃ�� DEFAULT_CHARSET

		OUT_DEFAULT_PRECIS,		//�o�͐��x
		CLIP_DEFAULT_PRECIS,	//�N���b�s���O���x
		PROOF_QUALITY,			//�o�͕i��
		FIXED_PITCH | FF_MODERN,//�s�b�`�ƃt�@�~���[
		fontName);				//�t�H���g�̏��̖�

	return hFont;
}
//�����������S�D�t�H���g��ݒ肷��y�֐��z��ǉ����遣��������

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

		//�����������U�D�yWM_CREATE�z���b�Z�[�W���֒ǉ����遥��������

		//judge hard�t�H���g���ꎞ�I�ɓǂݍ���
		if (AddFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL) == 0)
		{
			//�t�H���g���ǂݍ��߂Ȃ������Ƃ�	
			MessageBox(hwnd, ERR_MSG_NO_READ_FONT, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//���ʂ������}�W�b�N�t�H���g���ꎞ�I�ɓǂݍ���
		if (AddFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL) == 0)
		{
			//�t�H���g���ǂݍ��߂Ȃ������Ƃ�	
			MessageBox(hwnd, ERR_MSG_NO_READ_FONT, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//�����������U�D�yWM_CREATE�z���b�Z�[�W���֒ǉ����遣��������

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
		
		//�����������V�D�yWM_PAINT�z���b�Z�[�W���֒ǉ����遥��������
		
		//�t�H���g��ݒ肵�ĕ`��
		MY_SetFontDraw(hdc);
		
		//�����������V�D�yWM_PAINT�z���b�Z�[�W���֒ǉ����遣��������

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

		//�����������W�D�yWM_DESTROY�z���b�Z�[�W���ɒǉ����遥��������

		//�ꎞ�I�ɓǂݍ��� judge hard�t�H���g���폜
		RemoveFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL);

		//�ꎞ�I�ɓǂݍ��� ���ʂ������}�W�b�N�t�H���g���폜
		RemoveFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL);

		//�����������W�D�yWM_DESTROY�z���b�Z�[�W���ɒǉ����遣��������

		//���b�Z�[�W�L���[�� WM_QUIT �𑗂�
		PostQuitMessage(0);
		return 0;
	}

	//�f�t�H���g�̃E�B���h�E�v���V�[�W���֐����Ăяo��
	return DefWindowProc(hwnd, msg, wp, lp);
}
*/