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
	//�g���E�B���h�E��\��
	//+++++++++++++++++++++++++++++++++++++++++++++
	HWND hwnd;	//�X��Window�����ʂ���l(�E�B���h�E�n���h��)
	
	//�g���E�B���h�E�̍쐬(�E�B���h�E�N���X�̐���)
	hwnd = CreateWindowEx(
		WS_EX_LEFT,						//�@�������̃E�B���h�E���쐬(�f�t�H���g)
		TEXT("STATIC"),					//�A�e�L�X�g�t�B�[���h�p�N���X�FSTATIC
		TEXT("�c�[���E�B���h�E"),		//�B�E�B���h�E�̃^�C�g��
		WS_OVERLAPPEDWINDOW,			//�C�ȉ��̐ݒ�� | (or) �ł܂Ƃ߂��E�B���h�E���쐬
										//�@ WS_OVERLAPPED	�F�^�C�g�����E�B���h�E�̘g������
										// | WS_CAPTION		�F�^�C�g���o�[������
										// | WS_SYSMENU		�F�^�C�g���o�[�̏�Ƀ��j���[�{�b�N�X������
										// | WS_THICKFRAME	�F�T�C�Y�ύX���E������
										// | WS_MINIMIZEBOX	�F�ŏ����{�^��������
										// | WS_MAXIMIMZEBOX�F�ő剻�{�^��������
		100,							//�D���̈ʒu�F���ォ��100px�̈ʒu
		100,							//�E�c�̈ʒu�F���ォ��100px�̈ʒu
		200,							//�F�E�B���h�E�̕��@�F���̈ʒu����200px(�E�Ɍ������đ�����)
		200,							//�G�E�B���h�E�̍����F�c�̈ʒu����200px(���Ɍ������đ�����)
		NULL,							//�H�e�E�C���h�E�n���h���F�Ȃ�
		NULL,							//�I���j���[�n���h���F�Ȃ�
		hInstance,						//�J�C���X�^���X�n���h���F�Ȃ�
		NULL							//�K�쐬���ꂽ�E�B���h�E�̃n���h���F�Ȃ�
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

	//*****��r�p*************************

	HWND hwnd_2;	//�X��Window�����ʂ���l(�E�B���h�E�n���h��)
	
	
	
	
	
	
	//�E�B���h�E�̍쐬(�E�B���h�E�N���X�̐���)
	hwnd_2 = CreateWindow(
		TEXT("STATIC"),					//�@�e�L�X�g�t�B�[���h�p�N���X�FSTATIC
		TEXT("�ʏ�̃E�B���h�E"),		//�A�E�B���h�E�̃^�C�g��
		WS_CAPTION,						//�B�^�C�g���o�[�����E�B���h�E���쐬�FWS_CAPTION
		400,							//�C���̈ʒu�F���ォ��400px�̈ʒu
		100,							//�D�c�̈ʒu�F���ォ��100px�̈ʒu
		200,							//�E�E�B���h�E�̕��@�F���̈ʒu����200px(�E�Ɍ������đ�����)
		200,							//�F�E�B���h�E�̍����F�c�̈ʒu����200px(���Ɍ������đ�����)
		NULL,							//�G�e�E�C���h�E�n���h���F�Ȃ�
		NULL,							//�H���j���[�n���h���F�Ȃ�
		hInstance,						//�I�C���X�^���X�n���h���F�Ȃ�
		NULL							//�J�쐬���ꂽ�E�B���h�E�̃n���h���F�Ȃ�
	);

	//�E�B���h�E����������Ȃ������Ƃ�
	if (hwnd_2 == NULL)
	{
		//�������I��������
		return 0;
	}

	//�E�B���h�E��\��
	ShowWindow(
		hwnd_2,		//�\������E�C���h�E�n���h��
		SW_SHOW		//���݂̈ʒu�ƃT�C�Y�ŕ\��
	);

	//*****���̃E�B���h�E�N���X*************************

	HWND hwnd_3;	//�X��Window�����ʂ���l(�E�B���h�E�n���h��)

	//�E�B���h�E�̍쐬(�E�B���h�E�N���X�̐���)
	hwnd_3 = CreateWindow(
		TEXT("BUTTON"),					//�@�{�^���p�N���X�FBUTTON
		TEXT("�{�^���̃E�B���h�E"),		//�A�E�B���h�E�̃^�C�g��
		WS_CAPTION,						//�B�^�C�g���o�[�����E�B���h�E���쐬�FWS_CAPTION
		100,							//�C���̈ʒu�F���ォ��100�̈ʒu
		400,							//�D�c�̈ʒu�F���ォ��400px�̈ʒu
		200,							//�E�E�B���h�E�̕��@�F���̈ʒu����200px(�E�Ɍ������đ�����)
		200,							//�F�E�B���h�E�̍����F�c�̈ʒu����200px(���Ɍ������đ�����)
		NULL,							//�G�e�E�C���h�E�n���h���F�Ȃ�
		NULL,							//�H���j���[�n���h���F�Ȃ�
		hInstance,						//�I�C���X�^���X�n���h���F�Ȃ�
		NULL							//�J�쐬���ꂽ�E�B���h�E�̃n���h���F�Ȃ�
	);

	//�E�B���h�E����������Ȃ������Ƃ�
	if (hwnd_3 == NULL)
	{
		//�������I��������
		return 0;
	}

	//�E�B���h�E��\��
	ShowWindow(
		hwnd_3,		//�\������E�C���h�E�n���h��
		SW_SHOW		//���݂̈ʒu�ƃT�C�Y�ŕ\��
	);
	//*****���̃E�B���h�E�N���X*************************

	HWND hwnd_4;	//�X��Window�����ʂ���l(�E�B���h�E�n���h��)

	//�E�B���h�E�̍쐬(�E�B���h�E�N���X�̐���)
	hwnd_4 = CreateWindow(
		TEXT("EDIT"),					//�@�e�L�X�g�{�b�N�X�p�N���X�FEDIT
		TEXT("÷���ޯ���̃E�B���h�E"),	//�A�E�B���h�E�̃^�C�g��
		WS_CAPTION,						//�B�^�C�g���o�[�����E�B���h�E���쐬�FWS_CAPTION
		400,							//�C���̈ʒu�F���ォ��100�̈ʒu
		400,							//�D�c�̈ʒu�F���ォ��400px�̈ʒu
		200,							//�E�E�B���h�E�̕��@�F���̈ʒu����200px(�E�Ɍ������đ�����)
		200,							//�F�E�B���h�E�̍����F�c�̈ʒu����200px(���Ɍ������đ�����)
		NULL,							//�G�e�E�C���h�E�n���h���F�Ȃ�
		NULL,							//�H���j���[�n���h���F�Ȃ�
		hInstance,						//�I�C���X�^���X�n���h���F�Ȃ�
		NULL							//�J�쐬���ꂽ�E�B���h�E�̃n���h���F�Ȃ�
	);

	//�E�B���h�E����������Ȃ������Ƃ�
	if (hwnd_4 == NULL)
	{
		//�������I��������
		return 0;
	}

	//�E�B���h�E��\��
	ShowWindow(
		hwnd_4,		//�\������E�C���h�E�n���h��
		SW_SHOW		//���݂̈ʒu�ƃT�C�Y�ŕ\��
	);

	return 0;
}
*/