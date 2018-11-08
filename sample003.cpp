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
		TEXT("STATIC"),					//①テキストフィールド用クラス：STATIC
		TEXT("タイトル"),				//②ｳｨﾝﾄﾞｳのタイトル：タイトル
		WS_CAPTION,						//③タイトルバーを持つｳｨﾝﾄﾞｳ：WS_CAPTION
		100,							//④横の位置：左上から100pxの位置
		100,							//⑤縦の位置：左上から100pxの位置
		200,							//⑥ｳｨﾝﾄﾞｳの幅：横の位置から200px(右に増える)
		200,							//⑦ｳｨﾝﾄﾞｳの高：縦の位置から200px(下に増える)
		NULL,							//⑧親ｳｨﾝﾄﾞｳハンドル：なし
		NULL,							//⑨メニューハンドル：なし
		hInstance,						//⑩インスタンスハンドル：なし
		NULL							//⑪作成されたｳｨﾝﾄﾞｳのハンドル：なし
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
		TEXT("Message"),
		MB_OK);

	return 0;
}

//課題１：ウィンドウのタイトルを"TITLE"に変更してみよう
//課題２：ウィンドウの横の位置を300、縦の位置を300に変更しよう
//課題３：ウィンドウの幅を500、高さを500に変更しよう

//変更例
//hwnd = CreateWindow(
//	TEXT("STATIC"),					//①テキストフィールド用クラス：STATIC
//	TEXT("TITLE"),					//②ウィンドウのタイトル：タイトル
//	WS_CAPTION,						//③タイトルバーを持つウィンドウを作成：WS_CAPTION
//	300,							//④横の位置：左上から300pxの位置
//	300,							//⑤縦の位置：左上から300pxの位置
//	500,							//⑥ウィンドウの幅　：横の位置から500px(右に向かって増える)
//	500,							//⑦ウィンドウの高さ：縦の位置から500px(下に向かって増える)
//	NULL,							//⑧親ウインドウハンドル：なし
//	NULL,							//⑨メニューハンドル：なし
//	hInstance,						//⑩インスタンスハンドル：なし
//	NULL							//⑪作成されたウィンドウのハンドル：なし
//);
*/