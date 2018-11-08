/*
#include<windows.h>

#include<math.h>
#define PAI 3.14159


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
	brush = CreateSolidBrush(RGB(255, 255, 255));

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

	//領域を管理する構造体
	RECT rect_c;		//クライアント領域

	//PAINTSTRUCT：ウィンドウごとの描画情報を管理する構造体
	PAINTSTRUCT ps;

	//色情報を管理する整数
	COLORREF get_col;	//指定した座標の色を取得

	int cnt_x;
	int cnt_y;
	int cnt_c;
	double cnt_c_x;
	double cnt_c_y;

	int KANKAKU = 30;	//線の間隔を設定
	int haba = 20;		//渦巻きの幅を設定

	switch (msg)
	{

	case WM_CREATE:
		//ウィンドウの生成＆初期化

		//ウィンドウを生成するときは、0を返す
		return 0;












		
		
		
		
	case WM_PAINT:
		//ウィンドウ内を再描画するとき

		//デバイスコンテキストのハンドルを取得
		hdc = BeginPaint(hwnd, &ps);

		//現在のデバイスコンテキストを保存する
		SaveDC(hdc);

		//クライアント領域を取得
		GetClientRect(hwnd, &rect_c);

		//画面の幅いっぱいに点を描画する
		for (cnt_x = 0; cnt_x < rect_c.right; cnt_x++)
		{
			//点を描画
			SetPixel(hdc, cnt_x, KANKAKU, RGB(0, 0, 0));
		}

		//画面の高さいっぱいに点を描画する
		for (cnt_y = 0; cnt_y < rect_c.bottom; cnt_y++)
		{
			//点を描画
			SetPixel(hdc, KANKAKU, cnt_y, RGB(0, 0, 0));
		}

		//組み合わせて格子柄を描画
		//横の線
		for (cnt_y = 0; cnt_y < rect_c.bottom; cnt_y += KANKAKU)
		{
			for (cnt_x = 0; cnt_x < rect_c.right; cnt_x++)
			{
				//点を描画
				SetPixel(hdc, cnt_x, cnt_y, RGB(0, 0, 0));
			}
		}
		//縦の線
		for (cnt_x = 0; cnt_x < rect_c.right; cnt_x += KANKAKU)
		{
			for (cnt_y = 0; cnt_y < rect_c.bottom; cnt_y++)
			{
				//点を描画
				SetPixel(hdc, cnt_x, cnt_y, RGB(0, 0, 0));
			}
		}

		//組み合わせてドット柄を描画
		for (cnt_y = 0; cnt_y < rect_c.bottom; cnt_y += KANKAKU)
		{
			for (cnt_x = 0; cnt_x < rect_c.right; cnt_x += KANKAKU)
			{
				//点を描画
				SetPixel(hdc, cnt_x, cnt_y, RGB(255, 255, 255));
			}
		}

		//円を描画
		for (cnt_c = 0; cnt_c < 360; cnt_c++)
		{
			cnt_c_x = rect_c.right / 2 + KANKAKU * sin(cnt_c * PAI / 45);
			cnt_c_y = rect_c.bottom / 2 - KANKAKU * cos(cnt_c * PAI / 45);

			//点を描画
			SetPixel(hdc, (int)cnt_c_x, (int)cnt_c_y, RGB(255, 0, 0));
		}

		
		
		
		
		
		//うずまきを描画
		for (cnt_c = 0; cnt_c < 360 * 15; cnt_c++)
		{
			cnt_c_x = rect_c.right / 2 + (cnt_c / haba)* sin(cnt_c * PAI / 180);
			cnt_c_y = rect_c.bottom / 2 - (cnt_c / haba)* cos(cnt_c * PAI / 180);

			//点を描画
			SetPixel(hdc, (int)cnt_c_x, (int)cnt_c_y, RGB(0, 0, 255));
		}

		//指定した座標の色を取得
		get_col = GetPixel(hdc, 0, 0);

		//保存したデバイスコンテキスを復元する
		RestoreDC(hdc, -1);

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