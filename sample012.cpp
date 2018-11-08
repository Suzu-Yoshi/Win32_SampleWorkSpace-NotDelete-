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
	//+++++++++++++++++++++++++++++++++++++++++++++
	//ウィンドウに文字を描画する
	//+++++++++++++++++++++++++++++++++++++++++++++
	//Windows では、ウィンドウや文字も含め、全てを「画像」として扱う
	//そのため、例えば、文字表示したいなら「出力」ではなく「描画」して表現する
	//「描画」するには、 GDI ファンクションを使用する
	//GDI：Graphics Device Interface：グラフィック関連のプログラム

	//HDC：デバイスコンテキストのハンドル
	//デバイスコンテキスト：GDIで使用する構造体：描画を行うときに使用する
	HDC hdc;
	
	//表示する文字列のポインタ
	LPCTSTR DrawStr = TEXT("表示する文字列１");
	LPCTSTR DrawStr2 = TEXT("表示する文字列２");

	switch (msg)
	{
	case WM_CREATE:
		//ウィンドウの生成＆初期化

		//ウィンドウを生成するときは、0を返す
		return 0;

		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	case WM_LBUTTONDOWN:
		//マウスの左ボタンを押したとき

		//デバイスコンテキストのハンドルを取得
		hdc = GetDC(hwnd);	//描画するウィンドウハンドルを引数にする

		//文字を表示
		TextOut(
			hdc,				//デバイスコンテキストのハンドル
			10,					//文字の開始位置(X座標：横)
			10,					//文字の開始位置(Y座標：縦)
			DrawStr,			//表示する文字列のポインタ
			lstrlen(DrawStr));	//文字列の文字数：(lstrlen：文字数を数える)

		TextOut(hdc,100,100, DrawStr2,lstrlen(DrawStr2));

		//デバイスコンテキストのハンドルを解放
		ReleaseDC(hwnd, hdc);

		break;

	case WM_DESTROY:
		//ウィンドウが破棄された(なくなった)とき

		//メッセージキューに WM_QUIT を送る
		PostQuitMessage(0);
		return 0;
	}

	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, msg, wp, lp);
}

//実験：文字の再描画
//1.一度、画面を最小化をしてみる
//2.その後、画面を最大化すると、文字はどうなるだろう？
*/