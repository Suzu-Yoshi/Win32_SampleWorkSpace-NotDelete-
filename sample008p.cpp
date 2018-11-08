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
		//�������I��������
		return 0;
	}

	
	//�E�B���h�E��\��
	ShowWindow(
		hwnd,		//�\������E�C���h�E�n���h��
		SW_SHOW		//���݂̈ʒu�ƃT�C�Y�ŕ\��
	);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//�A�v���P�[�V����(�v���O����)���I������
	//+++++++++++++++++++++++++++++++++++++++++++++
	BOOL ret_msg = TRUE;

	//WM_QUIT�Ƃ������b�Z�[�W��������Ȃ���΁A�J��Ԃ�
	while (TRUE)
	{
		//���b�Z�[�W�L���[���烁�b�Z�[�W���󂯎��

		//GetMessage�́AWM_QUIT���󂯎��ƁAFALSE��Ԃ�
		//				����ȊO�́ATRUE��Ԃ�
		ret_msg = GetMessage(&msg, NULL, 0, 0);

		//WM_QUIT���󂯎�����Ƃ�
		if (ret_msg == FALSE)
		{
			MessageBox(
				NULL,
				TEXT("�v���O�������I�����܂�"),
				TEXT("QUIT"),
				MB_OK);

			//�������[�v�𔲂���
			break;
		}

		//�f�t�H���g�E�B���h�E�v���V�[�W���ɂ����b�Z�[�W���󂯎�点��
		DispatchMessage(&msg);
	}

	//��̖������[�v�����̂悤�ɏ������Ƃ��ł���
	//while (GetMessage(&msg, NULL, 0, 0))	//GetMessage�̖߂�l��WM_QUIT��FALSE�łȂ��Ƃ�
	//{
	//	DispatchMessage(&msg);
	//}

	//�I���R�[�h�͕K�� WS_QUIT �� wParam �̒l�ɂ��Ȃ���΂Ȃ�Ȃ�
	//����ɏI������� wParam �̒l�́A0�ɂȂ�
	return msg.wParam;
}
























//�E�B���h�E�v���V�[�W��(�֐�)���쐬
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
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

	//+++++++++++++++++++++++++++++++++++++++++++++
	//�A�v���P�[�V����(�v���O����)���I������
	//+++++++++++++++++++++++++++++++++++++++++++++

	case WM_CLOSE:
		//����{�^�����������Ƃ�

		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			hwnd,
			TEXT("�E�B���h�E���I�����܂�"),
			TEXT("CLOSE"),
			MB_OK);

		break;

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
	return DefWindowProc(hwnd, msg, wp, lp);
}

//+++++++++++++++++++++++++++++++++++++++++++++
//�Q�l�FWindow ���b�Z�[�W�̈ꕔ
//���K�v�ȂƂ��ɁA�m�F����΂����̂ŁA���ׂĊo���Ȃ��đ��v
//+++++++++++++++++++++++++++++++++++++++++++++
//0x0000	WM_NULL				����̳���޳�ɂ��̃��b�Z�[�W�𓊂�����ѱ�Ă��邩�ǂ����Ő����m�F���s�������ł���
//0x0001	WM_CREATE			����޳���쐬����Ă��邱�Ƃ������܂�
//0x0002	WM_DESTROY			����޳���j������悤�Ƃ��Ă��邱�Ƃ������܂�
//0x0003	WM_MOVE				����޳�̈ʒu���ύX���ꂽ���Ƃ������܂�
//0x0005	WM_SIZE				����޳�̃T�C�Y���ύX����Ă��邱�Ƃ������܂�
//0x0006	WM_ACTIVATE			�A�N�e�B�u��Ԃ��ύX����Ă��邱�Ƃ������܂�
//0x0007	WM_SETFOCUS			����޳���L�[�{�[�h�E�t�H�[�J�X���擾�������Ƃ������܂�
//0x0008	WM_KILLFOCUS		����޳���L�[�{�[�h�E�t�H�[�J�X�������Ă��邱�Ƃ������܂�
//0x000A	WM_ENABLE			����޳�̗L���܂��͖����̏�Ԃ��ύX����Ă��邱�Ƃ������܂�
//0x000B	WM_SETREDRAW		����޳���̍ĕ`������܂��͋֎~���܂�
//0x000C	WM_SETTEXT			����޳�̃e�L�X�g��ݒ肵�܂�
//0x000D	WM_GETTEXT			����޳�ɑΉ�����e�L�X�g���擾���܂�
//0x000E	WM_GETTEXTLENGTH	����޳�Ɋ֘A�t�����Ă���e�L�X�g�̒������擾���܂�
//0x000F	WM_PAINT			����޳�̸ײ��ė̈��`�悷��K�v�����邱�Ƃ������܂�
//0x0010	WM_CLOSE			�R���g���[���E���j���[��[�N���[�Y]�R�}���h���I�΂�܂���
//0x0011	WM_QUERYENDSESSION	Windows�Z�b�V�������I������悤�v�����܂�
//0x0012	WM_QUIT				�A�v���P�[�V�����������I������悤�v�����܂�
*/