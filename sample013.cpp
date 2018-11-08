/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前

//ウィンドウの場所を大きさを設定
#define WIN_X 100		//横の位置
#define WIN_Y 100		//縦の位置
#define WIN_WIDTH 500	//幅
#define WIN_HEIGHT 500	//高さ

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

	//ウィンドウクラスの設定はここから
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

	//ウィンドウクラスを登録する
	if (!RegisterClass(&winc))
	{
		//登録ができなかったら、プログラムを終了する
		return 0;
	}

	//ウィンドウの生成(ウィンドウクラスの生成)
	hwnd = CreateWindow(
		TEXT(MY_WIN_CLASS),
		TEXT("自分で登録したウィンドウクラス"),
		WS_OVERLAPPEDWINDOW,
		WIN_X,
		WIN_Y,
		WIN_WIDTH,
		WIN_HEIGHT,
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

	//HDC：デバイスコンテキストのハンドル
	HDC hdc;

	//PAINTSTRUCT：ウィンドウごとの描画情報を管理する構造体
	PAINTSTRUCT ps;

	//表示する文字列のポインタ
	LPCTSTR DrawStr1 = TEXT("表示する文字列１");
	LPCTSTR DrawStr2 = TEXT("表示する文字列２");
	LPCTSTR DrawStr3 = TEXT("表示する文字列３");
	LPCTSTR DrawStr4 = TEXT("表示する文字列４");

	switch (msg)
	{

	case WM_CREATE:
		//ウィンドウの生成＆初期化

		//ウィンドウを生成するときは、0を返す
		return 0;

	case WM_LBUTTONDOWN:
		//マウスの左ボタンを押したとき

		//デバイスコンテキストのハンドルを取得
		hdc = GetDC(hwnd);

		//文字を描画
		TextOut(hdc,50,50, DrawStr1,lstrlen(DrawStr1));
		TextOut(hdc, 150, 150, DrawStr2, lstrlen(DrawStr2));

		//デバイスコンテキストのハンドルを解放
		ReleaseDC(hwnd, hdc);

		break;

		
		
		
		
		
		
		
		
		
	case WM_PAINT:
		//+++++++++++++++++++++++++++++++++++++++++++++
		//ウィンドウに文字を再描画する
		//+++++++++++++++++++++++++++++++++++++++++++++

		//一つ前のプログラムで、画面を最小化、最大化したときに文字が消えたのは、
		//画面が消えたときに、画面の情報が消えてしまうから。
		//画面の情報が消えた状態を「無効リージョン」と呼ぶ
		//無効リージョンがウィンドウにある場合、
		//Windows(OS) が WM_PAINT メッセージを発行する
		//WM_PAINTで、多くの場所(タイトルや背景など)の「無効な領域だけ」を再描画してくれるが、
		//細かなところは、プログラムでも再描画することを書く必要がある
		//そうして、無効リージョンを再描画し、画面を有効な状態にする

		//無効な場所を再び描きなおして、有効化する(デバイスコンテキストのハンドルも取得)
		hdc = BeginPaint(hwnd, &ps);

		//文字を描画
		TextOut(hdc, 10, 10, DrawStr3, lstrlen(DrawStr4));
		TextOut(hdc, 100, 100, DrawStr4, lstrlen(DrawStr4));

		//デバイスコンテキストのハンドルを開放する
		EndPaint(hwnd, &ps);
		
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