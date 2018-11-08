/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前

//プロトタイプ宣言

LRESULT CALLBACK MY_WndProc(HWND , UINT , WPARAM , LPARAM );//ウィンドウプロシージャ

int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{
	//メッセージを保存する構造体
	MSG msg;

	//ウィンドウクラスを管理する構造体
	WNDCLASS winc;

	//個々のWindowを識別する値(ウィンドウハンドル)
	HWND hwnd;

	//ブラシを作成
	static HBRUSH brush;

	//ブラシの色を設定
	brush = CreateSolidBrush(RGB(0, 255, 0));

	//↓↓↓ウィンドウクラスの設定はここから↓↓↓
	winc.style = CS_HREDRAW | CS_VREDRAW;
	
	//★★★自分で作成したｳｨﾝﾄﾞｳﾌﾟﾛｼｰｼﾞｬに変更★★★
	winc.lpfnWndProc = MY_WndProc;

	winc.cbClsExtra = 0;
	winc.cbWndExtra = 0;
	winc.hInstance = hInstance;
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	winc.hbrBackground = brush;
	winc.lpszMenuName = NULL;
	winc.lpszClassName = TEXT(MY_WIN_CLASS);
	//↑↑↑ウィンドウクラスの設定はここまで↑↑↑

	//ウィンドウクラスを登録する
	if (!RegisterClass(&winc))
	{
		//登録ができなかったら、プログラムを終了する
		return 0;
	}

	//ウィンドウの作成(ウィンドウクラスの生成)
	hwnd = CreateWindow(
		TEXT(MY_WIN_CLASS),
		TEXT("自分で登録したウィンドウクラス"),
		WS_OVERLAPPEDWINDOW,
		100,
		100,
		600,
		600,
		NULL,
		NULL,
		hInstance,
		NULL);

	//ウィンドウが生成されなかったとき
	if (hwnd == NULL)
	{
		return 0;//処理を終了させる
	}

	//ウィンドウを表示
	ShowWindow(
		hwnd,		//表示するウインドウハンドル
		SW_SHOW		//現在の位置とサイズで表示
	);

	//メッセージを絶えず受け取り続ける
	while (TRUE)
	{
		GetMessage(&msg, NULL, 0, 0);
		DispatchMessage(&msg);
	}

	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++
//ウィンドウプロシージャ(関数)を作成
//自分で作成できる関数なので、関数の名前(WndProc)は自由に決められる
//+++++++++++++++++++++++++++++++++++++++++++++
//戻り値：LRESULT	この関数が返す、32ビットの値
//引　数：HWND hwnd	メッセージが発生したウィンドウのハンドル
//引　数：UINT msg	メッセージを識別する整数
//引　数：WPARAM wp	メッセージの付加情報その１
//引　数：LPARAM lp	メッセージの付加情報その２
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
		case WM_LBUTTONUP:
			//マウスの左ボタンを押したとき

			//メッセージボックスを表示
			MessageBox(
				hwnd,	//作成したウィンドウから呼び出されたメッセージボックス
				TEXT("マウスの左ボタンを押しました"),
				TEXT("LEFT"),
				MB_OK);
			break;

		case WM_MBUTTONDOWN:
			//マウスの真ん中ボタンを押したとき

			//メッセージボックスを表示
			MessageBox(
				hwnd,	//作成したウィンドウから呼び出されたメッセージボックス
				TEXT("マウスの真ん中ボタンを押しました"),
				TEXT("MIDDLE"),
				MB_OK);
			break;

		case WM_RBUTTONUP:
			//マウスの右ボタンを押したとき

			//メッセージボックスを表示
			MessageBox(
				hwnd,	//作成したウィンドウから呼び出されたメッセージボックス
				TEXT("マウスの右ボタンを押しました"),
				TEXT("RIGHT"),
				MB_OK);
			break;

	}
	
	//デフォルトのウィンドウプロシージャ関数を呼び出す
	//理由は、基本的なウィンドウの動作をさせたいため
	return DefWindowProc(hwnd, msg, wp, lp);
}



//コラム：MSG構造体のメンバ
//typedef struct tagMSG
//{
//	HWND   hwnd;	//メッセージが発生したウィンドウのハンドル
//	UINT   message;	//メッセージを識別する整数
//	WPARAM wParam;	//メッセージの付加情報その１
//	LPARAM lParam;	//メッセージの付加情報その２
//	DWORD  time;	//メッセージが送られた時間
//	POINT  pt;		//メッセージが送られたときのカーソルの位置
//} MSG, *PMSG;

//課題：ウィンドウプロシージャの名前を変更する
//変更前：WndProc
//変更後：MY_WndProc

//答え：変更する箇所
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);		//ウィンドウプロシージャ
//LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);	//ウィンドウプロシージャ

//winc.lpfnWndProc = WndProc;		//ウィンドウクラス作成時
//winc.lpfnWndProc = MY_WndProc;	//ウィンドウクラス作成時

//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)		//関数
//LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)	//関数

*/