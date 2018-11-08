/*

//windows.h���C���N���[�h
#include<windows.h>


#include <tchar.h>	//_T���g�p���邽��
#include <locale.h>	//setlocale���g�p���邽��

#include <stdio.h>	//sprintf���g�p���邽��

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

	//���b�Z�[�W�{�b�N�X��\��
	MessageBox(
		NULL,						//�I�[�i�[�E�C���h�E
		TEXT("HELLO Win32API"),		//�{���̃e�L�X�g
		TEXT("MessageBox"),			//�^�C�g���̃e�L�X�g
		MB_OK);						//���b�Z�[�W�{�b�N�X�̌`��
	//�����R�[�h��Unicode�ɂ���}�N����`�FTEXT()
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//�C���t�H���[�V�����̃A�C�R����\�����悤
	//+++++++++++++++++++++++++++++++++++++++++++++

	//���b�Z�[�W�{�b�N�X��\��
	MessageBox(
		NULL,
		TEXT("Infomation"),
		TEXT("MessageBox"),
		MB_OK | MB_ICONINFORMATION);
	//�C���t�H���[�V�����̃A�C�R���𓯎��ɕ\��

	//+++++++++++++++++++++++++++++++++++++++++++++
	//���b�Z�[�W�{�b�N�X�̖߂�l���g�p���Ă݂悤
	//+++++++++++++++++++++++++++++++++++++++++++++

	//���b�Z�[�W�{�b�N�X�̖߂�l(����)������ϐ�
	int btn_Kekka;

	//���b�Z�[�W�{�b�N�X��\��
	btn_Kekka = MessageBox(
		NULL, 
		TEXT("���͍D���ł����H"),
		TEXT("Quesition"),
		MB_YESNO | MB_ICONQUESTION);

	//���ʂ����ƂɃ��b�Z�[�W�{�b�N�X��\��
	if (btn_Kekka == IDYES)
	{
		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			NULL,
			TEXT("���h�ł��ˁI"),
			TEXT("Answer"),
			MB_OK);
	}
	else
	{
		//���b�Z�[�W�{�b�N�X��\��
		MessageBox(
			NULL,
			TEXT("�L�h�ł��傤��!?"),
			TEXT("Answer"),
			MB_OK);
	}

	//+++++++++++++++++++++++++++++++++++++++++++++
	//��������t�H�[�}�b�g�ɏ]���Đ��`���悤
	//+++++++++++++++++++++++++++++++++++++++++++++

	//TCHAR�FUnicode�ɑΉ�����char�Ɣ�Ή�char��؂�ւ�
	//WCHAR�FUnicode�ɑΉ�����char�^
	TCHAR StrBuf[128];	//�C���X�^���X�n���h����ۑ�����ϐ�

	//wsprintf�F��������t�H�[�}�b�g(%d�Ȃ�)�ɏ]���A���`����
	//���`���ꂽ������́A�֐��̐擪�̔z��(StrBuf)�ɓ���
	wsprintf(StrBuf, TEXT("�C���X�^���X�n���h���̒l:%d"), hInstance);

	//���b�Z�[�W�{�b�N�X��\��
	MessageBox(
		NULL,
		StrBuf,
		TEXT("Handle"),
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//������̃R�s�[�����Ă݂悤
	//+++++++++++++++++++++++++++++++++++++++++++++

	TCHAR strMoji[128] = TEXT("��������R�s�[���܂�");
	TCHAR strCpy[128];

	//��������R�s�[
	lstrcpy(strCpy, strMoji);

	//���b�Z�[�W�{�b�N�X��\��
	MessageBox(
		NULL, 
		strCpy, 
		TEXT("COPY!!"), 
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//�}���`�o�C�g�ƃ��j�R�[�h�̈Ⴂ��m�낤
	//+++++++++++++++++++++++++++++++++++++++++++++

	//+++++++++++++++++++++++++++++++++++++++++++++
	//�}���`�o�C�g�@�@�F�P�o�C�g(���p)�����łȂ��A
	//�@�@�@�@�@�@�@�@�@�Q�o�C�g(�S�p)��
	//�@�@�@�@�@�@�@�@�@�Q�o�C�g�ȏ�ŕ\��������@
	//���V���O���o�C�g�F�P�o�C�g(���p)�ŕ\��������@
	//++++++++++++++++++++++++++++++++++++++++++++ +

	char strAlpha[11] =  "ABCDEFGHIJ" ;	//\0��+1
	char strHira[11] = "����������";	//\0��+1
	const char *p_strNum = "12345";		//�|�C���^

	char chShowAlpha[33];	//�}���`�o�C�g�\���p
	char chShowHira[33];	//�}���`�o�C�g�\���p
	char chShowNum[33];	//�}���`�o�C�g�\���p

	//�}���`�o�C�g�ŁA[C]��\��������
	sprintf(chShowAlpha, "Alpha�F%c", strAlpha[2]);

	//���b�Z�[�W�{�b�N�X���}���`�o�C�g�ŕ\��
	MessageBoxA(
		NULL,
		chShowAlpha,
		"Multi Byte",
		MB_OK);

	//�}���`�o�C�g�ŁA[��]��\��������
	sprintf(chShowHira, "Hira�F%c%c", strHira[4], strHira[5]);

	//���b�Z�[�W�{�b�N�X���}���`�o�C�g�ŕ\��
	MessageBoxA(
		NULL,
		chShowHira,
		"Multi Byte",
		MB_OK);

	//�}���`�o�C�g�ŁA[3]��\��������
	sprintf(chShowNum, "Num�F%c", *(p_strNum+2));

	//���b�Z�[�W�{�b�N�X���}���`�o�C�g�ŕ\��
	MessageBoxA(
		NULL,
		chShowNum,
		"Multi Byte",
		MB_OK);
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//Unicode�@�@�F�Q�o�C�g(���C�h����)�Ŕ��p�A�S�p��\��������@
	//+++++++++++++++++++++++++++++++++++++++++++++
	wchar_t w_strAlpha[11] = L"ABCDEFGHIJ";	//\0��+1
	wchar_t w_strHira[11] = L"����������";	//\0��+1
	const wchar_t *w_p_strNum = L"12345";	//�|�C���^

	wchar_t w_chShowAlpha[33];	//Unicode�\���p
	wchar_t w_chShowHira[33];	//Unicode�\���p
	wchar_t w_chShowNum[33];	//Unicode�\���p

	//Unicode�ŁA[C]��\��������
	wsprintf(w_chShowAlpha, L"Alpha�F%c", w_strAlpha[2]);

	//���b�Z�[�W�{�b�N�X��Unicode�ŕ\��
	MessageBoxW(
		NULL,
		w_chShowAlpha,
		L"Wide(Unicode)",
		MB_OK);

	//Unicode�ŁA[��]��\��������
	wsprintf(w_chShowHira, L"Hira�F%c", w_strHira[2]);

	//���b�Z�[�W�{�b�N�X��Unicode�ŕ\��
	MessageBoxW(
		NULL,
		w_chShowHira,
		L"Wide(Unicode)",
		MB_OK);

	//Unicode�ŁA[3]��\��������
	wsprintf(w_chShowNum, L"Num�F%c", *(w_p_strNum + 2));

	//���b�Z�[�W�{�b�N�X��Unicode�ŕ\��
	MessageBoxW(
		NULL,
		w_chShowNum,
		L"Wide(Unicode)",
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//�����ɑΉ����鏑����
	//+++++++++++++++++++++++++++++++++++++++++++++
	TCHAR t_strAlpha[11] = TEXT("ABCDEFGHIJ");	//\0��+1
	TCHAR t_strHira[11] = TEXT("����������");	//\0��+1
	const TCHAR *t_strNum= TEXT("12345");		//�|�C���^

	TCHAR t_chShowAlpha[33];	//�����ɑΉ����鏑�����̕\���p
	TCHAR t_chShowHira[33];		//�����ɑΉ����鏑�����̕\���p
	TCHAR t_chShowNum[33];		//�����ɑΉ����鏑�����̕\���p

	//���P�[���i�n�挾��j����{��ŃZ�b�g
	//�t�@�C�����o�͂ƃR���\�[���ւ̓��o�͂̍ۂɃ��j�R�[�h���g�p����Ȃ�K�{
	setlocale(LC_ALL, "Japanese");

	//�����ɑΉ����鏑�����ŁA[C]��\��������
	wsprintf(t_chShowAlpha, TEXT("Alpha�F%c"), t_strAlpha[2]);

	//���b�Z�[�W�{�b�N�X�𗼕��ɑΉ����鏑�����ŕ\��
	MessageBox(
		NULL,
		t_chShowAlpha,
		TEXT("Multi Byte & Wide(Unicode)"),
		MB_OK);


	//�����ɑΉ����鏑�����ŁA[��]��\��������
	wsprintf(t_chShowHira, TEXT("Hira�F%c"), t_strHira[2]);

	//���b�Z�[�W�{�b�N�X�𗼕��ɑΉ����鏑�����ŕ\��
	MessageBox(
		NULL,
		t_chShowHira,
		TEXT("Multi Byte & Wide(Unicode)"),
		MB_OK);

	//�����ɑΉ����鏑�����ŁA[3]��\��������
	wsprintf(t_chShowNum, TEXT("Num�F%c"), *(t_strNum+2));

	//���b�Z�[�W�{�b�N�X�𗼕��ɑΉ����鏑�����ŕ\��
	MessageBox(
		NULL,
		t_chShowNum,
		TEXT("Multi Byte & Wide(Unicode)"),
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//_T��TEXT()�Ɠ����̓�����s��
	//+++++++++++++++++++++++++++++++++++++++++++++

	//�����ɑΉ����鏑�����ŁA[��]��\��������
	wsprintf(t_chShowHira, _T("Hira�F%c"), t_strHira[4]);

	//���b�Z�[�W�{�b�N�X�𗼕��ɑΉ����鏑�����ŕ\��
	MessageBox(
		NULL,
		t_chShowHira,
		_T("Multi Byte & Wide(Unicode)"),
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//���ǁA�f�[�^�^�̍Ē�`�y�@���������Ă݂悤�z
	//���������ׂĊo����K�v�͂Ȃ�������
	//(cont = �萔�� = �ϐ����������ȍ~�A�l��ς��邱�Ƃ��ł��Ȃ��ϐ�)
	//+++++++++++++++++++++++++++++++++++++++++++++
	char ch;				//����޲Ẵf�[�^�^
	char * p_ch;			//����޲Ẵf�[�^�^�̃|�C���^
	const char * c_p_ch;	//����޲Ẵf�[�^�^(�萔)�̃|�C���^

	CHAR CH;				//char �̍Ē�`
	PSTR P_CH;				//char * �̍Ē�`
	LPSTR L_P_CH;			//char * �̍Ē�`(L = Long = 16�r�b�g�̖��c)
	PCSTR C_P_CH;			//const char * �̍Ē�`
	//LPCSTR C_P_CH;			//const char * �̍Ē�`(L = Long = 16�r�b�g�̖��c)

	wchar_t wch;			//ܲ�ޕ���(Unicode)�̃f�[�^�^
	wchar_t * p_wch;		//ܲ�ޕ���(Unicode)�̃f�[�^�^�̃|�C���^
	const wchar_t * c_p_wch;//ܲ�ޕ���(Unicode)�̃f�[�^�^(�萔)�̃|�C���^

	WCHAR WCH;				//wchar_t �̍Ē�`
	PWSTR P_WCH;			//wchar_t * �̍Ē�`
	LPWSTR L_P_WCH;			//wchar_t * �̍Ē�`(L = Long = 16�r�b�g�̖��c)
	PCWSTR C_P_WCH;			//const wchar_t * �̍Ē�`
	//LPCWSTR C_P_WCH;		//const wchar_t * �̍Ē�`(L = Long = 16�r�b�g�̖��c)	

							//ܲ�ޕ��� or ����޲�
	TBYTE TBYTE;			//WCHAR    or CHAR   �̍Ē�`
	TCHAR TCH;				//WCHAR    or CHAR   �̍Ē�`
	TCHAR *P_TCH;			//PWSTR    or PSTR   �̍Ē�`
	const TCHAR *C_P_TCH;	//PCWSTR   or PCSTR  �̍Ē�`

	PTSTR P_TSR;			//PWSTR    or PSTR   �̍Ē�`
	LPTSTR L_P_STR;			//LPWSTR   or LPSTR  �̍Ē�`
	PCTSTR C_P_STR;			//PCWSTR   or PCSTR  �̍Ē�`
	LPCTSTR L_C_P_STR;		//LPCWSTR  or LPCSTR �̍Ē�`
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//�o�̓E�B���h�E�ɕ\��������
	//+++++++++++++++++++++++++++++++++++++++++++++

	TCHAR debug_STR[32] = TEXT("");	//�o�͂���ϐ�

	for (int i = 0; i < 10; i++)
	{
		wsprintf(debug_STR, TEXT("DEBUG�F%d\n"), i);

		//�o�̓E�C���h�E�ɕ\��
		//�f�o�b�O�̊J�n(F5)�ŕ\�������
		OutputDebugString(debug_STR);
	}

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
			TEXT("STATIC"),					//�@�ω����Ȃ��E�B���h�E�FSTATIC
			TEXT("�^�C�g��"),				//�A�E�B���h�E�̃^�C�g���F�^�C�g��
			WS_CAPTION,						//�B�^�C�g���o�[�����E�B���h�E���쐬�FWS_CAPTION
			100,							//�C���̈ʒu�F���ォ��100px�̈ʒu
			100,							//�D�c�̈ʒu�F���ォ��100px�̈ʒu
			200,							//�E�E�B���h�E�̕��@�F���̈ʒu����200px(�E�Ɍ������đ�����)
			200,							//�F�E�B���h�E�̍����F�c�̈ʒu����200px(���Ɍ������đ�����)
			NULL,							//�G�e�E�C���h�E�n���h���F�Ȃ�
			NULL,							//�H���j���[�n���h���F�Ȃ�
			hInstance,						//�I�C���X�^���X�n���h���F�Ȃ�
			NULL							//�J�쐬���ꂽ�E�B���h�E�̃n���h���F�Ȃ�
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
			TEXT("Multi Byte & Wide(Unicode)"),
			MB_OK);

	return 0;
}
*/