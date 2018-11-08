/*☆自分で設定したフォントで、文字を描画しよう☆
/*注意：プリントの\(バックスラッシュ)は、半角の￥マークです*/
/*※記入例と注意事項は以下の中にあります。参考にしてください。
  学生共有サーバ\担当\41.G1_Win32API
  */
  /*
 １．ヘッダーファイル読み込みに追加する
	#include <math.h>

 ２．マクロ定義に追加する
	//円周率
	#define MY_PI 3.1415926

 ３．プロトタイプ宣言を追加する
	 //線を描画する
	 void MY_DRAW_LINE(HDC);

	 //図形を描画する
	 void MY_DRAW_GRAPH(HDC);

 ４．線を描く【関数】を追加する
	//------------------------------------------------
	//線を描画する関数
	//------------------------------------------------
	void MY_DRAW_LINE(HDC hdc)
	{
		//++++++++++++++++++++++++++++++++++++++++
		//線を描く
		//++++++++++++++++++++++++++++++++++++++++

		//XY座標を１つ格納できるPOINT構造体
		POINT pt_line = { 250,250 };

		//線をどこから描き始めるか設定する
		//カレントポジションという
		MoveToEx(
			hdc,				//デバイスコンテキストのハンドル
			pt_line.x,			//描き始めるX座標
			pt_line.y,			//描き始めるY座標
			NULL);				//以前のカレントポジション取得/必要ないならNULL

		//線を描く(縦棒)
		LineTo(
			hdc,				//デバイスコンテキストのハンドル
			pt_line.x,			//描き終わるX座標
			pt_line.y + 200);	//描き終わるY座標

		//線をどこから描き始めるか設定する
		MoveToEx(hdc,pt_line.x,pt_line.y,NULL);

		//線を描く(横棒)
		LineTo(hdc,pt_line.x + 200,pt_line.y);

		//線をどこから描き始めるか設定する
		MoveToEx(hdc,pt_line.x,pt_line.y,NULL);

		//線を描く(斜め棒)
		LineTo(hdc,pt_line.x + 200,pt_line.y + 200);




	   //++++++++++++++++++++++++++++++++++++++++
	   //連続した線の描画を描く
	   //++++++++++++++++++++++++++++++++++++++++

		//連続した線の座標
		POINT pt_ren[5];
		int POINT_CNT = 5;	//座標の数

		//四角の左上
		pt_ren[0].x = 50;
		pt_ren[0].y = 300;

		//四角の右上
		pt_ren[1].x = 200;
		pt_ren[1].y = 300;

		//四角の右下
		pt_ren[2].x = 200;
		pt_ren[2].y = 400;

		//四角の左下
		pt_ren[3].x = 50;
		pt_ren[3].y = 400;

		//四角の左上
		pt_ren[4].x = 50;
		pt_ren[4].y = 300;

		int sw_ren = 1;

		if (sw_ren == 0)
		{
			//線をどこから描き始めるか設定する
			MoveToEx(hdc, pt_ren[0].x, pt_ren[0].y, NULL);

			//連続した線を描画する
			PolylineTo(
				hdc,			//デバイスコンテキストのハンドル
				pt_ren,			//POINT構造体配列のポインタ
				POINT_CNT);		//描画する座標の数
		}
		else
		{
			//カレントポジションを使用せず、連続した線を一括で描画
			Polyline(
				hdc,			//デバイスコンテキストのハンドル
				pt_ren,			//POINT構造体配列のポインタ
				POINT_CNT);		//描画する座標の数
		}

		//++++++++++++++++++++++++++++++++++++++++
		//連続した線を複数に分けて描く
		//++++++++++++++++++++++++++++++++++++++++

		int LINE_HUKU_CNT = 2;	//線の数

		//連続した線の座標
		DWORD split[2] = {
			3,		//３つでまとめる
			4 };	//４つでまとめる

		POINT pt_huku[7];

		//--------------------
		pt_huku[0].x = 50;
		pt_huku[0].y = 250;

		pt_huku[1].x = 75;
		pt_huku[1].y = 350;

		pt_huku[2].x = 100;
		pt_huku[2].y = 250;
		//--------------------
		pt_huku[3].x = 125;
		pt_huku[3].y = 350;

		pt_huku[4].x = 150;
		pt_huku[4].y = 250;

		pt_huku[5].x = 175;
		pt_huku[5].y = 350;

		pt_huku[6].x = 200;
		pt_huku[6].y = 250;
		//--------------------

		//線をどこから描き始めるか設定する
		MoveToEx(hdc, pt_huku[0].x, pt_huku[0].y, NULL);

		//連続して複数の線を描画する
		PolyPolyline(
			hdc,				//デバイスコンテキストのハンドル
			pt_huku,			//POINT構造体配列のポインタ
			split,				//線をを分ける
			LINE_HUKU_CNT);		//描画する線の数
	}

 ５．図形を描画する関数を追加する
	 //------------------------------------------------
	//図形を描画する関数
	//------------------------------------------------
	void MY_DRAW_GRAPH(HDC hdc)
	{








		//++++++++++++++++++++++++++++++++++++++++
		//四角を描画
		//++++++++++++++++++++++++++++++++++++++++

		//図形の座標を設定
		RECT rect_sq = {
			150,150,	//左上の座標
			350,350		//右下の座標
		};

		//線をどこから描き始めるか設定する
		MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

		//四角を描画
		Rectangle(
			hdc,				//デバイスコンテキストのハンドル
			rect_sq.left,		//四角の左上のX座標
			rect_sq.top,		//四角の左上のY座標
			rect_sq.right,		//四角の右下のX座標
			rect_sq.bottom);	//四角の右下のY座標

		//++++++++++++++++++++++++++++++++++++++++
		//角が丸い四角を描画
		//++++++++++++++++++++++++++++++++++++++++

		//線をどこから描き始めるか設定する
		MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

		//四角を描画
		RoundRect(
			hdc,					//デバイスコンテキストのハンドル
			rect_sq.left + 10,		//四角の左上のX座標
			rect_sq.top + 10,		//四角の左上のY座標
			rect_sq.right - 10,		//四角の右下のX座標
			rect_sq.bottom - 10,	//四角の右下のY座標
			50,						//角の丸みの横幅
			50);					//角の丸みの縦幅

		//++++++++++++++++++++++++++++++++++++++++
		//楕円を描画
		//++++++++++++++++++++++++++++++++++++++++

		//図形の座標を設定
		RECT rect_eli = {
			180,180,	//左上の座標
			320,320		//右下の座標
		};

		//線をどこから描き始めるか設定する
		MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

		//楕円を描画
		Ellipse(
			hdc,				//デバイスコンテキストのハンドル
			rect_eli.left,		//楕円の左上のX座標
			rect_eli.top,		//楕円の左上のY座標
			rect_eli.right,		//楕円の右下のX座標
			rect_eli.bottom);	//楕円の右下のY座標

		//++++++++++++++++++++++++++++++++++++++++
		//弧を描画
		//++++++++++++++++++++++++++++++++++++++++

		//楕円の半径を取得
		int hankei = (rect_eli.right - rect_eli.left) / 2;

		//楕円の中心を取得
		POINT chusin = {
			rect_eli.left + hankei,	// X座標
			rect_eli.top + hankei	// Y座標
		};




		//弧の始点の座標
		POINT pt_ko_start = {
			chusin.x + hankei * cos(MY_PI / 4 * 0),
			chusin.y + hankei * sin(MY_PI / 4 * 0) };

		//弧の終点の座標
		POINT pt_ko_end = {
			chusin.x + hankei * cos(MY_PI / 4 * 2),
			chusin.y + hankei * sin(MY_PI / 4 * 2) };

		//線をどこから描き始めるか設定する
		MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

		//弧を描画
		Arc(
			hdc,
			rect_eli.left + 10,		//円の左上のX座標
			rect_eli.top + 10,		//円の左上のY座標
			rect_eli.right - 10,	//円の右下のX座標
			rect_eli.bottom - 10,	//円の右下のY座標
			pt_ko_start.x,			//弧の始点のX座標
			pt_ko_start.y,			//弧の始点のY座標
			pt_ko_end.x,			//弧の終点のX座標
			pt_ko_end.y);			//弧の終点のY座標

		//弓形を描画
		Chord(
			hdc,
			rect_eli.left + 10,		//円の左上のX座標
			rect_eli.top + 10,		//円の左上のY座標
			rect_eli.right - 10,	//円の右下のX座標
			rect_eli.bottom - 10,	//円の右下のY座標
			pt_ko_start.x,			//弧の始点のX座標
			pt_ko_start.y,			//弧の始点のY座標
			pt_ko_end.x,			//弧の終点のX座標
			pt_ko_end.y);			//弧の終点のY座標

		//扇形を描画
		Pie(
			hdc,
			rect_eli.left + 10,		//円の左上のX座標
			rect_eli.top + 10,		//円の左上のY座標
			rect_eli.right - 10,	//円の右下のX座標
			rect_eli.bottom - 10,	//円の右下のY座標
			pt_ko_start.x,			//弧の始点のX座標
			pt_ko_start.y,			//弧の始点のY座標
			pt_ko_end.x,			//弧の終点のX座標
			pt_ko_end.y);			//弧の終点のY座標
	}
６．【WM_PAINT】メッセージ内へ追加する
	※MY_SetFontDraw(hdc);の下に追加する

	//線を描画
	MY_DRAW_LINE(hdc);

	//図を描画
	MY_DRAW_GRAPH(hdc);

 ☆プログラムが入力できたら、実行させよう！☆
 */










/*
 //+++++++++++++++++++++++++++++++++++++++++++++
 //ヘッダーファイル読み込み
 //+++++++++++++++++++++++++++++++++++++++++++++
#include <windows.h>
 //▼▼▼▼▼１．ヘッダーファイル読み込みに追加する▼▼▼▼▼

#include <math.h>

 //▲▲▲▲▲１．ヘッダーファイル読み込みに追加する▲▲▲▲▲

//+++++++++++++++++++++++++++++++++++++++++++++
//マクロ定義
//+++++++++++++++++++++++++++++++++++++++++++++
//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前
#define MY_WIN_CLASS "MY_WIN_CLASS"

//ウィンドウの場所を大きさを設定
#define WIN_X		100		//横の位置
#define WIN_Y		100		//縦の位置
#define WIN_WIDTH	500		//幅
#define WIN_HEIGHT	500		//高さ

//エラーメッセージ
#define ERR_MSG_TITLE			TEXT("ERROR")
#define ERR_MSG_NO_WIN_CLASS	TEXT("ウィンドウクラスが\
登録できませんでした\nプログラムを終了します")
#define ERR_MSG_NO_WIN_CREATE	TEXT("ウィンドウ\
が作成できませんでした\nプログラムを終了します")

#define ERR_MSG_NO_READ_FONT TEXT("フォントが\
 読み込めませんでした\nプログラムを終了します")

 //ウィンドウのサイズを変更できなくする
 //実は、WS_OVERLAPPEDWINDOWから、WS_THICKFRAME と WS_MAXIMIZEBOXを抜いたもの
#define WS_STATIC_WINDOW	WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//ウィンドウのタイトルをなくす
#define WS_NOT_TITLE WS_POPUP | WS_BORDER

//すでにPCにインストールされているフォント
#define FNT_MS_GOTHIC TEXT("ＭＳ ゴシック")
#define FNT_MS_MINCHO TEXT("ＭＳ 明朝")

//一時的に読み込むフォント
#define FNT_JUD_PASS	TEXT(".\\MY_FONT\\JUDGE2.TTF")		//フォントの場所
#define FNT_JUD_NAME	TEXT("Judge Hard")

#define FNT_TANU_PASS	TEXT(".\\MY_FONT\\TanukiMagic.ttf")	//フォントの場所
#define FNT_TANU_NAME	TEXT("たぬき油性マジック")

//▼▼▼▼▼２．マクロ定義に追加する▼▼▼▼▼

//円周率
#define MY_PI 3.1415926

//▲▲▲▲▲２．マクロ定義に追加する▲▲▲▲▲

//+++++++++++++++++++++++++++++++++++++++++++++
//列挙型
//+++++++++++++++++++++++++++++++++++++++++++++
//ウィンドウのサイズを変更できるか
enum WIN_MODE {
	WIN_RESZ_OK,	//0：ウィンドウサイズの変更ができる
	WIN_RESZ_NG,	//1：ウィンドウサイズの変更ができない
	WIN_NO_TITLE	//2：ウィンドウのタイトルをなくす
};

//+++++++++++++++++++++++++++++++++++++++++++++
//プロトタイプ宣言
//+++++++++++++++++++++++++++++++++++++++++++++
//ウィンドウプロシージャ
LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);

//自分のウィンドウクラスを作成する
WNDCLASS MY_CreateWindowClass(HINSTANCE);

//ウィンドウを生成する
HWND MY_CreateWindow(HINSTANCE, int);

//クライアント領域を設定する
VOID MY_SetClientSize(HWND hWnd);

//フォントを設定する
HFONT MY_CreateFont(HDC, LPCTSTR, int, int, int);

//フォントを設定して描画する
void MY_SetFontDraw(HDC);

//▼▼▼▼▼３．プロトタイプ宣言を追加する▼▼▼▼▼

//線を描画する
void MY_DRAW_LINE(HDC);

//図形を描画する
void MY_DRAW_GRAPH(HDC);

//▲▲▲▲▲３．プロトタイプ宣言を追加する▲▲▲▲▲

//+++++++++++++++++++++++++++++++++++++++++++++
//グローバル変数の宣言と初期化
//+++++++++++++++++++++++++++++++++++++++++++++
//マウスの座標を管理する構造体
POINT pt_Mouse = { 0,0 };

//ウィンドウサイズを管理する構造体
RECT window_Size = { 0, 0, 0, 0 };

//領域を管理する構造体
RECT rect_w;	//ウィンドウ領域を管理
RECT rect_c;	//クライアント領域を管理

//+++++++++++++++++++++++++++++++++++++++++++++
//ウィンドウのモードを設定
//+++++++++++++++++++++++++++++++++++++++++++++
int win_mode = (int)WIN_RESZ_OK;

//+++++++++++++++++++++++++++++++++++++++++++++
//プログラムで最初に実行される関数
//+++++++++++++++++++++++++++++++++++++++++++++
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{

	//個々のウィンドウを識別する値(ウィンドウハンドル)
	HWND hwnd;

	//ウィンドウクラスを管理する構造体
	WNDCLASS winc;

	//メッセージを保存する構造体
	MSG msg;

	//自分のウィンドウクラスを作成する関数
	winc = MY_CreateWindowClass(hInstance);

	//ウィンドウクラスを登録する
	if (!RegisterClass(&winc))
	{
		//メッセージボックスを表示
		MessageBox(NULL, ERR_MSG_NO_WIN_CLASS, ERR_MSG_TITLE, MB_OK);

		//登録ができなかったら、プログラムを終了する
		return 0;
	}

	//ウィンドウを生成する(サイズ変更なし)
	hwnd = MY_CreateWindow(hInstance, win_mode);

	//ウィンドウが生成されなかったとき
	if (hwnd == NULL)
	{
		//メッセージボックスを表示
		MessageBox(NULL, ERR_MSG_NO_WIN_CREATE, ERR_MSG_TITLE, MB_OK);

		//処理を終了させる
		return 0;
	}

	//クライアント領域を再設定する
	MY_SetClientSize(hwnd);

	//ウィンドウを表示
	ShowWindow(hwnd, SW_SHOW);

	//メッセージを受け取り続ける
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);
	}

	return msg.wParam;
}

//+++++++++++++++++++++++++++++++++++++++++++++
//自分のウィンドウクラスを作成する関数
//+++++++++++++++++++++++++++++++++++++++++++++
WNDCLASS MY_CreateWindowClass(HINSTANCE hInstance)
{
	//ウィンドウクラスを作成
	WNDCLASS winc;

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

	//ウィンドウクラスを返す
	return winc;
}

//+++++++++++++++++++++++++++++++++++++++++++++
//ウィンドウを生成する関数
//+++++++++++++++++++++++++++++++++++++++++++++
HWND MY_CreateWindow(HINSTANCE hInstance, int mode)
{
	//個々のウィンドウを識別する値(ウィンドウハンドル)
	HWND hwnd;

	switch (mode)
	{
	case WIN_RESZ_OK:
		//ウィンドウのサイズ変更ができる

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
		break;

	case WIN_RESZ_NG:
		//ウィンドウのサイズ変更ができない

		hwnd = CreateWindow(
			TEXT(MY_WIN_CLASS),
			TEXT("自分で登録したウィンドウクラス"),
			WS_STATIC_WINDOW,
			WIN_X,
			WIN_Y,
			WIN_WIDTH,
			WIN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
		break;

	case WIN_NO_TITLE:
		//ウィンドウのタイトルを表示しない

		hwnd = CreateWindow(
			TEXT(MY_WIN_CLASS),
			TEXT("自分で登録したウィンドウクラス"),
			WS_NOT_TITLE,
			WIN_X,
			WIN_Y,
			WIN_WIDTH,
			WIN_HEIGHT,
			NULL,
			NULL,
			hInstance,
			NULL);
		break;
	}

	//ウィンドウハンドルを返す
	return hwnd;
}

//------------------------------------------------
//クライアント領域の設定
//※クライアント領域は、タイトルやウィンドウの線などで
//  設定したい数値から減った値の大きさで表示されてしまう
//------------------------------------------------
VOID MY_SetClientSize(HWND hWnd)
{
	//領域を管理する構造体
	RECT rect_set;

	//最初のクライアントの領域を設定
	rect_set.top = WIN_Y;
	rect_set.left = WIN_X;
	rect_set.bottom = WIN_HEIGHT;
	rect_set.right = WIN_WIDTH;

	//ウィンドウ領域を取得
	GetWindowRect(hWnd, &rect_w);

	//クライアント領域を取得
	GetClientRect(hWnd, &rect_c);

	//クライアント領域の幅を修正
	//　　　　　　　　((ウインドウの横サイズ)       - (クライアントの横サイズ));
	//ウインドウの横サイズ - クライアントの横サイズ で ウインドウ枠の横幅が求まる
	//求めたウインドウ枠の幅を、元々の幅に加算する
	rect_set.right += ((rect_w.right - rect_w.left) - (rect_c.right - rect_c.left));

	//クライアント領域の高さを修正
	//                 ((ウインドウの縦サイズ)       - (クライアントの縦サイズ));
	//ウインドウの縦サイズ - クライアントの縦サイズ で ウインドウ枠の縦幅が求まる
	//求めたウインドウ枠の高さを、元々の高さに加算する
	rect_set.bottom += ((rect_w.bottom - rect_w.top) - (rect_c.bottom - rect_c.top));

	//クライアント領域の場所とサイズを再設定
	SetWindowPos(
		hWnd,					//ウィンドウハンドル
		HWND_TOP,				//ウィンドウを前の面にする
		rect_set.left,			//ウィンドウのX座標
		rect_set.top,			//ウィンドウのY座標
		rect_set.right,			//ウィンドウの幅
		rect_set.bottom,		//ウィンドウの高さ
		SWP_SHOWWINDOW);		//ウィンドウを表示
}

//------------------------------------------------
//画像を描画する関数
//------------------------------------------------
void MY_DRAW(HDC hdc)
{
	//マウスの座標の文字列を入れる変数
	TCHAR Str_X_Y[64];

	//画面の大きさの文字列を入れる変数
	TCHAR Str_CX_CY[64];

	//TEXTMETRIC：フォントの詳細情報を持つメトリックス構造体
	TEXTMETRIC tm;

	//フォントの詳細情報を取得
	GetTextMetrics(hdc, &tm);

	//文字の描画部分にそのまま上書きする
	//SetBkMode(hdc, TRANSPARENT);			//背景を塗りつぶさない

	//文字を描画部分の背景も書き直す
	SetBkMode(hdc, OPAQUE);					//背景を塗りつぶす

	SetTextColor(hdc, RGB(0, 0, 0));		//文字色を白にする
	SetBkColor(hdc, RGB(255, 255, 255));	//背景色を黒にする

	//マウスの座標を整形
	wsprintf(Str_X_Y, TEXT("マウスの位置(X:%03d,Y:%03d)"), pt_Mouse.x, pt_Mouse.y);

	//マウスの座標を描画
	TextOut(hdc, 100, tm.tmHeight * 0, Str_X_Y, lstrlen(Str_X_Y));

	//画面の大きさを整形
	wsprintf(Str_CX_CY, TEXT("画面の大きさ(X:%03d,Y:%03d)"), window_Size.right, window_Size.bottom);

	//画面の大きさを描画
	TextOut(hdc, 100, tm.tmHeight * 1, Str_CX_CY, lstrlen(Str_CX_CY));
}

//------------------------------------------------
//フォントを設定して文字を描画する
//------------------------------------------------
void MY_SetFontDraw(HDC hdc)
{
	//TEXTMETRIC：フォントの詳細情報を持つメトリックス構造体
	TEXTMETRIC tm_d;

	//表示する文字列
	TCHAR STR1[] = TEXT("こんにちは。");
	TCHAR STR2[] = TEXT("Hello,123*");
	TCHAR STR3[] = TEXT("店長のオススメ！");

	//描画する文字の位置(X座標)
	int Str_X = 0;

	//描画する文字の位置(Y座標)
	int Str_Y = 50;

	//フォントの詳細情報を取得
	GetTextMetrics(hdc, &tm_d);

	//------------------------------------------------
	//PCにインストール済のフォントを使用する
	//------------------------------------------------

	//フォントの情報を管理
	HFONT hfnt_Ins;

	//フォントを作成
	hfnt_Ins = MY_CreateFont(
		hdc,				//デバイスコンテキストのハンドル
		FNT_MS_MINCHO,		//フォントの名前
		32,				//フォントのサイズ
		0,					//描画するときの角度
		SHIFTJIS_CHARSET	//文字コード
	);

	//フォントを設定する
	SelectObject(hdc, hfnt_Ins);

	//文字を表示
	TextOut(hdc, Str_X, Str_Y, STR1, lstrlen(STR1));

	//フォントの詳細情報を取得
	GetTextMetrics(hdc, &tm_d);

	//描画する文字の高さを取得
	Str_Y += tm_d.tmHeight;

	//フォントをデフォルトに戻す
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//不要なフォントを削除
	DeleteObject(hfnt_Ins);

	//------------------------------------------------
	//PCに未インストール済のフォントを使用する(ANSI:英字のみ)
	//------------------------------------------------

	//フォントの情報を管理
	HFONT hfnt_Not_ANSI;

	//フォントを作成
	hfnt_Not_ANSI = MY_CreateFont(hdc, FNT_JUD_NAME, 100, 0, ANSI_CHARSET);

	//フォントを設定する
	SelectObject(hdc, hfnt_Not_ANSI);

	//文字を表示
	TextOut(hdc, Str_X, Str_Y, STR2, lstrlen(STR2));

	//フォントの詳細情報を取得
	GetTextMetrics(hdc, &tm_d);

	//描画する文字の高さを取得
	Str_Y += tm_d.tmHeight;

	//フォントをデフォルトに戻す
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//不要なフォントを削除
	DeleteObject(hfnt_Not_ANSI);

	//------------------------------------------------
	//PCに未インストール済のフォントを使用する(Shift-JIS:日本語)
	//------------------------------------------------

	//フォントの情報を管理
	HFONT hfnt_Not_SJIS;

	//フォントを作成
	hfnt_Not_SJIS = MY_CreateFont(hdc, FNT_TANU_NAME, 32, 0, SHIFTJIS_CHARSET);

	//フォントを設定する
	SelectObject(hdc, hfnt_Not_SJIS);

	//文字を表示
	TextOut(hdc, Str_X, Str_Y, STR3, lstrlen(STR3));

	//フォントの詳細情報を取得
	GetTextMetrics(hdc, &tm_d);

	//描画する文字の高さを取得
	Str_Y += tm_d.tmHeight;

	//フォントをデフォルトに戻す
	SelectObject(hdc, GetStockObject(SYSTEM_FONT));

	//不要なフォントを削除
	DeleteObject(hfnt_Not_SJIS);

	return;
}

//▼▼▼▼▼４．線を描画する関数を追加する▼▼▼▼▼
//------------------------------------------------
//線を描画する関数
//------------------------------------------------
void MY_DRAW_LINE(HDC hdc)
{
	//++++++++++++++++++++++++++++++++++++++++
	//線を描く
	//++++++++++++++++++++++++++++++++++++++++
	
	//XY座標を１つ格納できるPOINT構造体
	POINT pt_line = { 250,250 };

	//線をどこから描き始めるか設定する
	//カレントポジションという
	MoveToEx(
		hdc,				//デバイスコンテキストのハンドル
		pt_line.x,			//描き始めるX座標
		pt_line.y,			//描き始めるY座標
		NULL);				//以前のカレントポジション取得/必要ないならNULL

	//線を描く(縦棒)
	LineTo(
		hdc,				//デバイスコンテキストのハンドル
		pt_line.x,			//描き終わるX座標
		pt_line.y + 200);	//描き終わるY座標

	//線をどこから描き始めるか設定する
	MoveToEx(
		hdc,				//デバイスコンテキストのハンドル
		pt_line.x,			//描き始めるX座標
		pt_line.y,			//描き始めるY座標
		NULL);				//以前のカレントポジション/必要ないならNULL

	//線を描く(横棒)
	LineTo(
		hdc,				//デバイスコンテキストのハンドル
		pt_line.x + 200,	//描き終わるX座標
		pt_line.y);		//描き終わるY座標

	//線をどこから描き始めるか設定する
	MoveToEx(
		hdc,				//デバイスコンテキストのハンドル
		pt_line.x,			//描き始めるX座標
		pt_line.y,			//描き始めるY座標
		NULL);				//以前のカレントポジション/必要ないならNULL

	//線を描く(斜め棒)
	LineTo(
		hdc,				//デバイスコンテキストのハンドル
		pt_line.x + 200,	//描き終わるX座標
		pt_line.y + 200);	//描き終わるY座標

   //++++++++++++++++++++++++++++++++++++++++
   //連続した線の描画を描く
   //++++++++++++++++++++++++++++++++++++++++

	//連続した線の座標
	POINT pt_ren[5];
	int POINT_CNT = 5;	//座標の数

	//四角の左上
	pt_ren[0].x = 50;
	pt_ren[0].y = 300;

	//四角の右上
	pt_ren[1].x = 200;
	pt_ren[1].y = 300;

	//四角の右下
	pt_ren[2].x = 200;
	pt_ren[2].y = 400;

	//四角の左下
	pt_ren[3].x = 50;
	pt_ren[3].y = 400;

	//四角の左上
	pt_ren[4].x = 50;
	pt_ren[4].y = 300;

	int sw_ren = 1;

	if (sw_ren == 0)
	{
		//線をどこから描き始めるか設定する
		MoveToEx(hdc, pt_ren[0].x, pt_ren[0].y, NULL);

		//連続した線を描画する
		PolylineTo(
			hdc,			//デバイスコンテキストのハンドル
			pt_ren,			//POINT構造体配列のポインタ
			POINT_CNT);		//描画する座標の数
	}
	else
	{
		//カレントポジションを使用せず、連続した線を一括で描画
		Polyline(
			hdc,			//デバイスコンテキストのハンドル
			pt_ren,			//POINT構造体配列のポインタ
			POINT_CNT);		//描画する座標の数
	}

	//++++++++++++++++++++++++++++++++++++++++
	//連続した線を複数に分けて描く
	//++++++++++++++++++++++++++++++++++++++++

	int LINE_HUKU_CNT = 2;	//線の数

	//連続した線の座標
	DWORD split[2] = {
		3,	//３つでまとめる
		4 };	//４つでまとめる

	POINT pt_huku[7];

	//--------------------
	pt_huku[0].x = 50;
	pt_huku[0].y = 250;

	pt_huku[1].x = 75;
	pt_huku[1].y = 350;

	pt_huku[2].x = 100;
	pt_huku[2].y = 250;
	//--------------------
	pt_huku[3].x = 125;
	pt_huku[3].y = 350;

	pt_huku[4].x = 150;
	pt_huku[4].y = 250;

	pt_huku[5].x = 175;
	pt_huku[5].y = 350;

	pt_huku[6].x = 200;
	pt_huku[6].y = 250;
	//--------------------

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, pt_huku[0].x, pt_huku[0].y, NULL);

	//連続して複数の線を描画する
	PolyPolyline(
		hdc,				//デバイスコンテキストのハンドル
		pt_huku,			//POINT構造体配列のポインタ
		split,				//線をを分ける
		LINE_HUKU_CNT);		//描画する線の数
	

	int kyori = 100;
	POINT pt_chusin = { 250         ,250 };
	POINT pt_1 = { 250 + kyori ,250 };
	POINT pt_2 = { 250         ,250 - kyori };
	POINT pt_3 = { 250 - kyori ,250 };
	POINT pt_4 = { 250 - kyori ,250 - kyori };

	MoveToEx(hdc, pt_chusin.x, pt_chusin.y, NULL);
	LineTo(hdc, pt_1.x, pt_1.y);

	MoveToEx(hdc, pt_chusin.x, pt_chusin.y, NULL);
	LineTo(hdc, pt_2.x, pt_2.y);

	MoveToEx(hdc, pt_chusin.x, pt_chusin.y, NULL);
	LineTo(hdc, pt_3.x, pt_3.y);

	MoveToEx(hdc, pt_chusin.x, pt_chusin.y, NULL);
	LineTo(hdc, pt_4.x, pt_4.y);


	//座標を90度左回転(90度右回転はπ/2)
	double left90 = -MY_PI / 2;

	POINT pt_naname;
	pt_naname.x = 
		pt_chusin.x + kyori 
		* cos(2 * MY_PI / 6 * 1 + left90);
	
	pt_naname.y = 
		pt_chusin.y + kyori 
		* sin(2 * MY_PI / 6 * 1 + left90);

	MoveToEx(hdc, pt_chusin.x, pt_chusin.y, NULL);
	LineTo(hdc, pt_naname.x, pt_naname.y);


}
//▲▲▲▲▲４．線を描画する関数を追加する▲▲▲▲▲

//▼▼▼▼▼５．図形を描画する関数を追加する▼▼▼▼▼
//------------------------------------------------
//図形を描画する関数
//------------------------------------------------
void MY_DRAW_GRAPH(HDC hdc)
{
	//++++++++++++++++++++++++++++++++++++++++
	//四角を描画
	//++++++++++++++++++++++++++++++++++++++++

	//図形の座標を設定
	RECT rect_sq = {
		150,150,	//左上の座標
		350,350		//右下の座標
	};

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//四角を描画
	Rectangle(
		hdc,				//デバイスコンテキストのハンドル
		rect_sq.left,		//四角の左上のX座標
		rect_sq.top,		//四角の左上のY座標
		rect_sq.right,		//四角の右下のX座標
		rect_sq.bottom);	//四角の右下のY座標

	//++++++++++++++++++++++++++++++++++++++++
	//角が丸い四角を描画
	//++++++++++++++++++++++++++++++++++++++++

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//四角を描画
	RoundRect(
		hdc,					//デバイスコンテキストのハンドル
		rect_sq.left + 10,		//四角の左上のX座標
		rect_sq.top + 10,		//四角の左上のY座標
		rect_sq.right - 10,		//四角の右下のX座標
		rect_sq.bottom - 10,	//四角の右下のY座標
		50,						//角の丸みの横幅
		50);					//角の丸みの縦幅

	//++++++++++++++++++++++++++++++++++++++++
	//楕円を描画
	//++++++++++++++++++++++++++++++++++++++++

	//図形の座標を設定
	RECT rect_eli = {
		180,180,	//左上の座標
		320,320		//右下の座標
	};

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//楕円を描画
	Ellipse(
		hdc,				//デバイスコンテキストのハンドル
		rect_eli.left,		//楕円の左上のX座標
		rect_eli.top,		//楕円の左上のY座標
		rect_eli.right,		//楕円の右下のX座標
		rect_eli.bottom);	//楕円の右下のY座標

	//++++++++++++++++++++++++++++++++++++++++
	//弧を描画
	//++++++++++++++++++++++++++++++++++++++++

	//楕円の半径を取得
	int hankei = (rect_eli.right - rect_eli.left) / 2;

	//楕円の中心を取得
	POINT chusin = {
		rect_eli.left + hankei,	// X座標
		rect_eli.top + hankei	// Y座標
	};

	//弧の始点の座標
	POINT pt_ko_start = {
		chusin.x + hankei * cos(MY_PI / 4 * 0),
		chusin.y + hankei * sin(MY_PI / 4 * 0) };

	//弧の終点の座標
	POINT pt_ko_end = {
		chusin.x + hankei * cos(MY_PI / 4 * 2),
		chusin.y + hankei * sin(MY_PI / 4 * 2) };

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//弧を描画
	Arc(
		hdc,
		rect_eli.left + 10,		//円の左上のX座標
		rect_eli.top + 10,		//円の左上のY座標
		rect_eli.right - 10,	//円の右下のX座標
		rect_eli.bottom - 10,	//円の右下のY座標
		pt_ko_start.x,			//弧の始点のX座標
		pt_ko_start.y,			//弧の始点のY座標
		pt_ko_end.x,			//弧の終点のX座標
		pt_ko_end.y);			//弧の終点のY座標

	//弓形を描画
	Chord(
		hdc,
		rect_eli.left + 10,		//円の左上のX座標
		rect_eli.top + 10,		//円の左上のY座標
		rect_eli.right - 10,	//円の右下のX座標
		rect_eli.bottom - 10,	//円の右下のY座標
		pt_ko_start.x,			//弧の始点のX座標
		pt_ko_start.y,			//弧の始点のY座標
		pt_ko_end.x,			//弧の終点のX座標
		pt_ko_end.y);			//弧の終点のY座標

	//扇形を描画
	Pie(
		hdc,
		rect_eli.left + 10,		//円の左上のX座標
		rect_eli.top + 10,		//円の左上のY座標
		rect_eli.right - 10,	//円の右下のX座標
		rect_eli.bottom - 10,	//円の右下のY座標
		pt_ko_start.x,			//弧の始点のX座標
		pt_ko_start.y,			//弧の始点のY座標
		pt_ko_end.x,			//弧の終点のX座標
		pt_ko_end.y);			//弧の終点のY座標

}
//▲▲▲▲▲５．図形を描画する関数を追加する▲▲▲▲▲

//------------------------------------------------
//フォントを設定する関数
//------------------------------------------------
HFONT MY_CreateFont(HDC hdc, LPCTSTR fontName, int size, int angle, int charset)
{

	HFONT hFont;
	hFont = CreateFont(
		size,					//フォントの高さ / 0ならデフォルト(大きさ)
		0,						//文字幅		 / 0なら自動計算

		angle,					//テキストの角度
							   //水平から反時計回りに 1/10 度単位で角度を指定
							   //   0(  0度) ならば 左から右へ描画
							   // 900( 90度) ならば 下から上へ描画
							   //1800(180度) ならば 右から左へ描画
							   //2700(270度) ならば 上から下へ描画

		0,						//ベースラインとｘ軸との角度
		FW_REGULAR,			//フォントの重さ（太さ）
		FALSE,					//イタリック体
		FALSE,					//アンダーライン
		FALSE,					//打ち消し線

		charset,				//文字セット
							   //ANSI      を使うならば ANSI_CHARSET
							   //Shift-JIS を使うならば SHIFTJIS_CHARSET
							   //デフォルトを使うならば DEFAULT_CHARSET

		OUT_DEFAULT_PRECIS,	//出力精度
		CLIP_DEFAULT_PRECIS,	//クリッピング精度
		PROOF_QUALITY,			//出力品質
		FIXED_PITCH | FF_MODERN,//ピッチとファミリー
		fontName);				//フォントの書体名

	return hFont;
}

//------------------------------------------------
//ウィンドウプロシージャ関数
//------------------------------------------------
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	//HDC：デバイスコンテキストのハンドル
	HDC hdc;

	//PAINTSTRUCT：ウィンドウごとの描画情報を管理する構造体
	PAINTSTRUCT ps;

	switch (msg)
	{

	case WM_CREATE:
		//ウィンドウの生成＆初期化

		//judge hardフォントを一時的に読み込み
		if (AddFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL) == 0)
		{
			//フォントが読み込めなかったとき
			MessageBox(hwnd, ERR_MSG_NO_READ_FONT, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//たぬき油性マジックフォントを一時的に読み込み
		if (AddFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL) == 0)
		{
			//フォントが読み込めなかったとき
			MessageBox(hwnd, ERR_MSG_NO_READ_FONT, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//ウィンドウを生成するときは、0を返す
		return 0;

	case WM_PAINT:
		//ウィンドウ内を再描画するとき

		//デバイスコンテキストのハンドルを取得
		hdc = BeginPaint(hwnd, &ps);

		//現在のデバイスコンテキストを保存する
		SaveDC(hdc);

		//描画
		MY_DRAW(hdc);

		//フォントを設定して描画
		//MY_SetFontDraw(hdc);

		//▼▼▼▼▼６．【WM_PAINT】メッセージ内へ追加する▼▼▼▼▼

		//線を描画
		MY_DRAW_LINE(hdc);

		//図を描画
		//MY_DRAW_GRAPH(hdc);

		//▲▲▲▲▲６．【WM_PAINT】メッセージ内へ追加する▲▲▲▲▲

		//保存したデバイスコンテキスを復元する
		RestoreDC(hdc, -1);

		//デバイスコンテキストのハンドルを開放する
		EndPaint(hwnd, &ps);

		return 0;

	case WM_LBUTTONDOWN:
		//マウスの左ボタンを押しているとき

		//タイトルバーがないとき
		if (win_mode == WIN_NO_TITLE)
		{
			//メッセージが送られる
			PostMessage(
				hwnd,				//ウィンドウハンドル
				WM_NCLBUTTONDOWN,	//非クライアント領域を左クリックする
				HTCAPTION,			//タイトルバーをクリックする
				MAKELPARAM(0, 0));	//マウスの座標：0,0

			return 0;
		}

		//クライアント領域外でもマウスの動きの監視を開始
		SetCapture(hwnd);

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

		//タイトルバーがないとき
		if (win_mode == WIN_NO_TITLE)
		{
			return 0;
		}

		//クライアント領域外でもマウスの動きの監視を終了
		ReleaseCapture();

		//無効リージョンを発生
		InvalidateRect(hwnd, NULL, FALSE);

		//画面を、すぐに再描画する
		UpdateWindow(hwnd);

		break;

	case WM_RBUTTONDOWN:
		//マウスの右ボタンを押したとき

		//タイトルバーがないとき
		if (win_mode == WIN_NO_TITLE)
		{
			//メッセージを送る
			SendMessage(
				hwnd,		//ウィンドウハンドル
				WM_CLOSE,	//送るメッセージ：WM_CLOSE
				0,			//メッセージの情報その１
				0);		//メッセージの情報その２

			return 0;
		}

		break;

	case WM_RBUTTONUP:
		//マウスの右ボタンを上げたとき

		break;

	case WM_MOUSEMOVE:
		//マウスカーソルが移動したとき

		//マウスの座標を取得
		//LPARAM lpには、マウスの座標が入っている
		//その中で、上位16ビットには、y座標が入っている
		//その中で、下位16ビットには、x座標が入っている

		//DWORD型(32ビット)の下位WORD(16ビット)を取り出す
		pt_Mouse.x = LOWORD(lp);
		//DWORD型(32ビット)の上位WORD(16ビット)を取り出す
		pt_Mouse.y = HIWORD(lp);

		//クライアント領域外の対処
		if (pt_Mouse.x < window_Size.left)
			pt_Mouse.x = window_Size.left;

		if (pt_Mouse.x >= window_Size.right)
			pt_Mouse.x = window_Size.right - 1;

		if (pt_Mouse.y < window_Size.top)
			pt_Mouse.y = window_Size.top;

		if (pt_Mouse.y >= window_Size.bottom)
			pt_Mouse.y = window_Size.bottom - 1;

		//無効リージョンを発生
		//OS(Windows)が、WM_PAINTを直接ウィンドウプロシージャに送る
		//無効リージョン(領域)は再描画される
		InvalidateRect(hwnd, NULL, FALSE);

		//画面を、すぐに再描画する
		//WM_PAINTを直接ウィンドウプロシージャに送る関数
		UpdateWindow(hwnd);

		break;
	case WM_SIZE:
		//画面のサイズが変わったとき

		//ウィンドウのサイズを取得
		//LPARAM lpには、ウインドウのサイズが入っている
		//その中で、上位16ビットには、高さのサイズが入っている
		//その中で、下位16ビットには、幅のサイズが入っている

		//DWORD型(32ビット)の上位WORD(16ビット)を取り出す
		window_Size.bottom = HIWORD(lp);
		//DWORD型(32ビット)の下位WORD(16ビット)を取り出す
		window_Size.right = LOWORD(lp);

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

		break;

	case WM_CLOSE:
		//閉じるボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("ウィンドウを終了させます"),
			TEXT("CLOSE"),
			MB_OK);

		break;

	case WM_DESTROY:
		//ウィンドウが破棄された(なくなった)とき

		//一時的に読み込んだ judge hardフォントを削除
		RemoveFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL);

		//一時的に読み込んだ たぬき油性マジックフォントを削除
		RemoveFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL);

		//メッセージキューに WM_QUIT を送る
		PostQuitMessage(0);
		return 0;
	}

	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, msg, wp, lp);
}
*/