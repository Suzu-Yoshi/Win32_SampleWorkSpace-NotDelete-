/*
#include<windows.h>	//windows.hをインクルード

#define MY_WIN_CLASS "MY_WIN_CLASS"	//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前

//一番最初に実行される関数：WinMain
//引数：HINSTANCE hInstance：プログラムを管理する番号(インスタンスハンドル)
//引数：HINSTANCE hPrevInstance： Win16時代の名残：今はNULL
//引数：PSTR lpCmdLine：コマンドライン引数の文字列
//引数：int nCmdShow：ウインドウの状態
int WINAPI WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	PSTR lpCmdLine,
	int nCmdShow)
{
	//+++++++++++++++++++++++++++++++++++++++++++++
	//ウィンドウクラスを作成
	//+++++++++++++++++++++++++++++++++++++++++++++

	WNDCLASS winc;	//ウィンドウクラスを保存する構造体

	HWND hwnd;	//個々のWindowを識別する値(ウィンドウハンドル)

	//ブラシを作成
	//static HBRUSH brush;	//★課題４で使用★

	//ブラシの色を設定
	//brush = CreateSolidBrush(RGB(255, 0, 0));	//★課題４で使用★

	//↓↓↓ウィンドウクラスの設定はここから↓↓↓

	//ウィンドウスタイル：CS_HREDRAW | CS_VREDRAW
	//ウィンドウが水平/垂直にウィンドウサイズが
	//変更されると再描画する
	winc.style = CS_HREDRAW | CS_VREDRAW;
	
	//デフォルトのウィンドウプロシージャを設定
	//ウィンドウプロシージャ：メッセージを処理する関数
	winc.lpfnWndProc = DefWindowProc;
	
	//クラス構造体の追加領域：通常は0
	winc.cbClsExtra = 0;
	
	//ウィンドウ構造体の追加領域：通常は0
	winc.cbWndExtra = 0;
	
	//インスタンスハンドル
	winc.hInstance = hInstance;
	
	//アイコンのハンドル
	winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	
	//マウスカーソルのハンドル
	winc.hCursor = LoadCursor(NULL, IDC_ARROW);
	
	//ウィンドウの背景色
	winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);

	//作成したブラシを使用して背景色を塗りつぶす
	//winc.hbrBackground = brush;	//★課題４で使用★
	
	//メニューのハンドル
	winc.lpszMenuName = NULL;
	
	//ウィンドウクラスにつける名前
	winc.lpszClassName = TEXT(MY_WIN_CLASS);

	//↑↑↑ウィンドウクラスの設定はここまで↑↑↑

	
	
	//RegisterClass：ウィンドウクラスを登録する
	if (!RegisterClass(&winc))
	{
		//登録ができなかったら、プログラムを終了する
		return 0;
	}

	//ウィンドウの作成(ウィンドウクラスの生成)
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

	//メッセージボックスを表示(ウィンドウがすぐに閉じないようにする)
	MessageBox(
		NULL,
		TEXT("OKを押すとウィンドウを閉じます"),
		TEXT("Message"),
		MB_OK);

	//作成したブラシを削除
	//DeleteObject(brush);	//★課題４で使用★

	return 0;
}

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//課題１：アイコンを自由に変えてみよう
//アイコンのハンドル
//winc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//IDI_APPLICATION の箇所を変更する

//以下のアイコンに変更できる
//IDI_APPLICATION	既定のアプリケーションアイコン
//IDI_ASTERISK		IDI_INFORMATION と同じです
//IDI_ERROR			ストップマークのアイコン
//IDI_EXCLAMATION	IDI_WARNING と同じです
//IDI_HAND			IDI_ERROR と同じです
//IDI_INFORMATION	情報アイコン（吹き出しの中に i の文字）
//IDI_QUESTION		疑問符のアイコン
//IDI_WARNING		感嘆符のアイコン
//IDI_WINLOGO		Windows ロゴのアイコン
//参考サイト：https://msdn.microsoft.com/ja-jp/library/cc364833.aspx







//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//課題２：マウスカーソルを自由に変えてみよう
//マウスカーソルのハンドル
//winc.hCursor = LoadCursor(NULL, IDC_ARROW);
//IDC_ARROW の箇所を変更する

//以下のマウスカーソルに変更できる
//IDC_APPSTARTING	標準の矢印カーソルと小さい砂時計カーソル
//IDC_ARROW			標準の矢印カーソル
//IDC_CROSS			十字カーソル
//IDC_HAND			Windows 2000：ハンドカーソル
//IDC_HELP			矢印と疑問符
//IDC_IBEAM			アイビーム（ 縦線）カーソル
//IDC_ICON			バージョンが 4.0 以降
//IDC_NO			禁止カーソル（ 円に左上から右下への斜線）
//IDC_SIZE			バージョンが 4.0 以降（Windows NT 4.0 以降）
//IDC_SIZEALL		4 方向の矢印カーソル
//IDC_SIZENESW		右上と左下を指す両方向矢印カーソル
//IDC_SIZENS		上下を指す両方向矢印カーソル
//IDC_SIZENWSE		左上と右下を指す両方向矢印カーソル
//IDC_SIZEWE		左右を指す両方向矢印カーソル
//IDC_UPARROW		上を指す垂直の矢印カーソル
//IDC_WAIT			砂時計カーソル
//参考サイト：https://msdn.microsoft.com/ja-jp/library/cc410880.aspx

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//課題３：背景色を自由に変えてみよう
//ウィンドウの背景色
//winc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
//WHITE_BRUSH の箇所を変更する

//以下の背景色に変更できる
//WHITE_BRUSH の箇所を変更する
//BLACK_BRUSH	黒のブラシ
//DKGRAY_BRUSH	濃い灰色のブラシ
//GRAY_BRUSH	灰色のブラシ
//LTGRAY_BRUSH	明るい灰色のブラシ
//WHITE_BRUSH	白のブラシ
//参考サイト：https://msdn.microsoft.com/ja-jp/library/cc410411.aspx

//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
//課題４：背景色をカラフルな色にしてみよう

//以下の行の先頭のコメント(//)を削除
//static HBRUSH brush;	
//brush = CreateSolidBrush(RGB(255, 0, 0));
//winc.hbrBackground = brush;
//DeleteObject(brush);
//RGB値の参考サイト：https://www.peko-step.com/tool/tfcolor.html
*/