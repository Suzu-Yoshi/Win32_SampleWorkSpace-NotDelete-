/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//�����ō쐬���鳨��޳�׽�̖��O

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
	winc.lpfnWndProc = DefWindowProc;
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
	//Windows����̃��b�Z�[�W(�C�x���g)���󂯎��
	//+++++++++++++++++++++++++++++++++++++++++++++
	//�E���b�Z�[�W�́A�f�[�^�\���ƃA���S���Y���Ŋw��
	//�@�u�L���[�v�Ƃ��Ċi�[����Ă���
	//�E�u�L���[�v�F(�G���L���[)|A|��|B|C|D|��(�f�L���[):������o���@(FIFO)
	// �f�[�^��ǉ�����Ƃ��ɂ́A��̍ŏ��ɒǉ������i�G���L���[�j
	// �f�[�^�����o���Ƃ��ɂ́A��̍Ōォ����o�����i�f�L���[�j
	//�E���́u�L���[�v�̂��Ƃ� ���b�Z�[�W�L���[ �ƌĂ�
	//�E�A�v���P�[�V����(�v���O����)�́A���b�Z�[�W�L���[���烁�b�Z�[�W�����o��
	//+++++++++++++++++++++++++++++++++++++++++++++

	//���b�Z�[�W��₦���󂯎�葱����
	while (TRUE)	//�������[�v(TRUE�F�����^��1�̂���)
	{
		//���b�Z�[�W�L���[���烁�b�Z�[�W���󂯎��
		GetMessage(
			&msg,	//���b�Z�[�W��msg�\���̂ɓ����
			NULL,	//���b�Z�[�W���󂯎��n���h��
					//NULL�Ȃ�\�����Ă���S�ẴE�B���h�E���烁�b�Z�[�W���󂯎��
			0,		//�󂯎�郁�b�Z�[�W�̍ŏ��l�F�S�Ď󂯎��ꍇ��0
			0);		//�󂯎�郁�b�Z�[�W�̍ő�l�F�S�Ď󂯎��ꍇ��0

		//���b�Z�[�W�̎�ނ��Ƃɏ�����ς���
		if(msg.message == WM_RBUTTONDOWN)	//�}�E�X�̉E�{�^�����������Ƃ�
		{
			//���b�Z�[�W�{�b�N�X�̖߂�l(����)������ϐ�
			int kekka_msg;						

			//���b�Z�[�W�{�b�N�X��\��
			kekka_msg = MessageBox(
				NULL,
				TEXT("��ʂ��I�����܂����H"),
				TEXT("Quesition"),
				MB_YESNO | MB_ICONQUESTION);

			//�u�͂��v�{�^�����������Ƃ�
			if (kekka_msg == IDYES)				
			{
				//�������[�v�𔲂���
				break;
			}
			//�u�������v�{�^�����������Ƃ�
			else if (kekka_msg == IDNO)
			{
				//�������Ȃ�
			}
			
		}

		//�E�B���h�E�v���V�[�W���ɂ����b�Z�[�W���󂯎�点��
		DispatchMessage(&msg);

		//�E�B���h�E�v���V�[�W���F���b�Z�[�W�����������p�̊֐�
		//���́A���łɗp�ӂ��ꂽ(�f�t�H���g)�̊֐����g�p���Ă���
		//winc.lpfnWndProc = DefWindowProc; 
		//�f�t�H���g�̊֐��FDefWindowProc�̂������ŁA
		//��ʂ̍ő剻�A�ŏ�����A�E�B���h�E�T�C�Y�̕ύX���ł���
	}
	return 0;
}

//�����F�󂯎���Ă��郁�b�Z�[�W�����Ă݂悤�I
// 1.�v���O�������f�o�b�O�̊J�n(F5)�Ŏ��s
// 2.���s���Ȃ���AVisual Studio��ʏ�� �c�[�� ���N���b�N
// 3.Spy++(+)���N���b�N
// 4.�E�B���h�E�P����A�����œo�^�����E�B���h�E�N���X ��T��
// 5. �����œo�^�����E�B���h�E�N���X ���N���b�N���ASpy++��ʏ�� �X�p�C ���N���b�N
// 7. ���b�Z�[�W�̃��O�o�� ���N���b�N���AOK�{�^��������
// 8.���s���Ă���A�v���P�[�V����(�v���O����)�Ƀ}�E�X�J�[�\���𓖂Ă�
// 9.�I������ꍇ�́ASpy++��ʉE��́u����v�{�^���ŏI�����Ă�������
*/