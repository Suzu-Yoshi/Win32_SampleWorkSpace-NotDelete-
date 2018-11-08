//+++++++++++++++++++++++++++++++++++++++++++++
//
//+++++++++++++++++++++++++++++++++++++++++++++

//+++++++++++++++++++++++++++++++++++++++++++++
//ヘッダーファイル読み込み
//+++++++++++++++++++++++++++++++++++++++++++++
#include <windows.h>

//+++++++++++++++++++++++++++++++++++++++++++++
//マクロ定義
//+++++++++++++++++++++++++++++++++++++++++++++

//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前
#define MY_WIN_CLASS "MY_WIN_CLASS"	

//ウィンドウの場所を大きさを設定
#define WIN_X 100		//横の位置
#define WIN_Y 100		//縦の位置
#define WIN_WIDTH 500	//幅
#define WIN_HEIGHT 500	//高さ

//+++++++++++++++++++++++++++++++++++++++++++++
//プロトタイプ宣言
//+++++++++++++++++++++++++++++++++++++++++++++

//ウィンドウプロシージャ
LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);

//+++++++++++++++++++++++++++++++++++++++++++++
//グローバル変数の宣言と初期化
//+++++++++++++++++++++++++++++++++++++++++++++

//マウスのボタンを押しているかを入れる変数
BOOL isDrag = FALSE;

//マウスの座標を管理する構造体
POINT pt_Start = { 0,0 };

//ウィンドウサイズを管理する構造体
SIZE window_Size = { 0,0 };

//領域を管理する構造体
RECT rect_c;	//クライアント領域を管理

				//+++++++++++++++++++++++++++++++++++++++++++++
				//プログラムで最初に実行される関数
				//+++++++++++++++++++++++++++++++++++++++++++++
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
	HBRUSH brush;

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
	//ウィンドウスタイルにWS_VISIBLEを指定したら、WM_PAINTを送る
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

	//クライアント領域を取得
	GetClientRect(hwnd, &rect_c);

	//ウィンドウを表示
	//SW_SHOWを指定したら、WM_PAINTを送る
	ShowWindow(
		hwnd,		//表示するウインドウハンドル
		SW_SHOW		//現在の位置とサイズで表示
	);

	//WM_PAINTを直接ウィンドウプロシージャに送る
	//UpdateWindow(hwnd);

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

	//マウスの座標の文字列を入れる変数
	TCHAR StrBuf[64];

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


		//点を描画
		SetPixel(hdc, pt_Start.x, pt_Start.y, RGB(0, 0, 0));

		//マウスの座標を整形
		wsprintf(StrBuf, TEXT("マウスの位置(X:%03d,Y:%03d)"), pt_Start.x, pt_Start.y);

		//文字の描画部分にそのまま上書きする
		//SetBkMode(hdc, TRANSPARENT);			//背景を塗りつぶさない

		//文字を描画部分の背景も書き直す
		SetBkMode(hdc, OPAQUE);					//背景を塗りつぶす

		SetTextColor(hdc, RGB(0, 0, 0));		//文字色を白にする
		SetBkColor(hdc, RGB(255, 255, 255));	//背景色を黒にする

												//マウスの座標を描画
		DrawText(hdc, StrBuf, -1, &rect_c, DT_LEFT);

		//保存したデバイスコンテキスを復元する
		RestoreDC(hdc, -1);

		//デバイスコンテキストのハンドルを開放する
		EndPaint(hwnd, &ps);

		return 0;
	case WM_LBUTTONDOWN:
		//マウスの左ボタンを押しているとき

		//マウスの座標を取得
		//LPARAM lpには、マウスの座標が入っている
		//その中で、上位16ビットには、y座標が入っている
		//その中で、下位16ビットには、x座標が入っている

		//DWORD型(32ビット)の上位WORD(16ビット)を取り出す
		pt_Start.y = HIWORD(lp);
		//DWORD型(32ビット)の下位WORD(16ビット)を取り出す
		pt_Start.x = LOWORD(lp);

		//マウスのボタンを「押した」判定をする
		if (isDrag == FALSE)
		{
			isDrag = TRUE;
		}

		//無効リージョンを発生
		InvalidateRect(
			hwnd,	//無効リージョンを発生させるウィンドウハンドル
			NULL,	//無効化する領域：NULLならクライアント領域全体
			FALSE);	//TRUE：背景を消去/FALSE：背景をそのまま残す

					//画面を、すぐに再描画する
					//WM_PAINTを直接ウィンドウプロシージャに送る関数
		UpdateWindow(hwnd);

		break;






	case WM_LBUTTONUP:
		//マウスの左ボタンを上げたとき

		//マウスのボタンを「上げた」判定をする
		if (isDrag == TRUE)
		{
			isDrag = FALSE;
		}

		//無効リージョンを発生
		//OS(Windows)が、WM_PAINTを直接ウィンドウプロシージャに送る
		//無効リージョン(領域)は再描画される
		InvalidateRect(hwnd, NULL, FALSE);

		//画面を、すぐに再描画する
		//WM_PAINTを直接ウィンドウプロシージャに送る関数
		UpdateWindow(hwnd);

		break;

	case WM_MOUSEMOVE:
		//マウスカーソルが移動したとき

		//DWORD型(32ビット)の下位WORD(16ビット)を取り出す
		pt_Start.x = LOWORD(lp);
		//DWORD型(32ビット)の上位WORD(16ビット)を取り出す
		pt_Start.y = HIWORD(lp);

		//無効リージョンを発生
		InvalidateRect(hwnd, NULL, FALSE);

		//画面を、すぐに再描画する
		UpdateWindow(hwnd);

		break;
	case WM_SIZE:
		//画面のサイズが変わったとき

		//ウィンドウのサイズを取得
		//LPARAM lpには、ウインドウのサイズが入っている
		//その中で、上位16ビットには、高さのサイズが入っている
		//その中で、下位16ビットには、幅のサイズが入っている

		//DWORD型(32ビット)の上位WORD(16ビット)を取り出す
		window_Size.cy = HIWORD(lp);
		//DWORD型(32ビット)の下位WORD(16ビット)を取り出す
		window_Size.cx = LOWORD(lp);

		//画面がどのように変化したか判断
		switch (wp)
		{
		case SIZE_RESTORED:
			//ウィンドウサイズが変わったとき



			break;
		case SIZE_MINIMIZED:
			//ウィンドウが最小化されたとき

			break;

		case SIZE_MAXIMIZED:
			//ウィンドウが最大化されたとき

			break;
		}

		//画面が変更されたら、WM_PAINTを直接ウィンドウプロシージャに送るため
		//再描画の処理は不要である

		//無効リージョンを発生
		//InvalidateRect(hwnd, NULL, FALSE);

		//画面を、すぐに再描画する
		//UpdateWindow(hwnd);

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