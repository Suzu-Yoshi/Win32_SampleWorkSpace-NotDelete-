/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前

//プロトタイプ宣言

LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);//ウィンドウプロシージャ

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



	
	//ウィンドウの生成(ウィンドウクラスの生成)
	// ウィンドウを生成する前に WM_CREATE を
	// メッセージキューに入ることなくウィンドウプロシージャに送る
	// ウィンドウが生成されなかったとき、CreateWindowはNULLを返す
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
		//処理を終了させる
		return 0;
	}

	//ウィンドウを表示
	ShowWindow(
		hwnd,		//表示するウインドウハンドル
		SW_SHOW		//現在の位置とサイズで表示
	);

	//メッセージを受け取り続ける
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//ウィンドウプロシージャ(関数)を作成
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{

	case WM_CREATE:
		//+++++++++++++++++++++++++++++++++++++++++++++
		//ウィンドウを作成させたくないとき
		//+++++++++++++++++++++++++++++++++++++++++++++
		int ret_kekka;

		ret_kekka = MessageBox(
			hwnd,
			TEXT("ウィンドウを生成しますか？"),
			TEXT("CREATE WINDOW ?"),
			MB_YESNO | MB_ICONQUESTION);

		if (ret_kekka == IDYES)
		{
			//ウィンドウを生成するときは、0を返す
			return 0;
		}
		else if (ret_kekka == IDNO)
		{
			//ウィンドウを生成しないときは、-1を返す
			return -1;
		}

	case WM_LBUTTONUP:
		//マウスの左ボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("マウスの左ボタンを押しました"),
			TEXT("LEFT"),
			MB_OK);
		break;

	case WM_MBUTTONDOWN:
		//マウスの真ん中ボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("マウスの真ん中ボタンを押しました"),
			TEXT("MIDDLE"),
			MB_OK);
		break;

	case WM_RBUTTONUP:
		//マウスの右ボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("マウスの右ボタンを押しました"),
			TEXT("RIGHT"),
			MB_OK);
		break;
		case WM_CLOSE:
		//閉じるボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
		hwnd,
		TEXT("ウィンドウを終了させません"),
		TEXT("NOT CLOSE"),
		MB_OK);

		return 0;

		case WM_DESTROY:
		//ウィンドウが破棄された(なくなった)とき

		//メッセージボックスを表示
		MessageBox(
		hwnd,
		TEXT("ウィンドウを破棄しました"),
		TEXT("DESTROY"),
		MB_OK);

		//メッセージキューに WM_QUIT を送る
		PostQuitMessage(0);
		return 0;
	}
	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, msg, wp, lp);
}
*/