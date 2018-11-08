/*☆自分で設定したフォントで、文字を描画しよう☆
/*注意：プリントの\(バックスラッシュ)は、半角の￥マークです*/
/*※記入例と注意事項は以下の中にあります。参考にしてください。
  学生共有サーバ\担当\41.G1_Win32API
  */
 /* 
１．フォントのファイルをプロジェクト内に追加
	1-1.ソリューションエクスプローラーから
		自分のプロジェクトを右クリックし、
		エクスプローラーでフォルダを開く をクリック
	
	1-2.学生共有サーバ\担当\41.G1_Win32APIの中にある
		MY_FONT というフォルダを コピーする
	
	1-3.自分のプロジェクトが保存されているフォルダに
		MY_FONT というフォルダを 貼り付ける
		
	※今回は２種類を用意しました
	※今後、自分で使用したいフォントがある場合は、このフォルダにデータを入れて下さい
	※加えて、プログラムを追加しないと、フォントが使用できないことを忘れないで下さい
	
２．マクロ定義に以下を追加する

	#define ERR_MSG_NO_READ_FONT TEXT("フォントが
	\読み込めませんでした\nプログラムを終了します")		//\(半角の￥マークで、マクロ定義の改行)
	
	//すでにPCにインストールされているフォント
	#define FNT_MS_GOTHIC TEXT("ＭＳ ゴシック")		//ＭＳは全角、空白は半角、ゴシックは全角
	#define FNT_MS_MINCHO TEXT("ＭＳ 明朝")			//ＭＳは全角、空白は半角、明朝は全角
	
	//一時的に読み込むフォント
	#define FNT_JUD_PASS	TEXT(".\\MY_FONT\\JUDGE2.TTF")		//フォントの場所
	#define FNT_JUD_NAME	TEXT("Judge Hard")					//フォントの名前

	#define FNT_TANU_PASS	TEXT(".\\MY_FONT\\TanukiMagic.ttf")	//フォントの場所
	#define FNT_TANU_NAME	TEXT("たぬき油性マジック")			//フォントの名前

３．【プロトタイプ宣言】を追加する
	//フォントを設定する
	HFONT MY_CreateFont(HDC, LPCTSTR, int, int, int);

	//フォントを設定して描画する
	void MY_SetFontDraw(HDC);
	
４．フォントを設定して文字を描画する【関数】を追加する
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
			32,					//フォントのサイズ
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
	
５．フォントを設定する【関数】を追加する
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
			FW_REGULAR,				//フォントの重さ（太さ）
			FALSE,					//イタリック体
			FALSE,					//アンダーライン
			FALSE,					//打ち消し線

			charset,				//文字セット
									//ANSI      を使うならば ANSI_CHARSET 
									//Shift-JIS を使うならば SHIFTJIS_CHARSET
									//デフォルトを使うならば DEFAULT_CHARSET

			OUT_DEFAULT_PRECIS,		//出力精度
			CLIP_DEFAULT_PRECIS,	//クリッピング精度
			PROOF_QUALITY,			//出力品質
			FIXED_PITCH | FF_MODERN,//ピッチとファミリー
			fontName);				//フォントの書体名

		return hFont;
	}
	
６．【WM_CREATE】メッセージ内へ追加する
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
	
７．【WM_PAINT】メッセージ内へ追加する
	※MY_DRAW(hdc);の下に追加する

	//フォントを設定して描画 
	MY_SetFontDraw(hdc);
	
８．【WM_DESTROY】メッセージ内に追加する
	※PostQuitMessage(0);の上に追加する

	//一時的に読み込んだ judge hardフォントを削除
	RemoveFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL);

	//一時的に読み込んだ たぬき油性マジックフォントを削除
	RemoveFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL);

☆プログラムが入力できたら、実行させよう！☆*/











/*
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
#define WIN_X		100		//横の位置
#define WIN_Y		100		//縦の位置
#define WIN_WIDTH	500		//幅
#define WIN_HEIGHT	500		//高さ

//エラーメッセージ
#define ERR_MSG_TITLE			TEXT("ERROR")
#define ERR_MSG_NO_WIN_CLASS	TEXT("ウィンドウクラスが登録できませんでした\nプログラムを終了します")
#define ERR_MSG_NO_WIN_CREATE	TEXT("ウィンドウが作成できませんでした\nプログラムを終了します")

//▼▼▼▼▼２．マクロ定義に以下を追加する▼▼▼▼▼

#define ERR_MSG_NO_READ_FONT TEXT("フォントが\
読み込めませんでした\nプログラムを終了します")

//▲▲▲▲▲２．マクロ定義に以下を追加する▲▲▲▲▲

//ウィンドウのサイズを変更できなくする
//実は、WS_OVERLAPPEDWINDOWから、WS_THICKFRAME と WS_MAXIMIZEBOXを抜いたもの
#define WS_STATIC_WINDOW	WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX

//ウィンドウのタイトルをなくす
#define WS_NOT_TITLE WS_POPUP | WS_BORDER

//▼▼▼▼▼２．マクロ定義に以下を追加する▼▼▼▼▼

//すでにPCにインストールされているフォント
#define FNT_MS_GOTHIC TEXT("ＭＳ ゴシック")
#define FNT_MS_MINCHO TEXT("ＭＳ 明朝")

//一時的に読み込むフォント
#define FNT_JUD_PASS	TEXT(".\\MY_FONT\\JUDGE2.TTF")		//フォントの場所
#define FNT_JUD_NAME	TEXT("Judge Hard")

#define FNT_TANU_PASS	TEXT(".\\MY_FONT\\TanukiMagic.ttf")	//フォントの場所
#define FNT_TANU_NAME	TEXT("たぬき油性マジック")

//▲▲▲▲▲２．マクロ定義に以下を追加する▲▲▲▲▲

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

//▼▼▼▼▼５．【プロトタイプ宣言】を追加する▼▼▼▼▼

//フォントを設定する
HFONT MY_CreateFont(HDC, LPCTSTR, int, int, int);

//フォントを設定して描画する
void MY_SetFontDraw(HDC);

//▲▲▲▲▲５．【プロトタイプ宣言】を追加する▲▲▲▲▲

//+++++++++++++++++++++++++++++++++++++++++++++
//グローバル変数の宣言と初期化
//+++++++++++++++++++++++++++++++++++++++++++++
//マウスの座標を管理する構造体
POINT pt_Start = { 0,0 };

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
	wsprintf(Str_X_Y, TEXT("マウスの位置(X:%03d,Y:%03d)"), pt_Start.x, pt_Start.y);

	//マウスの座標を描画
	TextOut(hdc, 100, tm.tmHeight * 0, Str_X_Y, lstrlen(Str_X_Y));

	//画面の大きさを整形
	wsprintf(Str_CX_CY, TEXT("画面の大きさ(X:%03d,Y:%03d)"), window_Size.right, window_Size.bottom);

	//画面の大きさを描画
	TextOut(hdc, 100, tm.tmHeight * 1, Str_CX_CY, lstrlen(Str_CX_CY));
}

//▼▼▼▼▼３．フォントを設定して文字を描画する【関数】を追加する▼▼▼▼▼
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
		32,					//フォントのサイズ
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
//▲▲▲▲▲３．フォントを設定して文字を描画する【関数】を追加する▲▲▲▲▲

//▼▼▼▼▼４．フォントを設定する【関数】を追加する▼▼▼▼▼
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
		FW_REGULAR,				//フォントの重さ（太さ）
		FALSE,					//イタリック体
		FALSE,					//アンダーライン
		FALSE,					//打ち消し線

		charset,				//文字セット
								//ANSI      を使うならば ANSI_CHARSET 
								//Shift-JIS を使うならば SHIFTJIS_CHARSET
								//デフォルトを使うならば DEFAULT_CHARSET

		OUT_DEFAULT_PRECIS,		//出力精度
		CLIP_DEFAULT_PRECIS,	//クリッピング精度
		PROOF_QUALITY,			//出力品質
		FIXED_PITCH | FF_MODERN,//ピッチとファミリー
		fontName);				//フォントの書体名

	return hFont;
}
//▲▲▲▲▲４．フォントを設定する【関数】を追加する▲▲▲▲▲

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

		//▼▼▼▼▼６．【WM_CREATE】メッセージ内へ追加する▼▼▼▼▼

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

		//▲▲▲▲▲６．【WM_CREATE】メッセージ内へ追加する▲▲▲▲▲

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
		
		//▼▼▼▼▼７．【WM_PAINT】メッセージ内へ追加する▼▼▼▼▼
		
		//フォントを設定して描画
		MY_SetFontDraw(hdc);
		
		//▲▲▲▲▲７．【WM_PAINT】メッセージ内へ追加する▲▲▲▲▲

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
		pt_Start.x = LOWORD(lp);
		//DWORD型(32ビット)の上位WORD(16ビット)を取り出す
		pt_Start.y = HIWORD(lp);

		//クライアント領域外の対処
		if (pt_Start.x < window_Size.left)
			pt_Start.x = window_Size.left;

		if (pt_Start.x >= window_Size.right)
			pt_Start.x = window_Size.right - 1;

		if (pt_Start.y < window_Size.top)
			pt_Start.y = window_Size.top;

		if (pt_Start.y >= window_Size.bottom)
			pt_Start.y = window_Size.bottom - 1;

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

		//▼▼▼▼▼８．【WM_DESTROY】メッセージ内に追加する▼▼▼▼▼

		//一時的に読み込んだ judge hardフォントを削除
		RemoveFontResourceEx(FNT_JUD_PASS, FR_PRIVATE, NULL);

		//一時的に読み込んだ たぬき油性マジックフォントを削除
		RemoveFontResourceEx(FNT_TANU_PASS, FR_PRIVATE, NULL);

		//▲▲▲▲▲８．【WM_DESTROY】メッセージ内に追加する▲▲▲▲▲

		//メッセージキューに WM_QUIT を送る
		PostQuitMessage(0);
		return 0;
	}

	//デフォルトのウィンドウプロシージャ関数を呼び出す
	return DefWindowProc(hwnd, msg, wp, lp);
}
*/