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

	//背景モードを保存
	int bk_mode = 0;

	//領域を管理する構造体
	RECT rect_c;		//クライアント領域
	RECT rect_w;		//ウィンドウ領域
	RECT rect_str;	//表示する文字の領域

	//TEXTMETRIC：フォントの詳細情報を持つメトリックス構造体
	TEXTMETRIC tm;

	//HDC：デバイスコンテキストのハンドル
	HDC hdc;

	//PAINTSTRUCT：ウィンドウごとの描画情報を管理する構造体
	PAINTSTRUCT ps;

	//表示する文字列のポインタ
	LPCTSTR DrawStr1 = TEXT("表示する\n文字列１");
	LPCTSTR DrawStr2 = TEXT("表示する\n文字列２");
	LPCTSTR DrawStr3 = TEXT("表示する\n文字列３");
	LPCTSTR DrawStr4 = TEXT("表示する\n文字列４表示する\n文字列４表示する\n文字列４表示する\n文字列４");

	switch (msg)
	{

	case WM_CREATE:
		//ウィンドウの生成＆初期化

		//ウィンドウを生成するときは、0を返す
		return 0;

		
		
		
		
		
		
		
		
		
		
		
	case WM_PAINT:
		//ウィンドウ内を再描画するとき

		//+++++++++++++++++++++++++++++++++++++++++++++
		//ウィンドウに文字を再描画する
		//+++++++++++++++++++++++++++++++++++++++++++++

		//デバイスコンテキストのハンドルを取得
		hdc = BeginPaint(hwnd, &ps);

		//フォントの詳細情報を取得
		GetTextMetrics(hdc, &tm);

		//+++++++++++++++++++++++++++++++++++++++++++++
		//文字を改行風に描画する
		//+++++++++++++++++++++++++++++++++++++++++++++

		//文字を描画（tm.tmHeightは、文字の高さを表す）
		TextOut(hdc, 50, tm.tmHeight * 0 + 50, DrawStr1, lstrlen(DrawStr1));
		TextOut(hdc, 50, tm.tmHeight * 1 + 50, DrawStr2, lstrlen(DrawStr2));
		TextOut(hdc, 50, tm.tmHeight * 2 + 50, DrawStr3, lstrlen(DrawStr3));
		TextOut(hdc, 50, tm.tmHeight * 3 + 50, DrawStr4, lstrlen(DrawStr4));

		//文字を描画
		//tm.tmAveCharWidthは、小文字の平均的な幅を表す
		TextOut(hdc, tm.tmAveCharWidth * lstrlen(DrawStr1) + 50, tm.tmHeight * 0 + 50, DrawStr1, lstrlen(DrawStr1));
		TextOut(hdc, tm.tmAveCharWidth * lstrlen(DrawStr2) + 50, tm.tmHeight * 1 + 50, DrawStr2, lstrlen(DrawStr2));
		//tm.tmMaxCharWidthは、文字列の中で最も広い幅を表す
		TextOut(hdc, tm.tmMaxCharWidth * lstrlen(DrawStr3) + 50, tm.tmHeight * 2 + 50, DrawStr3, lstrlen(DrawStr3));
		TextOut(hdc, tm.tmMaxCharWidth * lstrlen(DrawStr4) + 50, tm.tmHeight * 3 + 50, DrawStr4, lstrlen(DrawStr4));

		//+++++++++++++++++++++++++++++++++++++++++++++
		//文字色を変える
		//+++++++++++++++++++++++++++++++++++++++++++++
		SetTextColor(hdc, RGB(255, 0, 0));	//文字色を赤にする
		TextOut(hdc, 50, tm.tmHeight * 4 + 50, DrawStr1, lstrlen(DrawStr1));

		SetTextColor(hdc, RGB(0, 255, 0));	//文字色を緑にする
		TextOut(hdc, 50, tm.tmHeight * 5 + 50, DrawStr2, lstrlen(DrawStr2));
		TextOut(hdc, 50, tm.tmHeight * 6 + 50, DrawStr3, lstrlen(DrawStr3));

		SetTextColor(hdc, RGB(0, 0, 255));	//文字色を青にする
		TextOut(hdc, 50, tm.tmHeight * 7 + 50, DrawStr4, lstrlen(DrawStr4));

		//+++++++++++++++++++++++++++++++++++++++++++++
		//背景色を変える
		//+++++++++++++++++++++++++++++++++++++++++++++
		SetBkColor(hdc, RGB(255, 0, 0));	//背景色を赤にする
		TextOut(hdc, 50, tm.tmHeight * 8 + 50, DrawStr1, lstrlen(DrawStr1));

		SetBkMode(hdc, OPAQUE);				//背景を塗りつぶす
		SetBkColor(hdc, RGB(0, 255, 0));	//背景色を緑にする
		TextOut(hdc, 50, tm.tmHeight * 9 + 50, DrawStr2, lstrlen(DrawStr2));
		TextOut(hdc, 50, tm.tmHeight * 10 + 50, DrawStr3, lstrlen(DrawStr3));

		bk_mode = GetBkMode(hdc);			//現在の背景モードを取得

		SetBkMode(hdc, TRANSPARENT);		//背景を塗りつぶさない
		SetBkColor(hdc, RGB(0, 0, 255));	//背景色を青にする
		TextOut(hdc, 50, tm.tmHeight * 11 + 50, DrawStr4, lstrlen(DrawStr4));

		SetBkColor(hdc, RGB(127, 127, 127));//背景色を灰色にする
		TextOut(hdc, 50, tm.tmHeight * 12 + 50, DrawStr4, lstrlen(DrawStr4));

		
		
		
		//+++++++++++++++++++++++++++++++++++++++++++++
		//領域に文字を描画する
		//+++++++++++++++++++++++++++++++++++++++++++++
		//クライアント領域を取得
		GetClientRect(hwnd, &rect_c);

		//ウィンドウ領域を取得
		GetWindowRect(hwnd, &rect_w);

		//　　ウインドウ領域：PCの画面の領域(大きさ)
		//　クライアント領域：アプリケーションで、描画ができる領域(大きさ)
		//非クライアント領域：タイトルバーなど、描画できない領域(大きさ)

		rect_str.left = 0;				//左上のX座標(横)
		rect_str.top = 400;				//左上のY座標(縦)
		rect_str.right = 0 + 200;		//右下のX座標(横)
		rect_str.bottom = 400 + 200;	//右下のY座標(縦)

		SetBkMode(hdc, OPAQUE);					//背景を塗りつぶす
		SetTextColor(hdc, RGB(0, 0, 0));		//文字色を黒にする
		SetBkColor(hdc, RGB(255, 255, 255));	//背景色を白にする

		//文字列を表示
		DrawText(
			hdc,				//デバイスコンテキストのハンドル
			DrawStr4,			//描画する文字
			-1,					//文字列の文字数：-1なら自動的に計算
			&rect_str,			//描画する領域
			DT_LEFT				//左揃え
			| DT_WORDBREAK);	//文字列が表示できなくなれば改行

		//+++++++++++++++++++++++++++++++++++++++++++++
		//現在のデバイスコンテキストを保存・復元する
		//+++++++++++++++++++++++++++++++++++++++++++++

		//現在のデバイスコンテキストを保存する
		SaveDC(hdc);
		
		SetTextColor(hdc, RGB(255, 255, 255));		//文字色を白にする
		SetBkColor(hdc, RGB(0, 0, 0));				//背景色を黒にする

		//文字を描画
		TextOut(hdc, 0, 0, TEXT("HOZON_HOZON_HOZON"), lstrlen(TEXT("HOZON_HOZON_HOZON")));

		//保存したデバイスコンテキスを復元する
		RestoreDC(hdc, -1);	//-1なら、1回前に保存したデバイスコンテキストを復元

		//文字を描画
		TextOut(hdc, 0, tm.tmHeight * 1, TEXT("HUKUGEN_HUKUGEN"), lstrlen(TEXT("HUKUGEN_HUKUGEN")));

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