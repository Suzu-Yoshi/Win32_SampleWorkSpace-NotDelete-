/*注意：プリントの\(バックスラッシュ)は、半角の￥マークです				*/
/*記入例は右の場所を参考→学生共有サーバ\担当\41.G1_Win32API			*/
/*Ctrl + M の後、Ctrl + L で、プログラム全体の折りたたみ/解除ができます */
/*Ctrl + M の後、Ctrl + M で、ブロックの折りたたみ/解除ができます		*/
/*プログラムが入力できたら、関数調べや、プログラムの改造をしてみよう    */

/*
◎ヘッダーファイル読み込みに追加
	・先頭に追加

	#include <stdio.h>
	#include <locale.h>

◎マクロ定義の修正
	・コメントアウト

	//#define TIMER_ID_1	1		//タイマー１
	//#define TIMER_ID_2	2		//タイマー２

◎マクロ定義に追加
	・#define TIMER_ID_2	2 の下に追加する

	#define TIMER_ID_FPS	100	//FPSタイマー

	#define DISP_FPS		60	//画面のFPS
	#define AVE_FPS			60	//平均を取るサンプル数

◎プロトタイプ宣言に追加
	・VOID MY_DRAW_BITMAP(HDC); の下に追加する

	//画面更新の時刻を取得する関数
	BOOL MY_FPS_UPDATE(VOID);

	//指定したFPSになるように待つ関数
	VOID MY_FPS_WAIT(VOID);

◎グローバル変数の修正
	・コメントアウト

	////unsigen：符号なし
	////メインループでカウントをする変数
	//unsigned int mainLoop_cnt = 0;
	//
	////タイマー１でカウントする変数
	//unsigned int timer_1_cnt = 0;
	//
	////タイマー２でカウントする変数
	//unsigned int timer_2_cnt = 0;

◎グローバル変数に追加
	・unsigned int timer_2_cnt = 0; の下に追加する

	//FPSのタイマーでカウントする変数
	unsigned int timer_fps_cnt = 0;

	float		fps;		//FPS
	DWORD		fps_sta_tm;	//0フレーム目の開始時刻
	DWORD		fps_end_tm;	//設定したフレームの終了時刻
	DWORD		fps_count;	//フレームのカウント

	
	
◎WinMain関数の修正
	・コメントアウト解除
	//メッセージを受け取り続ける
	while (GetMessage(&msg, NULL, 0, 0))
	{
	DispatchMessage(&msg);
	}

	・コメントアウト
	//メッセージを受け取り続ける
	while (GetMessage(&msg, NULL, 0, 0))
	{
	DispatchMessage(&msg);
	}
	の【下 の while文】をコメントアウト※プログラム参考例を要参照


◎関数の追加
	・WinMain関数の下の任意の場所に追加
	//########## 画面更新の時刻を取得する関数 ##########
	BOOL MY_FPS_UPDATE(VOID)
	{
		//1フレーム目なら時刻を記憶
		if (fps_count == 0)
		{
			//GetTickCount：
			//Windowsが起動してから現在までの時刻を
			//ミリ秒で取得
			fps_sta_tm = GetTickCount();
		}

		//60フレーム目なら平均を計算する
		if (fps_count == AVE_FPS)
		{
			//現在の時刻をミリ秒で取得
			fps_end_tm = GetTickCount();

			//.0f→float型で計算
			//平均的なFPS値を計算
			fps = 1000.0f / ((fps_end_tm - fps_sta_tm) / (float)AVE_FPS);

			fps_sta_tm = fps_end_tm;
			fps_count = 0;
		}

		fps_count++;

		return true;
	}

	//########## 指定したFPSになるように待つ関数 ##########
	VOID MY_FPS_WAIT(VOID)
	{
		//現在の時刻をミリ秒で取得
		DWORD now_tm = GetTickCount();

		//1フレーム目から実際にかかった時間を計算
		DWORD keika_tm = now_tm - fps_sta_tm;

		//待つべき時間 = かかるべき時間 - 実際にかかった時間;
		DWORD wait_tm = (fps_count * 1000 / DISP_FPS) - (keika_tm);

		//待つべき時間があった場合
		if (wait_tm > 0 && wait_tm < 2000)
		{
			//ミリ秒分、処理を中断する
			Sleep(wait_tm);
		}
	}

◎MY_DRAWを修正
	・コメントアウト
	////+++++ メインループでカウント ++++++++++++++++++++
	//TCHAR Str_mainLoop_Cnt[64];
	//wsprintf(Str_mainLoop_Cnt, TEXT("メインループのカウント：%06d"), mainLoop_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 2, Str_mainLoop_Cnt, lstrlen(Str_mainLoop_Cnt));

	////+++++ タイマー１でカウント ++++++++++++++++++++
	//TCHAR Str_Timer_1_Cnt[64];
	//wsprintf(Str_Timer_1_Cnt, TEXT("タイマー１のカウント：%06d"), timer_1_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 3, Str_Timer_1_Cnt, lstrlen(Str_Timer_1_Cnt));

	////+++++ タイマー２でカウント ++++++++++++++++++++
	//TCHAR Str_Timer_2_Cnt[64];
	//wsprintf(Str_Timer_2_Cnt, TEXT("タイマー２のカウント：%06d"), timer_2_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 4, Str_Timer_2_Cnt, lstrlen(Str_Timer_2_Cnt));
	
◎MY_DRAWに追加
	・タイマー２でカウントの TextOut() の下に追加
	//+++++ FPSを表示 ++++++++++++++++++++

	//FPS値を整形するための変数
	CHAR Str_fps_C[64];
	size_t wLen = 0;
	errno_t err = 0;

	//FPS値を整形
	sprintf(Str_fps_C, "FPS：%03.1lf", fps);

	//FPS値を表示するための変数
	TCHAR Str_fps_W[64];

	//ロケール指定
	setlocale(LC_ALL, "japanese");

	//文字列をマルチバイト文字からワイド文字に変換
	err = mbstowcs_s(
		&wLen,				//変換された文字数
		Str_fps_W,			//変換されたワイド文字
		strlen(Str_fps_C),	//変換する文字数
		Str_fps_C,			//変換するマルチバイト文字
		_TRUNCATE			//バッファに収まるだけの文字列まで変換
	);

	TextOut(hdc, 100, tm.tmHeight * 2, Str_fps_W, lstrlen(Str_fps_W));

	
	
	
	
	
	
	
	
◎WM_CREATEの修正

	・コメントアウト
	////タイマーを分解能(10ミリ秒)でセット(開始)
	//SetTimer(
	//	hwnd,		//関連付けるウィンドウハンドル
	//	TIMER_ID_1,	//タイマーのID
	//	10,			//タイムアウト値(ミリ秒)
	//	NULL);		//TIMERPROC型関数へのポインタ/なし はNULL

	//				//タイマーを１秒でセット(開始)
	//SetTimer(hwnd, TIMER_ID_2, 1000, NULL);

◎WM_CREATEの追加

	・SetTimer(hwnd, TIMER_ID_2, 1000, NULL); の下に追加
	//タイマーを10ミリ間隔にセット(開始)
	SetTimer(hwnd, TIMER_ID_FPS, 10, NULL);

◎WM_TIMERの修正
	・コメントアウト
	//	switch (wp)
	//	{
	//	case TIMER_ID_1:
	//		timer_1_cnt++;
	//		break;
	//	case TIMER_ID_2:
	//		timer_2_cnt++;
	//		break;
	//	}

◎WM_TIMERの追加
	・switch (wp)文 の下に追加
	switch (wp)
	{
		case TIMER_ID_FPS:

		//画面更新の時刻を取得する
		MY_FPS_UPDATE();

		//無効リージョンを発生
		//WM_PAINTを、一定時間で呼び出し
		InvalidateRect(hwnd, NULL, FALSE);

		//画面を、すぐに再描画する
		UpdateWindow(hwnd);

		//指定したFPSになるように待つ
		MY_FPS_WAIT();

		break;
	}

◎WM_DESTROYの修正
	・コメントアウト

	////タイマー１を削除(終了)
	//KillTimer(hwnd, TIMER_ID_2);

	////タイマー２を削除(終了)
	//KillTimer(hwnd, TIMER_ID_1);

◎WM_DESTROYの追加
	・KillTimer(hwnd, TIMER_ID_1); の下に追加

	//FPSタイマーを削除(終了)
	KillTimer(hwnd, TIMER_ID_FPS);

*/
























































/*
//########## ヘッダーファイル読み込み ##########

//▼▼▼▼▼ ヘッダーファイル読み込みに追加 ▼▼▼▼▼

#include <stdio.h>
#include <locale.h>
#include <windows.h>
#include <math.h>
#include <wingdi.h>
#pragma comment (lib, "msimg32.lib")

//########## マクロ定義 ##########

//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前
#define MY_WIN_CLASS "MY_WIN_CLASS"

//ウィンドウの場所を大きさを設定
#define WIN_X		100		//横の位置
#define WIN_Y		100		//縦の位置
#define WIN_WIDTH	500		//幅
#define WIN_HEIGHT	500		//高さ

//エラーメッセージ
#define ERR_MSG_TITLE			TEXT("ERROR")

//\はエディタ上の改行を行いたいときに記述する
#define ERR_MSG_NO_WIN_CLASS	TEXT("ウィンドウクラスが\
登録できませんでした\nプログラムを終了します")

#define ERR_MSG_NO_WIN_CREATE	TEXT("ウィンドウ\
が作成できませんでした\nプログラムを終了します")

#define ERR_MSG_NO_READ_FONT	TEXT("フォントが\
読み込めませんでした\nプログラムを終了します")

//ウィンドウのサイズを変更できなくする
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

//円周率
#define MY_PI 3.1415926

//頂点の最大数
#define CHOTEN_MAX	30

//ビットマップ読み込みエラー
#define ERR_MSG_NO_READ_BMP	TEXT("ビットマップが\
	 読み込めませんでした\nプログラムを終了します")

//ドラゴンのビットマップの場所
//#define BMP_DRA_PASS		TEXT(".\\MY_BITMAP\\mon23\\mon_255.bmp")

//ドラゴンのビットマップの場所（アルファチャネル付き）
#define BMP_DRA_PASS		TEXT(".\\MY_BITMAP\\mon23\\mon_255_alpha.bmp")

//ドラゴンの透過処理
#define BMP_DRA_WH_PASS	TEXT(".\\MY_BITMAP\\mon23\\mon_255_white.bmp")	//ドラゴンのビットマップ(背景白)の場所
#define BMP_DRA_MS_PASS	TEXT(".\\MY_BITMAP\\mon23\\mon_255_bw.bmp")		//ドラゴンのマスクの場所

//▼▼▼▼▼ マクロ定義の修正 ▼▼▼▼▼

////コメントアウト
//#define TIMER_ID_1	1		//タイマー１
//#define TIMER_ID_2	2		//タイマー２

//▲▲▲▲▲ マクロ定義の修正 ▲▲▲▲▲

//▼▼▼▼▼ マクロ定義に追加 ▼▼▼▼▼

#define TIMER_ID_FPS	100	//FPSタイマー

#define DISP_FPS		60	//画面のFPS
#define AVE_FPS			60	//平均を取るサンプル数

//▲▲▲▲▲ マクロ定義に追加 ▲▲▲▲▲

//########## 列挙型 ##########

//ウィンドウのサイズ変更モード
enum WIN_MODE {
	WIN_RESZ_OK,	//0：ウィンドウサイズの変更ができる
	WIN_RESZ_NG,	//1：ウィンドウサイズの変更ができない
	WIN_NO_TITLE	//2：ウィンドウのタイトルをなくす
};

//########## 構造体 ##########
struct MY_STRUCT_BITMAP {
	LPCTSTR filepass;	//ビットマップのファイルパスと名前
	HBITMAP hbmp;		//ビットマップのハンドル
	HDC mhdc;			//メモリデバイスコンテキストを作成
	BITMAP bmp;			//ビットマップ構造体
	int x;				//ビットマップの表示位置(X座標)
	int y;				//ビットマップの表示位置(Y座標)
	int width;			//ビットマップの幅を取得
	int height;			//ビットマップの高さを取得
};

//########## 名前の再定義 ##########

typedef MY_STRUCT_BITMAP	MY_BMP;

//########## プロトタイプ宣言 ##########

//ウィンドウプロシージャ
LRESULT CALLBACK MY_WndProc(HWND, UINT, WPARAM, LPARAM);

//自分のウィンドウクラスを作成する
WNDCLASS MY_CreateWindowClass(HINSTANCE);

//ウィンドウを生成する
HWND MY_CreateWindow(HINSTANCE, int);

//クライアント領域を設定する
VOID MY_SetClientSize(HWND);

//フォントを設定する
HFONT MY_CreateFont(HDC, LPCTSTR, int, int, int);

//フォントを設定して描画する
VOID MY_SetFontDraw(HDC);

//線を描画する
VOID MY_DRAW_LINE(HDC);

//図形を描画する
VOID MY_DRAW_GRAPH(HDC);

//ペンを使用して描画する関数
VOID MY_DRAW_PEN(HDC);

//ブラシを使用して描画する関数
VOID MY_DRAW_BRUSH(HDC);

//多角形を塗りつぶして描画する
VOID MY_DRAW_POLYGON(HDC);

//複数の多角形を塗りつぶして描画
VOID MY_DRAW_POLYPOLYGON(HDC);

//六角形を塗りつぶして描画する
VOID MY_DRAW_PENTAGON(HDC);

//パックマンを塗りつぶしで描画する
VOID MY_DRAW_PACMAN(HDC);

//モンスターボールを塗りつぶしで描画する
VOID MY_DRAW_MONBALL(HDC);

//ダブルバッファリングの設定をする
VOID MY_SetDoubleBufferring(HWND);

//ビットマップを描画する関数
VOID MY_DRAW_BITMAP(HDC);

//▼▼▼▼▼ プロトタイプ宣言に追加 ▼▼▼▼▼

//画面更新の時刻を取得する関数
BOOL MY_FPS_UPDATE(VOID);

//指定したFPSになるように待つ関数
VOID MY_FPS_WAIT(VOID);

//▲▲▲▲▲ プロトタイプ宣言に追加 ▲▲▲▲▲

//########## グローバル変数の宣言と初期化 ##########

//マウスの座標を管理する構造体
POINT pt_Mouse = { 0,0 };

//ウィンドウサイズを管理する構造体
RECT window_Size = { 0, 0, 0, 0 };

//領域を管理する構造体
RECT rect_w;	//ウィンドウ領域を管理
RECT rect_c;	//クライアント領域を管理

				//ウィンドウのモードを設定
int win_mode = (int)WIN_RESZ_OK;

//ダブルバッファリング用
HBITMAP hbmp_double;
HDC     hdc_double;

//自分で作成したビットマップ構造体
MY_BMP bmp_dragon;
MY_BMP bmp_dragon_white;
MY_BMP bmp_dragon_mask;

//▼▼▼▼▼ グローバル変数の修正 ▼▼▼▼▼
//コメントアウト
////unsigen：符号なし
////メインループでカウントをする変数
//unsigned int mainLoop_cnt = 0;
//
////タイマー１でカウントする変数
//unsigned int timer_1_cnt = 0;
//
////タイマー２でカウントする変数
//unsigned int timer_2_cnt = 0;

//▲▲▲▲▲ グローバル変数の修正 ▲▲▲▲▲

//▼▼▼▼▼ グローバル変数に追加 ▼▼▼▼▼

//FPSのタイマーでカウントする変数
unsigned int timer_fps_cnt = 0;	

float		fps;		//FPS
DWORD		fps_sta_tm;	//0フレーム目の開始時刻
DWORD		fps_end_tm;	//設定したフレームの終了時刻
DWORD		fps_count;	//フレームのカウント

//▲▲▲▲▲ グローバル変数に追加 ▲▲▲▲▲

//########## プログラムで最初に実行される関数 ##########
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

	//ダブルバッファリングの設定をする
	MY_SetDoubleBufferring(hwnd);

	//ウィンドウを表示
	ShowWindow(hwnd, SW_SHOW);


	//▼▼▼▼▼ WinMainの修正 ▼▼▼▼▼
	//コメントアウト解除

	//メッセージを受け取り続ける
	while (GetMessage(&msg, NULL, 0, 0))
	{
		DispatchMessage(&msg);

	}
	//▲▲▲▲▲ WinMainの修正 ▲▲▲▲▲


	//▼▼▼▼▼ WinMainの修正 ▼▼▼▼▼
	////コメントアウト
	//while (TRUE)
	//{
	//	//デッドタイムを使う
	//	//デッドタイム：ウィンドウがメッセージ処理をしていない時間のこと
	//	//「アイドル状態」「遊休時間」などの表現方法もある
	//	//→ユーザからキーボードやマウスなどの入力待ちなどで、
	//	//  CPUが処理をしていない状態

	//	//デッドタイムか調べる(0以外→ﾒｯｾｰｼﾞ取得 / 0→ﾃﾞｯﾄﾞﾀｲﾑ)
	//	BOOL PeekRet = PeekMessage(
	//		&msg,		//MSG構造体のポインタ
	//		NULL,		//ﾒｯｾｰｼﾞ取得ｳｨﾝﾄﾞｳのハンドル/全部ならNULL
	//		0,			//メッセージの最小値 / ない場合は0
	//		0,			//メッセージの最大値 / ない場合は0
	//		PM_REMOVE	//メッセージキューからメッセージを削除
	//	);

	//	//デッドタイムのとき
	//	if (PeekRet == TRUE)
	//	{
	//		//メッセージがWM_QUITならループを抜ける
	//		if (msg.message == WM_QUIT)
	//		{
	//			break;
	//		}

	//		//他のメッセージの処理をする
	//		DispatchMessage(&msg);
	//	}

	//	//デッドタイムのとき
	//	if (PeekRet == FALSE)
	//	{
	//		//unsigned intの最大値より小さい場合
	//		if (mainLoop_cnt < UINT_MAX)
	//		{
	//			mainLoop_cnt++;

	//			//無効リージョンを発生
	//			InvalidateRect(hwnd, NULL, FALSE);

	//			//画面を、すぐに再描画する
	//			UpdateWindow(hwnd);
	//		}
	//	}
	//}
	//▲▲▲▲▲ WinMainの修正 ▲▲▲▲▲

	return msg.wParam;
}

//▼▼▼▼▼ 関数を追加 ▼▼▼▼▼

//########## 画面更新の時刻を取得する関数 ##########
BOOL MY_FPS_UPDATE(VOID)
{
	//1フレーム目なら時刻を記憶
	if (fps_count == 0)
	{
		//GetTickCount：
		//Windowsが起動してから現在までの時刻を
		//ミリ秒で取得
		fps_sta_tm = GetTickCount();
	}

	//60フレーム目なら平均を計算する
	if (fps_count == AVE_FPS)
	{
		//現在の時刻をミリ秒で取得
		fps_end_tm = GetTickCount();

		//.0f→float型で計算
		//平均的なFPS値を計算
		fps = 1000.0f / ((fps_end_tm - fps_sta_tm) / (float)AVE_FPS);
		
		fps_sta_tm = fps_end_tm;
		fps_count = 0;

	}

	fps_count++;

	return true;
}

//########## 指定したFPSになるように待つ関数 ##########
VOID MY_FPS_WAIT(VOID)
{
	//現在の時刻をミリ秒で取得
	DWORD now_tm = GetTickCount();

	//1フレーム目から実際にかかった時間を計算
	DWORD keika_tm = now_tm - fps_sta_tm;
	
	//待つべき時間 = かかるべき時間 - 実際にかかった時間;
	DWORD wait_tm = (fps_count * 1000 / DISP_FPS) - (keika_tm);

	//待つべき時間があった場合
	if (wait_tm > 0 && wait_tm < 2000)
	{
		//ミリ秒分、処理を中断する
		Sleep(wait_tm);
	}
}

//▲▲▲▲▲ 関数を追加 ▲▲▲▲▲

//########## ダブルバッファリングの設定をする関数 ##########
VOID MY_SetDoubleBufferring(HWND hWnd)
{

	//ダブルバッファリングとは？
	//現在の描画方法は、一旦、画面を書き換えるため、画面がちらついていた
	//描画処理を直接表示するのではなく、メモリの中に描画し
	//最後にメモリの中にあるものを表示することで、ちらつきをなくす
	//これを、「ダブルバッファリング」という

	// ウインドウのデバイスコンテキストのハンドルを取得
	HDC hdc = GetDC(hWnd);

	//メモリの中に画像を作成
	hbmp_double = CreateCompatibleBitmap(hdc, rect_c.right, rect_c.bottom);

	//メモリの中にデバイスコンテキストのハンドルを作成
	hdc_double = CreateCompatibleDC(hdc);

	//デバイスコンテキストに画像を設定
	SelectObject(hdc_double, hbmp_double);

}

//########## 自分のウィンドウクラスを作成する関数 ##########
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

//########## ウィンドウを生成する関数 ##########
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

//########## クライアント領域の設定をする関数 ##########
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

								//サイズを同じにする
	rect_c.bottom = rect_set.bottom;
	rect_c.right = rect_set.right;

}

//########## 画像を描画する関数 ##########
VOID MY_DRAW(HDC hdc)
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

	//▼▼▼▼▼ MY_DRAWを修正 ▼▼▼▼▼

	////+++++ メインループでカウント ++++++++++++++++++++
	//TCHAR Str_mainLoop_Cnt[64];
	//wsprintf(Str_mainLoop_Cnt, TEXT("メインループのカウント：%06d"), mainLoop_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 2, Str_mainLoop_Cnt, lstrlen(Str_mainLoop_Cnt));

	////+++++ タイマー１でカウント ++++++++++++++++++++
	//TCHAR Str_Timer_1_Cnt[64];
	//wsprintf(Str_Timer_1_Cnt, TEXT("タイマー１のカウント：%06d"), timer_1_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 3, Str_Timer_1_Cnt, lstrlen(Str_Timer_1_Cnt));

	////+++++ タイマー２でカウント ++++++++++++++++++++
	//TCHAR Str_Timer_2_Cnt[64];
	//wsprintf(Str_Timer_2_Cnt, TEXT("タイマー２のカウント：%06d"), timer_2_cnt);
	//TextOut(hdc, 100, tm.tmHeight * 4, Str_Timer_2_Cnt, lstrlen(Str_Timer_2_Cnt));
	//▲▲▲▲▲ MY_DRAWを修正 ▲▲▲▲▲

	//▼▼▼▼▼ MY_DRAWを追加 ▼▼▼▼▼
	//+++++ FPSを表示 ++++++++++++++++++++
	
	//FPS値を整形するための変数
	CHAR Str_fps_C[64];
	size_t wLen = 0;
	errno_t err = 0;

	//FPS値を整形
	sprintf(Str_fps_C, "FPS：%03.1lf", fps);

	//FPS値を表示するための変数
	TCHAR Str_fps_W[64];

	//ロケール指定
	setlocale(LC_ALL, "japanese");

	//文字列をマルチバイト文字からワイド文字に変換
	err = mbstowcs_s(
		&wLen,				//変換された文字数
		Str_fps_W,			//変換されたワイド文字
		strlen(Str_fps_C),	//変換する文字数
		Str_fps_C,			//変換するマルチバイト文字
		_TRUNCATE			//バッファに収まるだけの文字列まで変換
	);

	TextOut(hdc, 100, tm.tmHeight * 2, Str_fps_W, lstrlen(Str_fps_W));

	//▲▲▲▲▲ MY_DRAWを追加 ▲▲▲▲▲
}

//########## フォントを設定して文字を描画する ##########
VOID MY_SetFontDraw(HDC hdc)
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

//########## フォントを設定する関数 ##########
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
		FW_REGULAR,				//フォントの重さ（太さ）
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

//########## 線を描画する関数 ##########
VOID MY_DRAW_LINE(HDC hdc)
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
}

//########## 図形を描画する関数 ##########
VOID MY_DRAW_GRAPH(HDC hdc)
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

//########## ペンを使用して描画する関数 ##########
VOID MY_DRAW_PEN(HDC hdc)
{
	//ペン：線を引く色、太さなどを設定
	HPEN hpen;

	//ペンを作成
	hpen = CreatePen(
		PS_SOLID,			//ペンのタイプ
		5,					//ペンの太さ
		RGB(255, 0, 0));	//ペンの色

							//ペンのタイプ
							//PS_SOLID		実線のペン
							//PS_DASH		破線のペン
							//PS_DOT		点線のペン
							//PS_DASHDOT	一点鎖線のペン
							//PS_DASHDOTDOT	二点鎖線のペン

							//ペンを設定
	SelectObject(hdc, hpen);

	//図形の座標を設定
	RECT rect_sq = {
		50,50,		//左上の座標
		100,100		//右下の座標
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

							//ペンをデフォルトに戻す
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//ペンを削除
	DeleteObject(hpen);
}

//########## ブラシを使用して描画する関数 ##########
VOID MY_DRAW_BRUSH(HDC hdc)
{
	//++++++++++++++++++++++++++++++++++++++++
	//通常の塗りつぶし
	//++++++++++++++++++++++++++++++++++++++++

	//ブラシ：塗りつぶす色、模様などを設定
	HBRUSH hbrush;

	//ブラシを作成
	hbrush = CreateSolidBrush(
		RGB(255, 0, 0));//ブラシの色

						//ブラシを設定
	SelectObject(hdc, hbrush);

	//図形の座標を設定
	RECT rect_sq = {
		150,50,		//左上の座標
		200,100		//右下の座標
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

							//ブラシをデフォルトに戻す
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//ブラシを削除
	DeleteObject(hbrush);

	//++++++++++++++++++++++++++++++++++++++++
	//模様で塗りつぶし
	//++++++++++++++++++++++++++++++++++++++++

	//ブラシ：塗りつぶす色、模様などを設定
	HBRUSH hbrush_2;

	//ブラシを作成
	hbrush_2 = CreateHatchBrush(
		HS_CROSS,			//ブラシの模様
		RGB(255, 0, 0));	//ブラシの色

							//ブラシの模様
							//HS_BDIAGONAL	45 度の右下がりのハッチ
							//HS_CROSS		水平と垂直のクロスハッチ
							//HS_DIAGCROSS	45 度のクロスハッチ
							//HS_FDIAGONAL	45 度の右上がりのハッチ
							//HS_HORIZONTAL	水平ハッチ
							//HS_VERTICAL	垂直ハッチ

							//ブラシを設定
	SelectObject(hdc, hbrush_2);

	//図形の座標を設定
	RECT rect_sq_2 = {
		250,50,		//左上の座標
		300,100		//右下の座標
	};

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_sq.left, rect_sq.top, NULL);

	//四角を描画
	Rectangle(
		hdc,				//デバイスコンテキストのハンドル
		rect_sq_2.left,		//四角の左上のX座標
		rect_sq_2.top,		//四角の左上のY座標
		rect_sq_2.right,		//四角の右下のX座標
		rect_sq_2.bottom);	//四角の右下のY座標

							//ブラシをデフォルトに戻す
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//ブラシを削除
	DeleteObject(hbrush_2);

}

//########## 多角形の塗りつぶして描画する関数 ##########
VOID MY_DRAW_POLYGON(HDC hdc)
{

	//ペン：線を引く色、太さなどを設定
	HPEN hpen;

	//ペンを作成
	hpen = CreatePen(
		PS_SOLID,			//ペンのタイプ
		1,					//ペンの太さ
		RGB(0, 0, 0));		//ペンの色

							//ペンを設定
	SelectObject(hdc, hpen);

	//ブラシ：塗りつぶす色、模様などを設定
	HBRUSH hbrush;

	//ブラシを作成
	hbrush = CreateSolidBrush(
		RGB(255, 0, 0));//ブラシの色

						//ブラシを設定
	SelectObject(hdc, hbrush);

	//++++++++++++++++++++++++++++++++++++++++
	//五角形を描画
	//++++++++++++++++++++++++++++++++++++++++

	//図形の中心を設定
	POINT chusin;
	chusin.x = 200;
	chusin.y = 200;

	//図形の大きさを設定
	int scale = 100;

	//多角形の頂点の数
	int kaku_cnt = 5;

	//座標を設定
	POINT rect_po[CHOTEN_MAX];

	//座標を90度左回転(90度右回転はπ/2)
	double left90 = -MY_PI / 2;

	//座標を計算
	int i;
	for (i = 0; i < kaku_cnt; i++)
	{
		//Xの座標=中心のX座標+大きさ*弧度(360度/図形の角の数*右回りで何番目の角+90度左回転)
		rect_po[i].x = chusin.x + scale * cos(2 * MY_PI / kaku_cnt * i + left90);
		//Yの座標=中心のY座標+大きさ*弧度(360度/図形の角の数*右回りで何番目の角+90度左回転)
		rect_po[i].y = chusin.y + scale * sin(2 * MY_PI / kaku_cnt * i + left90);
	}
	//最後の座標は一番最初の座標
	rect_po[i].x = rect_po[0].x;
	rect_po[i].y = rect_po[0].y;

	//多角形の中をすべて塗りつぶす
	SetPolyFillMode(hdc, WINDING);

	//多角形の塗りつぶし
	Polygon(
		hdc,		//デバイスコンテキストのハンドル
		rect_po,	//多角形の座標
		kaku_cnt);	//多角形の頂点の数

					//++++++++++++++++++++++++++++++++++++++++
					//星を描画
					//++++++++++++++++++++++++++++++++++++++++

					//中心を設定
	chusin.x = 400;
	chusin.y = 200;

	//座標を計算
	for (i = 0; i < kaku_cnt; i++)
	{
		//Xの座標=中心のX座標+大きさ*弧度(360度/図形の角の数*右回りで何番目の角+90度左回転)
		rect_po[i].x = chusin.x + scale * cos(2 * MY_PI / kaku_cnt * i + left90);
		//Yの座標=中心のY座標+大きさ*弧度(360度/図形の角の数*右回りで何番目の角+90度左回転)
		rect_po[i].y = chusin.y + scale * sin(2 * MY_PI / kaku_cnt * i + left90);
	}
	//最後の座標は一番最初の座標
	rect_po[i].x = rect_po[0].x;
	rect_po[i].y = rect_po[0].y;

	//星の座標
	POINT rect_star[CHOTEN_MAX];

	//星を書くときの書き順を参考にする
	rect_star[0].x = rect_po[0].x;
	rect_star[0].y = rect_po[0].y;

	rect_star[1].x = rect_po[2].x;
	rect_star[1].y = rect_po[2].y;

	rect_star[2].x = rect_po[4].x;
	rect_star[2].y = rect_po[4].y;

	rect_star[3].x = rect_po[1].x;
	rect_star[3].y = rect_po[1].y;

	rect_star[4].x = rect_po[3].x;
	rect_star[4].y = rect_po[3].y;

	rect_star[5].x = rect_po[0].x;
	rect_star[5].y = rect_po[0].y;

	//多角形の中で線が交差しているところは塗りつぶさない
	SetPolyFillMode(hdc, ALTERNATE);

	//多角形の塗りつぶし
	Polygon(
		hdc,		//デバイスコンテキストのハンドル
		rect_star,	//多角形の座標
		kaku_cnt);	//多角形の頂点の数

					//ブラシをデフォルトに戻す
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//ブラシを削除
	DeleteObject(hbrush);

	//ペンをデフォルトに戻す
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//ペンを削除
	DeleteObject(hpen);
}

//########## 複数の多角形の塗りつぶして描画する関数 ##########
VOID MY_DRAW_POLYPOLYGON(HDC hdc)
{
	//ペン：線を引く色、太さなどを設定
	HPEN hpen;

	//ペンを作成
	hpen = CreatePen(
		PS_SOLID,			//ペンのタイプ
		1,					//ペンの太さ
		RGB(176, 224, 230));	//ペンの色

								//ペンを設定
	SelectObject(hdc, hpen);

	//ブラシ：塗りつぶす色、模様などを設定
	HBRUSH hbrush;

	//ブラシを作成
	hbrush = CreateSolidBrush(
		RGB(176, 224, 230));//ブラシの色

							//ブラシを設定
	SelectObject(hdc, hbrush);

	//++++++++++++++++++++++++++++++++++++++++
	//六芒星を描画
	//++++++++++++++++++++++++++++++++++++++++

	//図形の中心を設定
	POINT chusin;
	chusin.x = 400;
	chusin.y = 400;

	//図形の大きさを設定
	int scale = 100;

	//多角形の頂点の数
	int kaku_cnt = 6;

	//座標を設定
	POINT rect_po[CHOTEN_MAX];

	//座標を90度左回転(90度右回転はπ/2)
	double left90 = -MY_PI / 2;

	//座標を計算
	int i;
	for (i = 0; i < kaku_cnt; i++)
	{
		//Xの座標=中心のX座標+大きさ*弧度(360度/図形の角の数*右回りで何番目の角+90度左回転)
		rect_po[i].x = chusin.x + scale * cos(2 * MY_PI / kaku_cnt * i + left90);
		//Yの座標=中心のY座標+大きさ*弧度(360度/図形の角の数*右回りで何番目の角+90度左回転)
		rect_po[i].y = chusin.y + scale * sin(2 * MY_PI / kaku_cnt * i + left90);
	}
	//最後の座標は一番最初の座標
	rect_po[i].x = rect_po[0].x;
	rect_po[i].y = rect_po[0].y;

	//複数の多角形の頂点の区切り
	int split[2]{ 3,3 };

	//六芒星の座標
	POINT rect_star[CHOTEN_MAX];

	//六芒星を書くときの書き順を参考にする
	rect_star[0].x = rect_po[0].x;
	rect_star[0].y = rect_po[0].y;

	rect_star[1].x = rect_po[2].x;
	rect_star[1].y = rect_po[2].y;

	rect_star[2].x = rect_po[4].x;
	rect_star[2].y = rect_po[4].y;
	//------------------------------
	rect_star[3].x = rect_po[1].x;
	rect_star[3].y = rect_po[1].y;

	rect_star[4].x = rect_po[3].x;
	rect_star[4].y = rect_po[3].y;

	rect_star[5].x = rect_po[5].x;
	rect_star[5].y = rect_po[5].y;
	//------------------------------

	//多角形の中で線が交差しているところは塗りつぶさない
	SetPolyFillMode(hdc, WINDING);

	//多角形の塗りつぶし
	PolyPolygon(
		hdc,		//デバイスコンテキストのハンドル
		rect_star,	//多角形の座標
		split,		//複数の多角形の頂点の区切り
		2);			//多角形の総数

					//ブラシをデフォルトに戻す
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//ブラシを削除
	DeleteObject(hbrush);

	//ペンをデフォルトに戻す
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//ペンを削除
	DeleteObject(hpen);
}

//########## パックマンを描画する関数 ##########
VOID MY_DRAW_PACMAN(HDC hdc)
{
	//ペン：線を引く色、太さなどを設定
	HPEN hpen;

	//ペンを作成
	hpen = CreatePen(
		PS_SOLID,			//ペンのタイプ
		1,					//ペンの太さ
		RGB(0, 0, 0));		//ペンの色

							//ペンを設定
	SelectObject(hdc, hpen);

	//ブラシ：塗りつぶす色、模様などを設定
	HBRUSH hbrush;

	//ブラシを作成
	hbrush = CreateSolidBrush(
		RGB(255, 255, 0));//ブラシの色

						  //ブラシを設定
	SelectObject(hdc, hbrush);

	//座標を90度左回転(90度右回転はπ/2)
	double left90 = -MY_PI / 2;

	//++++++++++++++++++++++++++++++++++++++++
	//弧を描画
	//++++++++++++++++++++++++++++++++++++++++

	//図形の座標を設定
	RECT rect_eli = {
		200,200,	//左上の座標
		300,300		//右下の座標
	};

	//楕円の半径を取得
	int hankei = (rect_eli.right - rect_eli.left) / 2;

	//楕円の中心を取得
	POINT chusin = {
		rect_eli.left + hankei,	// X座標
		rect_eli.top + hankei	// Y座標
	};

	//弧の始点の座標
	POINT pt_ko_start = {
		chusin.x + hankei * cos(2 * MY_PI / 8 * 1 + left90),
		chusin.y + hankei * sin(2 * MY_PI / 8 * 1 + left90) };

	//弧の終点の座標
	POINT pt_ko_end = {
		chusin.x + hankei * cos(2 * MY_PI / 8 * 3 + left90),
		chusin.y + hankei * sin(2 * MY_PI / 8 * 3 + left90) };

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_eli.left, rect_eli.top, NULL);

	//扇形を描画
	Pie(
		hdc,
		rect_eli.left,		//円の左上のX座標
		rect_eli.top,		//円の左上のY座標
		rect_eli.right,		//円の右下のX座標
		rect_eli.bottom,	//円の右下のY座標
		pt_ko_start.x,		//弧の始点のX座標
		pt_ko_start.y,		//弧の始点のY座標
		pt_ko_end.x,		//弧の終点のX座標
		pt_ko_end.y);		//弧の終点のY座標

							//ブラシをデフォルトに戻す
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//ブラシを削除
	DeleteObject(hbrush);

	//ペンをデフォルトに戻す
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//ペンを削除
	DeleteObject(hpen);
}

//########## 六角形を描画する関数 ##########
VOID MY_DRAW_PENTAGON(HDC hdc)
{
	//ペン：線を引く色、太さなどを設定
	HPEN hpen;

	//ペンを作成
	hpen = CreatePen(
		PS_SOLID,			//ペンのタイプ
		1,					//ペンの太さ
		RGB(0, 0, 0));		//ペンの色

							//ペンを設定
	SelectObject(hdc, hpen);

	//ブラシ：塗りつぶす色、模様などを設定
	HBRUSH hbrush;

	//ブラシを作成
	hbrush = CreateSolidBrush(
		RGB(0, 128, 0));//ブラシの色

						//ブラシを設定
	SelectObject(hdc, hbrush);

	//++++++++++++++++++++++++++++++++++++++++
	//六角形を描画
	//++++++++++++++++++++++++++++++++++++++++

	//図形の中心を設定
	POINT chusin;
	chusin.x = 100;
	chusin.y = 250;

	//図形の大きさを設定
	int scale = 70;

	//多角形の頂点の数
	int kaku_cnt = 6;

	//座標を設定
	POINT rect_po[CHOTEN_MAX];

	//座標を90度左回転(90度右回転はπ/2)
	double left90 = -MY_PI / 2;

	//座標を計算
	int i;
	for (i = 0; i < kaku_cnt; i++)
	{
		//Xの座標=中心のX座標+大きさ*弧度(360度/図形の角の数*右回りで何番目の角+90度左回転)
		rect_po[i].x = chusin.x + scale * cos(2 * MY_PI / kaku_cnt * i + left90);
		//Yの座標=中心のY座標+大きさ*弧度(360度/図形の角の数*右回りで何番目の角+90度左回転)
		rect_po[i].y = chusin.y + scale * sin(2 * MY_PI / kaku_cnt * i + left90);
	}
	//最後の座標は一番最初の座標
	rect_po[i].x = rect_po[0].x;
	rect_po[i].y = rect_po[0].y;

	//多角形の中をすべて塗りつぶす
	SetPolyFillMode(hdc, WINDING);

	//多角形の塗りつぶし
	Polygon(
		hdc,		//デバイスコンテキストのハンドル
		rect_po,	//多角形の座標
		kaku_cnt);	//多角形の頂点の数

					//ブラシをデフォルトに戻す
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//ブラシを削除
	DeleteObject(hbrush);

	//ペンをデフォルトに戻す
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//ペンを削除
	DeleteObject(hpen);
}

//########## モンスターボールを描画する関数 ##########
VOID MY_DRAW_MONBALL(HDC hdc)
{
	//++++++++++++++++++++++++++++++++++++++++
	//ペンとブラシを作成
	//++++++++++++++++++++++++++++++++++++++++

	//ペンを作成
	HPEN hpen_Black = CreatePen(PS_SOLID, 1, RGB(0, 0, 0));

	//ペンを作成
	HPEN hpen_Black_Bold = CreatePen(PS_SOLID, 4, RGB(0, 0, 0));

	//ペンを設定
	SelectObject(hdc, hpen_Black_Bold);

	//ブラシを作成
	HBRUSH hbrush_Red = CreateSolidBrush(RGB(255, 0, 0));

	//ブラシを作成
	HBRUSH hbrush_White = CreateSolidBrush(RGB(255, 255, 255));

	//ブラシを設定
	SelectObject(hdc, hbrush_White);

	//++++++++++++++++++++++++++++++++++++++++
	//図形の情報を設定
	//++++++++++++++++++++++++++++++++++++++++

	//図形の座標を設定
	RECT rect_eli = {
		300,200,	//左上の座標
		400,300		//右下の座標
	};

	//楕円の半径を取得
	int hankei = (rect_eli.right - rect_eli.left) / 2;

	//楕円の中心を取得
	POINT chusin = {
		rect_eli.left + hankei,	// X座標
		rect_eli.top + hankei	// Y座標
	};

	//座標を90度左回転(90度右回転はπ/2)
	double left90 = -MY_PI / 2;

	//++++++++++++++++++++++++++++++++++++++++
	//上の赤い部分を描画
	//++++++++++++++++++++++++++++++++++++++++

	//ペンを設定
	SelectObject(hdc, hpen_Black_Bold);

	//ブラシを設定
	SelectObject(hdc, hbrush_Red);

	//弧の始点の座標
	POINT pt_ko_start;

	//弧の終点の座標
	POINT pt_ko_end;

	//弧の始点の座標
	pt_ko_start.x = chusin.x + hankei * cos(2 * MY_PI / 8 * 2 + left90);
	pt_ko_start.y = chusin.y + hankei * sin(2 * MY_PI / 8 * 2 + left90);

	//弧の終点の座標
	pt_ko_end.x = chusin.x + hankei * cos(2 * MY_PI / 8 * 6 + left90);
	pt_ko_end.y = chusin.y + hankei * sin(2 * MY_PI / 8 * 6 + left90);

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_eli.left, rect_eli.top, NULL);

	//扇形を描画
	Pie(
		hdc,
		rect_eli.left,		//円の左上のX座標
		rect_eli.top,		//円の左上のY座標
		rect_eli.right,		//円の右下のX座標
		rect_eli.bottom,	//円の右下のY座標
		pt_ko_start.x,		//弧の始点のX座標
		pt_ko_start.y,		//弧の始点のY座標
		pt_ko_end.x,		//弧の終点のX座標
		pt_ko_end.y);		//弧の終点のY座標

							//++++++++++++++++++++++++++++++++++++++++
							//下の白い部分を描画
							//++++++++++++++++++++++++++++++++++++++++

							//ペンを設定
	SelectObject(hdc, hpen_Black_Bold);

	//ブラシを設定
	SelectObject(hdc, hbrush_White);

	//弧の始点の座標
	pt_ko_start.x = chusin.x + hankei * cos(2 * MY_PI / 8 * 6 + left90);
	pt_ko_start.y = chusin.y + hankei * sin(2 * MY_PI / 8 * 6 + left90);

	//弧の終点の座標
	pt_ko_end.x = chusin.x + hankei * cos(2 * MY_PI / 8 * 2 + left90);
	pt_ko_end.y = chusin.y + hankei * sin(2 * MY_PI / 8 * 2 + left90);

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_eli.left, rect_eli.top, NULL);

	//扇形を描画
	Pie(
		hdc,
		rect_eli.left,		//円の左上のX座標
		rect_eli.top,		//円の左上のY座標
		rect_eli.right,		//円の右下のX座標
		rect_eli.bottom,	//円の右下のY座標
		pt_ko_start.x,		//弧の始点のX座標
		pt_ko_start.y,		//弧の始点のY座標
		pt_ko_end.x,		//弧の終点のX座標
		pt_ko_end.y);		//弧の終点のY座標

							//++++++++++++++++++++++++++++++++++++++++
							//真ん中の丸いボタンを描画
							//++++++++++++++++++++++++++++++++++++++++

							//ペンを設定
	SelectObject(hdc, hpen_Black_Bold);

	//ブラシを設定
	SelectObject(hdc, hbrush_White);

	//図形の座標を設定
	RECT rect_circle;
	rect_circle.left = rect_eli.left + 35;
	rect_circle.top = rect_eli.top + 35;
	rect_circle.right = rect_eli.right - 35;
	rect_circle.bottom = rect_eli.bottom - 35;

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_circle.left, rect_circle.top, NULL);

	//楕円を描画
	Ellipse(
		hdc,
		rect_circle.left,
		rect_circle.top,
		rect_circle.right,
		rect_circle.bottom);

	//++++++++++++++++++++++++++++++++++++++++
	//真ん中の丸いボタンの中のボタンを描画
	//++++++++++++++++++++++++++++++++++++++++

	//ペンを設定
	SelectObject(hdc, hpen_Black);

	//ブラシを設定
	SelectObject(hdc, hbrush_White);

	//図形の座標を設定
	RECT rect_circle_button;
	rect_circle_button.left = rect_eli.left + 42;
	rect_circle_button.top = rect_eli.top + 42;
	rect_circle_button.right = rect_eli.right - 42;
	rect_circle_button.bottom = rect_eli.bottom - 42;

	//線をどこから描き始めるか設定する
	MoveToEx(hdc, rect_circle_button.left, rect_circle_button.top, NULL);

	//楕円を描画
	Ellipse(
		hdc,
		rect_circle_button.left,
		rect_circle_button.top,
		rect_circle_button.right,
		rect_circle_button.bottom);

	//++++++++++++++++++++++++++++++++++++++++
	//ペンとブラシをデフォルトに戻す
	//++++++++++++++++++++++++++++++++++++++++

	//ブラシをデフォルトに戻す
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//ペンをデフォルトに戻す
	SelectObject(hdc, GetStockObject(BLACK_PEN));

	//++++++++++++++++++++++++++++++++++++++++
	//ペンとブラシを削除
	//++++++++++++++++++++++++++++++++++++++++

	//ブラシを削除
	DeleteObject(hbrush_Red);

	//ブラシを削除
	DeleteObject(hbrush_White);

	//ペンを削除
	DeleteObject(hpen_Black);

	//ペンを削除
	DeleteObject(hpen_Black_Bold);

}

//########## ビットマップを描画する関数 ##########
VOID MY_DRAW_BITMAP(HDC hdc)
{

	//ブラシを作成
	HBRUSH hbrush = CreateSolidBrush(RGB(128, 128, 0));

	//ブラシを設定
	SelectObject(hdc, hbrush);

	//四角を描画
	Rectangle(
		hdc,			//デバイスコンテキストのハンドル
		rect_c.left,	//四角の左上のX座標
		rect_c.top,		//四角の左上のY座標
		rect_c.right,	//四角の右下のX座標
		rect_c.bottom);	//四角の右下のY座標

						//+++++ビットマップを描画++++++++++++++++++++

						//ビットマップの表示位置を設定
	bmp_dragon.x = 100;
	bmp_dragon.y = 100;

	//ビットマップを描画
	BitBlt(
		hdc,				//描画するデバイスコンテキスト
		bmp_dragon.x,		//描画開始位置X座標
		bmp_dragon.y,		//描画開始位置Y座標
		bmp_dragon.width,	//描画する幅
		bmp_dragon.height,	//描画する高さ
		bmp_dragon.mhdc,	//ビットマップのデバイスコンテキスト
		0,					//ビットマップをどこからコピーするか(X座標)
		0,					//ビットマップをどこからコピーするか(X座標)
		SRCCOPY);			//塗りつぶしのオプション(ラスタオペレーションコード)

							//+++++ビットマップの背景を透過して描画(お手軽)++++++++++++++++++++

							//ビットマップの表示位置を設定
	bmp_dragon.x = 200;
	bmp_dragon.y = 200;


	//背景色を指定して描画
	TransparentBlt(
		hdc,				//描画するデバイスコンテキスト
		bmp_dragon.x,		//描画開始位置X座標
		bmp_dragon.y,		//描画開始位置Y座標
		bmp_dragon.width,	//描画する幅
		bmp_dragon.height,	//描画する高さ
		bmp_dragon.mhdc,	//ビットマップのデバイスコンテキスト
		0,					//ビットマップをどこからコピーするか(X座標)
		0,					//ビットマップをどこからコピーするか(Y座標)
		bmp_dragon.width,	//ビットマップをどこまでコピーするか(X座標)
		bmp_dragon.height,	//ビットマップをどこまでコピーするか(Y座標)
		RGB(107, 140, 148));//GetPixel(bmp_dragon.mhdc,0,0)も可
							//+++++ビットマップの背景を透過して描画(高速描画)++++++++++++++++++++

							//ビットマップの表示位置を設定
	bmp_dragon_mask.x = 300;
	bmp_dragon_mask.y = 300;

	bmp_dragon_white.x = 300;
	bmp_dragon_white.y = 300;

	//背景とマスクをANDで転送→マスクの黒い部分は無視される
	BitBlt(
		hdc,						//描画するデバイスコンテキスト
		bmp_dragon_mask.x,			//描画開始位置X座標
		bmp_dragon_mask.y,			//描画開始位置Y座標
		bmp_dragon_mask.width,		//描画する幅
		bmp_dragon_mask.height,		//描画する高さ
		bmp_dragon_mask.mhdc,		//ビットマップのデバイスコンテキスト
		0,							//ビットマップをどこからコピーするか(X座標)
		0,							//ビットマップをどこからコピーするか(X座標)
		SRCPAINT);					//塗りつぶしのオプション(ラスタオペレーションコード)

									//背景とビットマップをORで転送→ビットマップの白い背景は無視される
	BitBlt(
		hdc,						//描画するデバイスコンテキスト
		bmp_dragon_white.x,			//描画開始位置X座標
		bmp_dragon_white.y,			//描画開始位置Y座標
		bmp_dragon_white.width,		//描画する幅
		bmp_dragon_white.height,	//描画する高さ
		bmp_dragon_white.mhdc,		//ビットマップのデバイスコンテキスト
		0,							//ビットマップをどこからコピーするか(X座標)
		0,							//ビットマップをどこからコピーするか(X座標)
		SRCAND);					//塗りつぶしのオプション(ラスタオペレーションコード)

									//+++++ 画像の拡大・縮小 ++++++++++++++++++++

									//拡大縮小率(倍)
	double rate = 2.0;

	//ビットマップの表示位置を設定
	bmp_dragon.x = 50;
	bmp_dragon.y = 250;

	//ストレッチモードを指定
	SetStretchBltMode(hdc, COLORONCOLOR);

	//ストレッチモードの種類
	//BLACKONWHITE	残す点の色と取り除く点の色を論理 AND 演算子で結合
	//COLORONCOLOR	取り除く点の情報を保存することなく、削除します
	//HALFTONE		コピー先のブロックの平均的な色が、コピー元のピクセルの色に近い色
	//				HALFTONEモードを設定した場合は、ブラシのずれを防ぐため
	//				SetBrushOrgEx() 関数を呼び出す
	//WHITEONBLACK	残す点の色と取り除く点の色を論理 OR 演算子で結合
	//STRETCH_ANDSCANS		BLACKONWHITE と同じ
	//STRETCH_DELETESCANS	COLORONCOLOR と同じです
	//STRETCH_HALFTONE		HALFTONE と同じです
	//STRETCH_ORSCANS		WHITEONBLACK と同じです

	StretchBlt(
		hdc,					//コピー先のデバイスコンテキストのハンドル
		bmp_dragon.x,			//コピー先の長方形の左上 X座標
		bmp_dragon.y,			//コピー先の長方形の左上 Y座標
		bmp_dragon.width*rate,	//コピー先の長方形の右下 X座標
		bmp_dragon.height*rate,	//コピー先の長方形の右下 X座標
		bmp_dragon.mhdc,		//コピー元のデバイスコンテキストのハンドル
		0,						//コピー元の長方形の左上 X座標
		0,						//コピー元の長方形の左上 Y座標
		bmp_dragon.width,		//コピー元の長方形の右下 X座標
		bmp_dragon.height,		//コピー元の長方形の左上 Y座標
		SRCCOPY					//ラスタオペレーションを指定
	);

	//+++++ 画像を反転させる ++++++++++++++++++++

	//ビットマップの表示位置を設定
	bmp_dragon.x = 400;
	bmp_dragon.y = 400;

	//拡大縮小率
	rate = 0.75;

	//コピー先の長方形の右下の座標に、マイナスを付加すると反転する
	//左右反転
	StretchBlt(
		hdc,						//コピー先のデバイスコンテキストのハンドル
		bmp_dragon.x,				//コピー先の長方形の左上 X座標
		bmp_dragon.y,				//コピー先の長方形の左上 Y座標
		-(bmp_dragon.width*rate),	//コピー先の長方形の右下 X座標
		bmp_dragon.height*rate,		//コピー先の長方形の右下 X座標
		bmp_dragon.mhdc,			//コピー元のデバイスコンテキストのハンドル
		0,							//コピー元の長方形の左上 X座標
		0,							//コピー元の長方形の左上 Y座標
		bmp_dragon.width,			//コピー元の長方形の右下 X座標
		bmp_dragon.height,			//コピー元の長方形の左上 Y座標
		SRCCOPY						//ラスタオペレーションを指定
	);

	//+++++ 半透明な画像を表示させる ++++++++++++++++++++

	//ビットマップの表示位置を設定
	bmp_dragon.x = 350;
	bmp_dragon.y = 100;

	//拡大縮小率
	rate = 2.0;

	BLENDFUNCTION bf;	//ブレンドファンクション構造体

	bf.BlendOp = AC_SRC_OVER;		//AC_SRC_OVERのみ
	bf.BlendFlags = 0;				//ゼロのみ
	bf.AlphaFormat = AC_SRC_ALPHA;	//ビットマップのアルファチャネルを使用
	bf.SourceConstantAlpha = 100;	//透明にする割合(透明：0～255：不透明)

									//半透明で表示
	AlphaBlend(
		hdc,						//コピー先のデバイスコンテキストのハンドル
		bmp_dragon.x,				//コピー先の長方形の左上 X座標
		bmp_dragon.y,				//コピー先の長方形の左上 Y座標
		bmp_dragon.width *rate,		//コピー先の長方形の右下 X座標
		bmp_dragon.height*rate,		//コピー先の長方形の右下 X座標
		bmp_dragon.mhdc,			//コピー元のデバイスコンテキストのハンドル
		0,							//コピー元の長方形の左上 X座標
		0,							//コピー元の長方形の左上 Y座標
		bmp_dragon.width,			//コピー元の長方形の右下 X座標
		bmp_dragon.height,			//コピー元の長方形の左上 Y座標
		bf							//ブレンドファンクション構造体
	);

	//+++++ 画像の背景を透過して拡大・縮小 ++++++++++++++++++++

	//ビットマップの表示位置を設定
	bmp_dragon_mask.x = 250;
	bmp_dragon_mask.y = 350;

	bmp_dragon_white.x = 250;
	bmp_dragon_white.y = 350;

	//拡大縮小率
	rate = 1.50;

	//背景とマスクをANDで転送→マスクの黒い部分は無視される
	StretchBlt(
		hdc,							//コピー先のデバイスコンテキストのハンドル
		bmp_dragon_mask.x,				//コピー先の長方形の左上 X座標
		bmp_dragon_mask.y,				//コピー先の長方形の左上 Y座標
		-(bmp_dragon_mask.width*rate),	//コピー先の長方形の右下 X座標
		bmp_dragon_mask.height*rate,	//コピー先の長方形の右下 X座標
		bmp_dragon_mask.mhdc,			//コピー元のデバイスコンテキストのハンドル
		0,								//コピー元の長方形の左上 X座標
		0,								//コピー元の長方形の左上 Y座標
		bmp_dragon_mask.width,			//コピー元の長方形の右下 X座標
		bmp_dragon_mask.height,			//コピー元の長方形の左上 Y座標
		SRCPAINT						//ラスタオペレーションを指定
	);

	//背景とビットマップをORで転送→ビットマップの白い背景は無視される
	StretchBlt(
		hdc,							//コピー先のデバイスコンテキストのハンドル
		bmp_dragon_white.x,				//コピー先の長方形の左上 X座標
		bmp_dragon_white.y,				//コピー先の長方形の左上 Y座標
		-(bmp_dragon_white.width*rate),	//コピー先の長方形の右下 X座標
		bmp_dragon_white.height*rate,	//コピー先の長方形の右下 X座標
		bmp_dragon_white.mhdc,			//コピー元のデバイスコンテキストのハンドル
		0,								//コピー元の長方形の左上 X座標
		0,								//コピー元の長方形の左上 Y座標
		bmp_dragon_white.width,			//コピー元の長方形の右下 X座標
		bmp_dragon_white.height,		//コピー元の長方形の左上 Y座標
		SRCAND							//ラスタオペレーションを指定
	);

	//ブラシをデフォルトに戻す
	SelectObject(hdc, GetStockObject(WHITE_BRUSH));

	//ブラシを削除
	DeleteObject(hbrush);

}

//########## ウィンドウプロシージャ関数 ##########
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

		//+++++ドラゴンのビットマップ++++++++++++++++++++

		//ビットマップを読み込み
		bmp_dragon.hbmp =		//ビットマップのハンドル
			(HBITMAP)LoadImage(
				NULL,			// インスタンスのハンドル/BTMAPを読み込む場合はNULL
				BMP_DRA_PASS,	//ビットマップの場所と名前
				IMAGE_BITMAP,	//イメージのタイプ
				0,				//幅   /そのまま使用するには0
				0,				//高さ /そのまま使用するには0
				LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ロードのオプション

														//ビットマップ読み込みエラー
		if (bmp_dragon.hbmp == NULL)
		{
			//ビットマップが読み込めなかったとき
			MessageBox(hwnd, ERR_MSG_NO_READ_BMP, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//画像サイズ取得
		GetObject(bmp_dragon.hbmp, sizeof(BITMAP), &bmp_dragon.bmp);
		bmp_dragon.width = bmp_dragon.bmp.bmWidth;		//幅を取得
		bmp_dragon.height = bmp_dragon.bmp.bmHeight;	//高さを取得

														//メモリデバイスコンテキストを作成
		bmp_dragon.mhdc = CreateCompatibleDC(NULL);

		//メモリデバイスコンテキストにビットマップを設定
		SelectObject(bmp_dragon.mhdc, bmp_dragon.hbmp);

		//+++++ドラゴンのビットマップ(背景白)++++++++++++++++++++

		//ビットマップを読み込み
		bmp_dragon_white.hbmp =		//ビットマップのハンドル
			(HBITMAP)LoadImage(
				NULL,				// インスタンスのハンドル/BTMAPを読み込む場合はNULL
				BMP_DRA_WH_PASS,	//ビットマップの場所と名前
				IMAGE_BITMAP,		//イメージのタイプ
				0,					//幅   /そのまま使用するには0
				0,					//高さ /そのまま使用するには0
				LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ロードのオプション

														//ビットマップ読み込みエラー
		if (bmp_dragon_white.hbmp == NULL)
		{
			//ビットマップが読み込めなかったとき
			MessageBox(hwnd, ERR_MSG_NO_READ_BMP, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//画像サイズ取得
		GetObject(bmp_dragon_white.hbmp, sizeof(BITMAP), &bmp_dragon_white.bmp);
		bmp_dragon_white.width = bmp_dragon_white.bmp.bmWidth;		//幅を取得
		bmp_dragon_white.height = bmp_dragon_white.bmp.bmHeight;	//高さを取得

																	//メモリデバイスコンテキストを作成
		bmp_dragon_white.mhdc = CreateCompatibleDC(NULL);

		//メモリデバイスコンテキストにビットマップを設定
		SelectObject(bmp_dragon_white.mhdc, bmp_dragon_white.hbmp);

		//+++++ドラゴンのマスク++++++++++++++++++++

		//ビットマップを読み込み
		bmp_dragon_mask.hbmp =		//ビットマップのハンドル
			(HBITMAP)LoadImage(
				NULL,				// インスタンスのハンドル/BTMAPを読み込む場合はNULL
				BMP_DRA_MS_PASS,	//ビットマップの場所と名前
				IMAGE_BITMAP,		//イメージのタイプ
				0,					//幅   /そのまま使用するには0
				0,					//高さ /そのまま使用するには0
				LR_LOADFROMFILE | LR_CREATEDIBSECTION);	// ロードのオプション

														//ビットマップ読み込みエラー
		if (bmp_dragon_mask.hbmp == NULL)
		{
			//ビットマップが読み込めなかったとき
			MessageBox(hwnd, ERR_MSG_NO_READ_BMP, ERR_MSG_TITLE, MB_OK);

			return -1;
		}

		//画像サイズ取得
		GetObject(bmp_dragon_mask.hbmp, sizeof(BITMAP), &bmp_dragon_mask.bmp);
		bmp_dragon_mask.width = bmp_dragon_mask.bmp.bmWidth;		//幅を取得
		bmp_dragon_mask.height = bmp_dragon_mask.bmp.bmHeight;	//高さを取得

																//メモリデバイスコンテキストを作成
		bmp_dragon_mask.mhdc = CreateCompatibleDC(NULL);

		//メモリデバイスコンテキストにビットマップを設定
		SelectObject(bmp_dragon_mask.mhdc, bmp_dragon_mask.hbmp);

		//▼▼▼▼▼ WM_CREATEの修正 ▼▼▼▼▼

		//コメントアウト
		////タイマー：ある一定の指定した時間が経過すると
		////          メッセージキューにメッセージを送る機能
		////          メッセージを送るということは、
		////          マウスなどと同じ、入力装置の一つといえる
		////分解能　：限界周期が定められている
		////        　分解能以上の周期でメッセージを発行することはできない
		////          Windows2000以降の、NT系の場合は10ミリ秒
		////          1000ミリ÷10ミリ＝1秒間で100回、最大でメッセージを送れる

		////タイマーを分解能(10ミリ秒)でセット(開始)
		//SetTimer(
		//	hwnd,		//関連付けるウィンドウハンドル
		//	TIMER_ID_1,	//タイマーのID
		//	10,			//タイムアウト値(ミリ秒)
		//	NULL);		//TIMERPROC型関数へのポインタ/なし はNULL

		//				//タイマーを１秒でセット(開始)
		//SetTimer(hwnd, TIMER_ID_2, 1000, NULL);

		//▲▲▲▲▲ WM_CREATEの修正 ▲▲▲▲▲

		//▼▼▼▼▼ WM_CREATEの追加 ▼▼▼▼▼
		
		//タイマーを10ミリ間隔にセット(開始)
		SetTimer(hwnd, TIMER_ID_FPS, 10, NULL);

		//▲▲▲▲▲ WM_CREATEの追加 ▲▲▲▲▲

		//ウィンドウを生成するときは、0を返す
		return 0;

	case WM_TIMER:

		//▼▼▼▼▼ WM_TIMERの修正 ▼▼▼▼▼
		//コメントアウト
		//	switch (wp)
		//	{
		//	case TIMER_ID_1:
		//		timer_1_cnt++;
		//		break;
		//	case TIMER_ID_2:
		//		timer_2_cnt++;
		//		break;
		//	}
		//▲▲▲▲▲ WM_TIMERの修正 ▲▲▲▲▲

		//▼▼▼▼▼ WM_TIMERの追加 ▼▼▼▼▼

		switch (wp)
		{
		case TIMER_ID_FPS:

			//画面更新の時刻を取得する
			MY_FPS_UPDATE();

			//無効リージョンを発生
			//WM_PAINTを、一定時間で呼び出し
			InvalidateRect(hwnd, NULL, FALSE);

			//画面を、すぐに再描画する
			UpdateWindow(hwnd);

			//指定したFPSになるように待つ
			MY_FPS_WAIT();
			
			break;
		}
		
		//▲▲▲▲▲ WM_TIMERの追加 ▲▲▲▲▲

		return 0;

	case WM_PAINT:
		//ウィンドウ内を再描画するとき

		//デバイスコンテキストのハンドルを取得
		hdc = BeginPaint(hwnd, &ps);

		//現在のデバイスコンテキストを保存する
		SaveDC(hdc);

		//描画
		//MY_DRAW(hdc);

		//フォントを設定して描画
		//MY_SetFontDraw(hdc);

		//線を描画
		//MY_DRAW_LINE(hdc);

		//図を描画
		//MY_DRAW_GRAPH(hdc);


		//ペンを使用して描画
		//MY_DRAW_PEN(hdc);

		//ブラシを使用して描画
		//MY_DRAW_BRUSH(hdc);

		//多角形を塗りつぶして描画
		//MY_DRAW_POLYGON(hdc);

		//複数の多角形を塗りつぶして描画
		//MY_DRAW_POLYPOLYGON(hdc);

		//六角形を塗りつぶして描画する
		//MY_DRAW_PENTAGON(hdc);

		//パックマンを描画する
		//MY_DRAW_PACMAN(hdc);

		//モンスターボールを描画する
		//MY_DRAW_MONBALL(hdc);

		//ビットマップを描画する
		MY_DRAW_BITMAP(hdc_double);

		//マウスの座標位置を描画する
		MY_DRAW(hdc_double);

		//メモリ内の画像を描画
		BitBlt(hdc, 0, 0, rect_c.right, rect_c.bottom, hdc_double, 0, 0, SRCCOPY);

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
				0);			//メッセージの情報その２

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

		//ビットマップハンドルを削除
		DeleteObject(bmp_dragon.hbmp);

		//メモリデバイスコンテキストを破棄
		DeleteDC(bmp_dragon.mhdc);

		//ビットマップハンドルを削除
		DeleteObject(bmp_dragon_white.hbmp);

		//メモリデバイスコンテキストを破棄
		DeleteDC(bmp_dragon_white.mhdc);

		//ビットマップハンドルを削除
		DeleteObject(bmp_dragon_mask.hbmp);

		//メモリデバイスコンテキストを破棄
		DeleteDC(bmp_dragon_mask.mhdc);

		//ビットマップハンドルを削除
		DeleteObject(hbmp_double);

		//メモリデバイスコンテキストを破棄
		DeleteDC(hdc_double);

		//▼▼▼▼▼ WM_DESTROYの修正 ▼▼▼▼▼

		//コメントアウト
		////タイマー１を削除(終了)
		//KillTimer(hwnd, TIMER_ID_2);

		////タイマー２を削除(終了)
		//KillTimer(hwnd, TIMER_ID_1);

		//▲▲▲▲▲ WM_DESTROYの修正 ▲▲▲▲▲

		//▼▼▼▼▼ WM_DESTROYの追加 ▼▼▼▼▼

		//FPSタイマーを削除(終了)
		KillTimer(hwnd, TIMER_ID_FPS);

		//▲▲▲▲▲ WM_DESTROYの追加 ▲▲▲▲▲

		//メッセージキューに WM_QUIT を送る
		PostQuitMessage(0);
		return 0;
	}

	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, msg, wp, lp);
}
*/