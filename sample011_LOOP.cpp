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

	//個々のWindowを識別する配列(ウィンドウハンドル)
	HWND hwndA[10];

	//ウィンドウ作成で使用
	int i;

	//ブラシを作成
	static HBRUSH brush;

	//ブラシの色を設定
	brush = CreateSolidBrush(RGB(255, 255, 255));

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

	
	
	
	
	
	
	
	
	
	
	
	
	
	//+++++++++++++++++++++++++++++++++++++++++++++
	//ウィンドウを10個、連続で作成し、連続で表示する
	//+++++++++++++++++++++++++++++++++++++++++++++
	for (i = 0; i < 10; i++)
	{
		hwndA[i] = CreateWindow(
			TEXT(MY_WIN_CLASS),
			TEXT("自分で登録したウィンドウクラス"),
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,	//デフォルトの値を使用
			CW_USEDEFAULT,	//デフォルトの値を使用
			CW_USEDEFAULT,	//デフォルトの値を使用
			CW_USEDEFAULT,	//デフォルトの値を使用
			NULL,
			NULL,
			hInstance,
			NULL);

		//ウィンドウが生成されなかったとき
		if (hwndA[i] == NULL)
		{
			//処理を終了させる
			return 0;
		}

		//ウィンドウを表示
		ShowWindow(
			hwndA[i],	//表示するウインドウハンドル
			SW_SHOW		//現在の位置とサイズで表示
		);
	}

	//メッセージを受け取り続ける
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	//ブラシの開放
	DeleteObject(brush);

	return msg.wParam;
}

//ウィンドウプロシージャ(関数)を作成
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
		case WM_CREATE:
			//ウィンドウが生成されたとき
		
			//ウィンドウを生成するときは、0を返す
			return 0;

		case WM_DESTROY:
			//ウィンドウが破棄された(なくなった)とき

			//メッセージキューに WM_QUIT を送る
			PostQuitMessage(0);
			return 0;
	}

	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, msg, wp, lp);
}
*/