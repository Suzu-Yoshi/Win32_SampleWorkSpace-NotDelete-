/*
#include<windows.h>	//windows.h���C���N���[�h

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
	//�E�B���h�E��\��������
	//+++++++++++++++++++++++++++++++++++++++++++++
	DWORD dw;	//�y�Q�l�zDWORD�F32�r�b�g �����Ȃ� ���� �̍Ē�`

	HWND hwnd;	//�X��Window�����ʂ���l(�E�B���h�E�n���h��)

	//�E�B���h�E�̍쐬(�E�B���h�E�N���X�̐���)
	//�@�����FLPCTSTR lpszClassName	:�E�B���h�E�N���X�̖��O���w��
	//�A�����FLPCTSTR lpWindowName	:�E�B���h�E�̃^�C�g��
	//�B�����FDWORD dwStyle			:�E�B���h�E�̎��
	//�C�����Fint x					:�E�C���h�E�����x���W(���̈ʒu)
	//�D�����Fint y					:�E�C���h�E�����y���W(�c�̈ʒu)
	//�E�����Fint nWidth			:�E�C���h�E�̕�
	//�F�����Fint nHeight			:�E�C���h�E�̍���
	//�G�����FHWND hwndParent		:�e�E�B���h�E�n���h��
	//�H�����FHMENU hmenu			:���j���[�n���h��
	//�I�����FHANDLE hinst			:�C���X�^���X�n���h��
	//�J�����FLPVOID lpvParam		:�쐬���ꂽ�E�B���h�E�̃n���h��
	hwnd = CreateWindow(
		TEXT("STATIC"),					//�@�e�L�X�g�t�B�[���h�p�N���X�FSTATIC
		TEXT("�^�C�g��"),				//�A����޳�̃^�C�g���F�^�C�g��
		WS_CAPTION,						//�B�^�C�g���o�[�����³���޳�FWS_CAPTION
		100,							//�C���̈ʒu�F���ォ��100px�̈ʒu
		100,							//�D�c�̈ʒu�F���ォ��100px�̈ʒu
		200,							//�E����޳�̕��F���̈ʒu����200px(�E�ɑ�����)
		200,							//�F����޳�̍��F�c�̈ʒu����200px(���ɑ�����)
		NULL,							//�G�e����޳�n���h���F�Ȃ�
		NULL,							//�H���j���[�n���h���F�Ȃ�
		hInstance,						//�I�C���X�^���X�n���h���F�Ȃ�
		NULL							//�J�쐬���ꂽ����޳�̃n���h���F�Ȃ�
	);

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

	return 0;
}

//�ۑ�P�F�E�B���h�E�̃^�C�g����"TITLE"�ɕύX���Ă݂悤
//�ۑ�Q�F�E�B���h�E�̉��̈ʒu��300�A�c�̈ʒu��300�ɕύX���悤
//�ۑ�R�F�E�B���h�E�̕���500�A������500�ɕύX���悤

//�ύX��
//hwnd = CreateWindow(
//	TEXT("STATIC"),					//�@�e�L�X�g�t�B�[���h�p�N���X�FSTATIC
//	TEXT("TITLE"),					//�A�E�B���h�E�̃^�C�g���F�^�C�g��
//	WS_CAPTION,						//�B�^�C�g���o�[�����E�B���h�E���쐬�FWS_CAPTION
//	300,							//�C���̈ʒu�F���ォ��300px�̈ʒu
//	300,							//�D�c�̈ʒu�F���ォ��300px�̈ʒu
//	500,							//�E�E�B���h�E�̕��@�F���̈ʒu����500px(�E�Ɍ������đ�����)
//	500,							//�F�E�B���h�E�̍����F�c�̈ʒu����500px(���Ɍ������đ�����)
//	NULL,							//�G�e�E�C���h�E�n���h���F�Ȃ�
//	NULL,							//�H���j���[�n���h���F�Ȃ�
//	hInstance,						//�I�C���X�^���X�n���h���F�Ȃ�
//	NULL							//�J�쐬���ꂽ�E�B���h�E�̃n���h���F�Ȃ�
//);
*/