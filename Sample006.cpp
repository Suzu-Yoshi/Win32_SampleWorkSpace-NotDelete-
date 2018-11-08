/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前

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

	//↓↓↓ウィンドウクラスの設定はここから↓↓↓
	winc.style = CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc = DefWindowProc;
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
	//+++++++++++++++++++++++++++++++++++++++++++++
	//Windowsからのメッセージ(イベント)を受け取る
	//+++++++++++++++++++++++++++++++++++++++++++++
	//・メッセージは、データ構造とアルゴリズムで学んだ
	//　「キュー」として格納されている
	//・「キュー」：(エンキュー)|A|→|B|C|D|→(デキュー):先入れ先出し法(FIFO)
	// データを追加するときには、列の最初に追加される（エンキュー）
	// データを取り出すときには、列の最後から取り出される（デキュー）
	//・この「キュー」のことを メッセージキュー と呼ぶ
	//・アプリケーション(プログラム)は、メッセージキューからメッセージを取り出す
	//+++++++++++++++++++++++++++++++++++++++++++++

	//メッセージを絶えず受け取り続ける
	while (TRUE)	//無限ループ(TRUE：整数型の1のこと)
	{
		//メッセージキューからメッセージを受け取る
		GetMessage(
			&msg,	//メッセージをmsg構造体に入れる
			NULL,	//メッセージを受け取るハンドル
					//NULLなら表示している全てのウィンドウからメッセージを受け取る
			0,		//受け取るメッセージの最小値：全て受け取る場合は0
			0);		//受け取るメッセージの最大値：全て受け取る場合は0

		//メッセージの種類ごとに処理を変える
		if(msg.message == WM_RBUTTONDOWN)	//マウスの右ボタンを押したとき
		{
			//メッセージボックスの戻り値(結果)を入れる変数
			int kekka_msg;						

			//メッセージボックスを表示
			kekka_msg = MessageBox(
				NULL,
				TEXT("画面を終了しますか？"),
				TEXT("Quesition"),
				MB_YESNO | MB_ICONQUESTION);

			//「はい」ボタンを押したとき
			if (kekka_msg == IDYES)				
			{
				//無限ループを抜ける
				break;
			}
			//「いいえ」ボタンを押したとき
			else if (kekka_msg == IDNO)
			{
				//何もしない
			}
			
		}

		//ウィンドウプロシージャにもメッセージを受け取らせる
		DispatchMessage(&msg);

		//ウィンドウプロシージャ：メッセージを処理する専用の関数
		//今は、すでに用意された(デフォルト)の関数を使用している
		//winc.lpfnWndProc = DefWindowProc; 
		//デフォルトの関数：DefWindowProcのおかげで、
		//画面の最大化、最初化や、ウィンドウサイズの変更ができる
	}
	return 0;
}

//実験：受け取っているメッセージを見てみよう！
// 1.プログラムをデバッグの開始(F5)で実行
// 2.実行しながら、Visual Studio画面上の ツール をクリック
// 3.Spy++(+)をクリック
// 4.ウィンドウ１から、自分で登録したウィンドウクラス を探す
// 5. 自分で登録したウィンドウクラス をクリックし、Spy++画面上の スパイ をクリック
// 7. メッセージのログ出力 をクリックし、OKボタンを押す
// 8.実行しているアプリケーション(プログラム)にマウスカーソルを当てる
// 9.終了する場合は、Spy++画面右上の「閉じる」ボタンで終了してください
*/