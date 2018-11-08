/*
#include<windows.h>	//windows.h���C���N���[�h

#define MY_WIN_CLASS "MY_WIN_CLASS"	//�����ō쐬���鳨��޳�׽�̖��O

//��ԍŏ��Ɏ��s�����֐��FWinMain
//�����FHINSTANCE hInstance�F�v���O�������Ǘ�����ԍ�(�C���X�^���X�n���h��)
//�����FHINSTANCE hPrevInstance�F Win16����̖��c�F����NULL
//�����FPSTR lpCmdLine�F�R�}���h���C�������̕�����
//�����Fint nCmdShow�F�E�C���h�E�̏��
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{
	//+++++++++++++++++++++++++++++++++++++++++++++
	//�E�B���h�E�N���X���쐬
	//+++++++++++++++++++++++++++++++++++++++++++++

	WNDCLASS winc;	//�E�B���h�E�N���X��ۑ�����\����

	HWND hwnd;	//�X��Window�����ʂ���l(�E�B���h�E�n���h��)

	//�u���V���쐬
	//static HBRUSH brush;	//���ۑ�S�Ŏg�p��

	//�u���V�̐F��ݒ�
	//brush = CreateSolidBrush(RGB(255, 0, 0));	//���ۑ�S�Ŏg�p��

	//�������E�B���h�E�N���X�̐ݒ�͂������火����

	//�E�B���h�E�X�^�C���FCS_HREDRAW | CS_VREDRAW
	//�E�B���h�E������/�����ɃE�B���h�E�T�C�Y��
	//�ύX�����ƍĕ`�悷��
	winc.style = CS_HREDRAW | CS_VREDRAW;
	
	//�f�t�H���g�̃E�B���h�E�v���V�[�W����ݒ�
	//�E�B���h�E�v���V�[�W���F���b�Z�[�W����������֐�
	winc.lpfnWndProc = DefWindowProc;
	
	//�N���X�\���̂̒ǉ��̈�F�ʏ��0
	winc.cbClsExtra = 0;
	
	//�E�B���h�E�\���̂̒ǉ��̈�F�ʏ��0
	winc.cbWndExtra = 0;
	
	//�C���X�^���X�n���h��
	winc.hInstance = hInstance;
	
	//�A�C�R���̃n���h��
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	
	//�}�E�X�J�[�\���̃n���h��
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	
	//�E�B���h�E�̔w�i�F
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	//�쐬�����u���V���g�p���Ĕw�i�F��h��Ԃ�
	//winc.hbrBackground = brush;	//���ۑ�S�Ŏg�p��
	
	//���j���[�̃n���h��
	winc.lpszMenuName = NULL;
	
	//�E�B���h�E�N���X�ɂ��閼�O
	winc.lpszClassName = TEXT(MY_WIN_CLASS);

	//�������E�B���h�E�N���X�̐ݒ�͂����܂Ł�����

	
	
	//RegisterClass�F�E�B���h�E�N���X��o�^����
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

	//���b�Z�[�W�{�b�N�X��\��(�E�B���h�E�������ɕ��Ȃ��悤�ɂ���)
	MessageBox(
		NULL,
		TEXT("OK�������ƃE�B���h�E����܂�"),
		TEXT("Message"),
		MB_OK);

	//�쐬�����u���V���폜
	//DeleteObject(brush);	//���ۑ�S�Ŏg�p��

	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//�ۑ�P�F�A�C�R�������R�ɕς��Ă݂悤
//�A�C�R���̃n���h��
//winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//IDI_APPLICATION �̉ӏ���ύX����

//�ȉ��̃A�C�R���ɕύX�ł���
//IDI_APPLICATION	����̃A�v���P�[�V�����A�C�R��
//IDI_ASTERISK		IDI_INFORMATION �Ɠ����ł�
//IDI_ERROR			�X�g�b�v�}�[�N�̃A�C�R��
//IDI_EXCLAMATION	IDI_WARNING �Ɠ����ł�
//IDI_HAND			IDI_ERROR �Ɠ����ł�
//IDI_INFORMATION	���A�C�R���i�����o���̒��� i �̕����j
//IDI_QUESTION		�^�╄�̃A�C�R��
//IDI_WARNING		���Q���̃A�C�R��
//IDI_WINLOGO		Windows ���S�̃A�C�R��
//�Q�l�T�C�g�Fhttps://msdn.microsoft.com/ja-jp/library/cc364833.aspx







//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//�ۑ�Q�F�}�E�X�J�[�\�������R�ɕς��Ă݂悤
//�}�E�X�J�[�\���̃n���h��
//winc.hCursor = LoadCursor(NULL, IDC_ARROW);
//IDC_ARROW �̉ӏ���ύX����

//�ȉ��̃}�E�X�J�[�\���ɕύX�ł���
//IDC_APPSTARTING	�W���̖��J�[�\���Ə����������v�J�[�\��
//IDC_ARROW			�W���̖��J�[�\��
//IDC_CROSS			�\���J�[�\��
//IDC_HAND			Windows 2000�F�n���h�J�[�\��
//IDC_HELP			���Ƌ^�╄
//IDC_IBEAM			�A�C�r�[���i �c���j�J�[�\��
//IDC_ICON			�o�[�W������ 4.0 �ȍ~
//IDC_NO			�֎~�J�[�\���i �~�ɍ��ォ��E���ւ̎ΐ��j
//IDC_SIZE			�o�[�W������ 4.0 �ȍ~�iWindows NT 4.0 �ȍ~�j
//IDC_SIZEALL		4 �����̖��J�[�\��
//IDC_SIZENESW		�E��ƍ������w�����������J�[�\��
//IDC_SIZENS		�㉺���w�����������J�[�\��
//IDC_SIZENWSE		����ƉE�����w�����������J�[�\��
//IDC_SIZEWE		���E���w�����������J�[�\��
//IDC_UPARROW		����w�������̖��J�[�\��
//IDC_WAIT			�����v�J�[�\��
//�Q�l�T�C�g�Fhttps://msdn.microsoft.com/ja-jp/library/cc410880.aspx

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//�ۑ�R�F�w�i�F�����R�ɕς��Ă݂悤
//�E�B���h�E�̔w�i�F
//winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//WHITE_BRUSH �̉ӏ���ύX����

//�ȉ��̔w�i�F�ɕύX�ł���
//WHITE_BRUSH �̉ӏ���ύX����
//BLACK_BRUSH	���̃u���V
//DKGRAY_BRUSH	�Z���D�F�̃u���V
//GRAY_BRUSH	�D�F�̃u���V
//LTGRAY_BRUSH	���邢�D�F�̃u���V
//WHITE_BRUSH	���̃u���V
//�Q�l�T�C�g�Fhttps://msdn.microsoft.com/ja-jp/library/cc410411.aspx

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//�ۑ�S�F�w�i�F���J���t���ȐF�ɂ��Ă݂悤

//�ȉ��̍s�̐擪�̃R�����g(//)���폜
//static HBRUSH brush;	
//brush = CreateSolidBrush(RGB(255, 0, 0));
//winc.hbrBackground = brush;
//DeleteObject(brush);
//RGB�l�̎Q�l�T�C�g�Fhttps://www.peko-step.com/tool/tfcolor.html
*/