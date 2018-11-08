/*

//windows.hをインクルード
#include<windows.h>


#include <tchar.h>	//_Tを使用するため
#include <locale.h>	//setlocaleを使用するため

#include <stdio.h>	//sprintfを使用するため

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

	//メッセージボックスを表示
	MessageBox(
		NULL,						//オーナーウインドウ
		TEXT("HELLO Win32API"),		//本文のテキスト
		TEXT("MessageBox"),			//タイトルのテキスト
		MB_OK);						//メッセージボックスの形態
	//文字コードをUnicodeにするマクロ定義：TEXT()
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//インフォメーションのアイコンを表示しよう
	//+++++++++++++++++++++++++++++++++++++++++++++

	//メッセージボックスを表示
	MessageBox(
		NULL,
		TEXT("Infomation"),
		TEXT("MessageBox"),
		MB_OK | MB_ICONINFORMATION);
	//インフォメーションのアイコンを同時に表示

	//+++++++++++++++++++++++++++++++++++++++++++++
	//メッセージボックスの戻り値を使用してみよう
	//+++++++++++++++++++++++++++++++++++++++++++++

	//メッセージボックスの戻り値(結果)を入れる変数
	int btn_Kekka;

	//メッセージボックスを表示
	btn_Kekka = MessageBox(
		NULL, 
		TEXT("犬は好きですか？"),
		TEXT("Quesition"),
		MB_YESNO | MB_ICONQUESTION);

	//結果をもとにメッセージボックスを表示
	if (btn_Kekka == IDYES)
	{
		//メッセージボックスを表示
		MessageBox(
			NULL,
			TEXT("犬派ですね！"),
			TEXT("Answer"),
			MB_OK);
	}
	else
	{
		//メッセージボックスを表示
		MessageBox(
			NULL,
			TEXT("猫派でしょうか!?"),
			TEXT("Answer"),
			MB_OK);
	}

	//+++++++++++++++++++++++++++++++++++++++++++++
	//文字列をフォーマットに従って整形しよう
	//+++++++++++++++++++++++++++++++++++++++++++++

	//TCHAR：Unicodeに対応したcharと非対応charを切り替え
	//WCHAR：Unicodeに対応したchar型
	TCHAR StrBuf[128];	//インスタンスハンドルを保存する変数

	//wsprintf：文字列をフォーマット(%dなど)に従い、整形する
	//整形された文字列は、関数の先頭の配列(StrBuf)に入る
	wsprintf(StrBuf, TEXT("インスタンスハンドルの値:%d"), hInstance);

	//メッセージボックスを表示
	MessageBox(
		NULL,
		StrBuf,
		TEXT("Handle"),
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//文字列のコピーをしてみよう
	//+++++++++++++++++++++++++++++++++++++++++++++

	TCHAR strMoji[128] = TEXT("文字列をコピーします");
	TCHAR strCpy[128];

	//文字列をコピー
	lstrcpy(strCpy, strMoji);

	//メッセージボックスを表示
	MessageBox(
		NULL, 
		strCpy, 
		TEXT("COPY!!"), 
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//マルチバイトとユニコードの違いを知ろう
	//+++++++++++++++++++++++++++++++++++++++++++++

	//+++++++++++++++++++++++++++++++++++++++++++++
	//マルチバイト　　：１バイト(半角)だけでなく、
	//　　　　　　　　　２バイト(全角)や
	//　　　　　　　　　２バイト以上で表現する方法
	//※シングルバイト：１バイト(半角)で表現する方法
	//++++++++++++++++++++++++++++++++++++++++++++ +

	char strAlpha[11] =  "ABCDEFGHIJ" ;	//\0で+1
	char strHira[11] = "あいうえお";	//\0で+1
	const char *p_strNum = "12345";		//ポインタ

	char chShowAlpha[33];	//マルチバイト表示用
	char chShowHira[33];	//マルチバイト表示用
	char chShowNum[33];	//マルチバイト表示用

	//マルチバイトで、[C]を表示したい
	sprintf(chShowAlpha, "Alpha：%c", strAlpha[2]);

	//メッセージボックスをマルチバイトで表示
	MessageBoxA(
		NULL,
		chShowAlpha,
		"Multi Byte",
		MB_OK);

	//マルチバイトで、[う]を表示したい
	sprintf(chShowHira, "Hira：%c%c", strHira[4], strHira[5]);

	//メッセージボックスをマルチバイトで表示
	MessageBoxA(
		NULL,
		chShowHira,
		"Multi Byte",
		MB_OK);

	//マルチバイトで、[3]を表示したい
	sprintf(chShowNum, "Num：%c", *(p_strNum+2));

	//メッセージボックスをマルチバイトで表示
	MessageBoxA(
		NULL,
		chShowNum,
		"Multi Byte",
		MB_OK);
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//Unicode　　：２バイト(ワイド文字)で半角、全角を表現する方法
	//+++++++++++++++++++++++++++++++++++++++++++++
	wchar_t w_strAlpha[11] = L"ABCDEFGHIJ";	//\0で+1
	wchar_t w_strHira[11] = L"あいうえお";	//\0で+1
	const wchar_t *w_p_strNum = L"12345";	//ポインタ

	wchar_t w_chShowAlpha[33];	//Unicode表示用
	wchar_t w_chShowHira[33];	//Unicode表示用
	wchar_t w_chShowNum[33];	//Unicode表示用

	//Unicodeで、[C]を表示したい
	wsprintf(w_chShowAlpha, L"Alpha：%c", w_strAlpha[2]);

	//メッセージボックスをUnicodeで表示
	MessageBoxW(
		NULL,
		w_chShowAlpha,
		L"Wide(Unicode)",
		MB_OK);

	//Unicodeで、[う]を表示したい
	wsprintf(w_chShowHira, L"Hira：%c", w_strHira[2]);

	//メッセージボックスをUnicodeで表示
	MessageBoxW(
		NULL,
		w_chShowHira,
		L"Wide(Unicode)",
		MB_OK);

	//Unicodeで、[3]を表示したい
	wsprintf(w_chShowNum, L"Num：%c", *(w_p_strNum + 2));

	//メッセージボックスをUnicodeで表示
	MessageBoxW(
		NULL,
		w_chShowNum,
		L"Wide(Unicode)",
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//両方に対応する書き方
	//+++++++++++++++++++++++++++++++++++++++++++++
	TCHAR t_strAlpha[11] = TEXT("ABCDEFGHIJ");	//\0で+1
	TCHAR t_strHira[11] = TEXT("あいうえお");	//\0で+1
	const TCHAR *t_strNum= TEXT("12345");		//ポインタ

	TCHAR t_chShowAlpha[33];	//両方に対応する書き方の表示用
	TCHAR t_chShowHira[33];		//両方に対応する書き方の表示用
	TCHAR t_chShowNum[33];		//両方に対応する書き方の表示用

	//ロケール（地域言語）を日本語でセット
	//ファイル入出力とコンソールへの入出力の際にユニコードを使用するなら必須
	setlocale(LC_ALL, "Japanese");

	//両方に対応する書き方で、[C]を表示したい
	wsprintf(t_chShowAlpha, TEXT("Alpha：%c"), t_strAlpha[2]);

	//メッセージボックスを両方に対応する書き方で表示
	MessageBox(
		NULL,
		t_chShowAlpha,
		TEXT("Multi Byte & Wide(Unicode)"),
		MB_OK);


	//両方に対応する書き方で、[う]を表示したい
	wsprintf(t_chShowHira, TEXT("Hira：%c"), t_strHira[2]);

	//メッセージボックスを両方に対応する書き方で表示
	MessageBox(
		NULL,
		t_chShowHira,
		TEXT("Multi Byte & Wide(Unicode)"),
		MB_OK);

	//両方に対応する書き方で、[3]を表示したい
	wsprintf(t_chShowNum, TEXT("Num：%c"), *(t_strNum+2));

	//メッセージボックスを両方に対応する書き方で表示
	MessageBox(
		NULL,
		t_chShowNum,
		TEXT("Multi Byte & Wide(Unicode)"),
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//_TはTEXT()と同等の動作を行う
	//+++++++++++++++++++++++++++++++++++++++++++++

	//両方に対応する書き方で、[お]を表示したい
	wsprintf(t_chShowHira, _T("Hira：%c"), t_strHira[4]);

	//メッセージボックスを両方に対応する書き方で表示
	MessageBox(
		NULL,
		t_chShowHira,
		_T("Multi Byte & Wide(Unicode)"),
		MB_OK);

	//+++++++++++++++++++++++++++++++++++++++++++++
	//結局、データ型の再定義【法則性を見てみよう】
	//★★★すべて覚える必要はない★★★
	//(cont = 定数化 = 変数を初期化以降、値を変えることができない変数)
	//+++++++++++++++++++++++++++++++++++++++++++++
	char ch;				//ﾏﾙﾁﾊﾞｲﾄのデータ型
	char * p_ch;			//ﾏﾙﾁﾊﾞｲﾄのデータ型のポインタ
	const char * c_p_ch;	//ﾏﾙﾁﾊﾞｲﾄのデータ型(定数)のポインタ

	CHAR CH;				//char の再定義
	PSTR P_CH;				//char * の再定義
	LPSTR L_P_CH;			//char * の再定義(L = Long = 16ビットの名残)
	PCSTR C_P_CH;			//const char * の再定義
	//LPCSTR C_P_CH;			//const char * の再定義(L = Long = 16ビットの名残)

	wchar_t wch;			//ﾜｲﾄﾞ文字(Unicode)のデータ型
	wchar_t * p_wch;		//ﾜｲﾄﾞ文字(Unicode)のデータ型のポインタ
	const wchar_t * c_p_wch;//ﾜｲﾄﾞ文字(Unicode)のデータ型(定数)のポインタ

	WCHAR WCH;				//wchar_t の再定義
	PWSTR P_WCH;			//wchar_t * の再定義
	LPWSTR L_P_WCH;			//wchar_t * の再定義(L = Long = 16ビットの名残)
	PCWSTR C_P_WCH;			//const wchar_t * の再定義
	//LPCWSTR C_P_WCH;		//const wchar_t * の再定義(L = Long = 16ビットの名残)	

							//ﾜｲﾄﾞ文字 or ﾏﾙﾁﾊﾞｲﾄ
	TBYTE TBYTE;			//WCHAR    or CHAR   の再定義
	TCHAR TCH;				//WCHAR    or CHAR   の再定義
	TCHAR *P_TCH;			//PWSTR    or PSTR   の再定義
	const TCHAR *C_P_TCH;	//PCWSTR   or PCSTR  の再定義

	PTSTR P_TSR;			//PWSTR    or PSTR   の再定義
	LPTSTR L_P_STR;			//LPWSTR   or LPSTR  の再定義
	PCTSTR C_P_STR;			//PCWSTR   or PCSTR  の再定義
	LPCTSTR L_C_P_STR;		//LPCWSTR  or LPCSTR の再定義
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//出力ウィンドウに表示したい
	//+++++++++++++++++++++++++++++++++++++++++++++

	TCHAR debug_STR[32] = TEXT("");	//出力する変数

	for (int i = 0; i < 10; i++)
	{
		wsprintf(debug_STR, TEXT("DEBUG：%d\n"), i);

		//出力ウインドウに表示
		//デバッグの開始(F5)で表示される
		OutputDebugString(debug_STR);
	}

	//+++++++++++++++++++++++++++++++++++++++++++++
	//ウィンドウを表示したい
	//+++++++++++++++++++++++++++++++++++++++++++++
	DWORD dw;	//【参考】DWORD：32ビット 符号なし 整数 の再定義


	HWND hwnd;	//個々のWindowを識別する値(ウィンドウハンドル)

	//ウィンドウの作成(ウィンドウクラスの生成)
	//①引数：LPCTSTR lpszClassName	:ウィンドウクラスの名前を指定
	//②引数：LPCTSTR lpWindowName	:ウィンドウのタイトル
	//③引数：DWORD dwStyle			:ウィンドウの種類
	//④引数：int x					:ウインドウ左上のx座標(横の位置)
	//⑤引数：int y					:ウインドウ左上のy座標(縦の位置)
	//⑥引数：int nWidth			:ウインドウの幅
	//⑦引数：int nHeight			:ウインドウの高さ
	//⑧引数：HWND hwndParent		:親ウィンドウハンドル
	//⑨引数：HMENU hmenu			:メニューハンドル
	//⑩引数：HANDLE hinst			:インスタンスハンドル
	//⑪引数：LPVOID lpvParam		:作成されたウィンドウのハンドル

	hwnd = CreateWindow(
			TEXT("STATIC"),					//①変化しないウィンドウ：STATIC
			TEXT("タイトル"),				//②ウィンドウのタイトル：タイトル
			WS_CAPTION,						//③タイトルバーを持つウィンドウを作成：WS_CAPTION
			100,							//④横の位置：左上から100pxの位置
			100,							//⑤縦の位置：左上から100pxの位置
			200,							//⑥ウィンドウの幅　：横の位置から200px(右に向かって増える)
			200,							//⑦ウィンドウの高さ：縦の位置から200px(下に向かって増える)
			NULL,							//⑧親ウインドウハンドル：なし
			NULL,							//⑨メニューハンドル：なし
			hInstance,						//⑩インスタンスハンドル：なし
			NULL							//⑪作成されたウィンドウのハンドル：なし
		);

		//ウィンドウが生成されなかったとき
		if (hwnd == NULL)
		{
			//処理を終了させる
			return 0;
		}

		//ウィンドウを表示
		ShowWindow(
			hwnd,		//表示するウインドウハンドル
			SW_SHOW		//現在の位置とサイズで表示
		);

		//メッセージボックスを表示(ウィンドウがすぐに閉じないようにする)
		MessageBox(
			NULL,
			TEXT("OKを押すとウィンドウを閉じます"),
			TEXT("Multi Byte & Wide(Unicode)"),
			MB_OK);

	return 0;
}
*/