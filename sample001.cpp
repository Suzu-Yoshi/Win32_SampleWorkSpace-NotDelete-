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
	//���b�Z�[�W�{�b�N�X��\�����悤
	//+++++++++++++++++++++++++++++++++++++++++++++

	MessageBox(						//���b�Z�[�W�{�b�N�X��\��
		NULL,						//�I�[�i�[�E�C���h�E
		TEXT("HELLO Win32API"),		//�{���̃e�L�X�g
		TEXT("MessageBox"),			//�^�C�g���̃e�L�X�g
		MB_OK);						//���b�Z�[�W�{�b�N�X�̌`��
	//�����R�[�h��Unicode�ɂ���}�N����`�FTEXT()

	//+++++++++++++++++++++++++++++++++++++++++++++
	//�C���t�H���[�V�����̃A�C�R����\�����悤
	//+++++++++++++++++++++++++++++++++++++++++++++

	MessageBox(						//���b�Z�[�W�{�b�N�X��\��
		NULL,
		TEXT("Infomation"),
		TEXT("MessageBox"),
		MB_OK | MB_ICONINFORMATION);//�C���t�H���[�V�����̃A�C�R���𓯎��ɕ\��
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//���b�Z�[�W�{�b�N�X�̖߂�l���g�p
	//+++++++++++++++++++++++++++++++++++++++++++++

	int Kekka;						//���b�Z�[�W�{�b�N�X�̖߂�l(����)������ϐ�

	Kekka = MessageBox(				//���b�Z�[�W�{�b�N�X��\��
		NULL,
		TEXT("���͍D���ł����H"),
		TEXT("Quesition"),
		MB_YESNO | MB_ICONQUESTION);
		
	
	if (Kekka == IDYES)				//�u�͂��v�{�^�����������Ƃ�
	{	
		MessageBox(					//���b�Z�[�W�{�b�N�X��\��
			NULL,
			TEXT("���h�ł��ˁI"),
			TEXT("Answer"),
			MB_OK);
	}
	else if(Kekka == IDNO)	//�u�������v�{�^�����������Ƃ�
	{
		MessageBox(					//���b�Z�[�W�{�b�N�X��\��
			NULL,
			TEXT("�L�h�ł��傤��!?"),
			TEXT("Answer"),
			MB_OK);
	}
}
*/