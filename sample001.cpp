/*
#include<windows.h>	//windows.hをインクルード

//一番最初に実行される関数：WinMain
//引数：HINSTANCE hInstance：プログラムを管理する番号(インスタンスハンドル)
//引数：HINSTANCE hPrevInstance： Win16時代の名残：今はNULL
//引数：PSTR lpCmdLine：コマンドライン引数の文字列
//引数：int nCmdShow：ウインドウの状態
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{

	//+++++++++++++++++++++++++++++++++++++++++++++
	//メッセージボックスを表示しよう
	//+++++++++++++++++++++++++++++++++++++++++++++

	MessageBox(						//メッセージボックスを表示
		NULL,						//オーナーウインドウ
		TEXT("HELLO Win32API"),		//本文のテキスト
		TEXT("MessageBox"),			//タイトルのテキスト
		MB_OK);						//メッセージボックスの形態
	//文字コードをUnicodeにするマクロ定義：TEXT()

	//+++++++++++++++++++++++++++++++++++++++++++++
	//インフォメーションのアイコンを表示しよう
	//+++++++++++++++++++++++++++++++++++++++++++++

	MessageBox(						//メッセージボックスを表示
		NULL,
		TEXT("Infomation"),
		TEXT("MessageBox"),
		MB_OK | MB_ICONINFORMATION);//インフォメーションのアイコンを同時に表示
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//メッセージボックスの戻り値を使用
	//+++++++++++++++++++++++++++++++++++++++++++++

	int Kekka;						//メッセージボックスの戻り値(結果)を入れる変数

	Kekka = MessageBox(				//メッセージボックスを表示
		NULL,
		TEXT("犬は好きですか？"),
		TEXT("Quesition"),
		MB_YESNO | MB_ICONQUESTION);
		
	
	if (Kekka == IDYES)				//「はい」ボタンを押したとき
	{	
		MessageBox(					//メッセージボックスを表示
			NULL,
			TEXT("犬派ですね！"),
			TEXT("Answer"),
			MB_OK);
	}
	else if(Kekka == IDNO)	//「いいえ」ボタンを押したとき
	{
		MessageBox(					//メッセージボックスを表示
			NULL,
			TEXT("猫派でしょうか!?"),
			TEXT("Answer"),
			MB_OK);
	}
}
*/