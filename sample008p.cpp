/*
#include<windows.h>

#define MY_WIN_CLASS "MY_WIN_CLASS"	//自分で作成するｳｨﾝﾄﾞｳｸﾗｽの名前

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

	//↓↓↓ウィンドウクラスの設定はここから↓↓↓
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
	//アプリケーション(プログラム)を終了する
	//+++++++++++++++++++++++++++++++++++++++++++++
	BOOL ret_msg = TRUE;

	//WM_QUITというメッセージが送られるなければ、繰り返す
	while (TRUE)
	{
		//メッセージキューからメッセージを受け取る

		//GetMessageは、WM_QUITを受け取ると、FALSEを返す
		//				それ以外は、TRUEを返す
		ret_msg = GetMessage(&msg, NULL, 0, 0);

		//WM_QUITを受け取ったとき
		if (ret_msg == FALSE)
		{
			MessageBox(
				NULL,
				TEXT("プログラムを終了します"),
				TEXT("QUIT"),
				MB_OK);

			//無限ループを抜ける
			break;
		}

		//デフォルトウィンドウプロシージャにもメッセージを受け取らせる
		DispatchMessage(&msg);
	}

	//上の無限ループをこのように書くこともできる
	//while (GetMessage(&msg, NULL, 0, 0))	//GetMessageの戻り値がWM_QUIT→FALSEでないとき
	//{
	//	DispatchMessage(&msg);
	//}

	//終了コードは必ず WS_QUIT の wParam の値にしなければならない
	//正常に終了すれば wParam の値は、0になる
	return msg.wParam;
}
























//ウィンドウプロシージャ(関数)を作成
LRESULT CALLBACK MY_WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_LBUTTONUP:
		//マウスの左ボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("マウスの左ボタンを押しました"),
			TEXT("LEFT"),
			MB_OK);
		break;

	case WM_MBUTTONDOWN:
		//マウスの真ん中ボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("マウスの真ん中ボタンを押しました"),
			TEXT("MIDDLE"),
			MB_OK);
		break;

	case WM_RBUTTONUP:
		//マウスの右ボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("マウスの右ボタンを押しました"),
			TEXT("RIGHT"),
			MB_OK);
		break;

	//+++++++++++++++++++++++++++++++++++++++++++++
	//アプリケーション(プログラム)を終了する
	//+++++++++++++++++++++++++++++++++++++++++++++

	case WM_CLOSE:
		//閉じるボタンを押したとき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("ウィンドウを終了します"),
			TEXT("CLOSE"),
			MB_OK);

		break;

	case WM_DESTROY:
		//ウィンドウが破棄された(なくなった)とき

		//メッセージボックスを表示
		MessageBox(
			hwnd,
			TEXT("ウィンドウを破棄しました"),
			TEXT("DESTROY"),
			MB_OK);

		//メッセージキューに WM_QUIT を送る
		PostQuitMessage(0);
		return 0;

	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

//+++++++++++++++++++++++++++++++++++++++++++++
//参考：Window メッセージの一部
//※必要なときに、確認すればいいので、すべて覚えなくて大丈夫
//+++++++++++++++++++++++++++++++++++++++++++++
//0x0000	WM_NULL				特定のｳｨﾝﾄﾞｳにこのメッセージを投げてﾀｲﾑｱｳﾄするかどうかで生存確認を行う事ができる
//0x0001	WM_CREATE			ｳｨﾝﾄﾞｳが作成されていることを示します
//0x0002	WM_DESTROY			ｳｨﾝﾄﾞｳが破棄されようとしていることを示します
//0x0003	WM_MOVE				ｳｨﾝﾄﾞｳの位置が変更されたことを示します
//0x0005	WM_SIZE				ｳｨﾝﾄﾞｳのサイズが変更されていることを示します
//0x0006	WM_ACTIVATE			アクティブ状態が変更されていることを示します
//0x0007	WM_SETFOCUS			ｳｨﾝﾄﾞｳがキーボード・フォーカスを取得したことを示します
//0x0008	WM_KILLFOCUS		ｳｨﾝﾄﾞｳがキーボード・フォーカスを失っていることを示します
//0x000A	WM_ENABLE			ｳｨﾝﾄﾞｳの有効または無効の状態が変更されていることを示します
//0x000B	WM_SETREDRAW		ｳｨﾝﾄﾞｳ内の再描画を許可または禁止します
//0x000C	WM_SETTEXT			ｳｨﾝﾄﾞｳのテキストを設定します
//0x000D	WM_GETTEXT			ｳｨﾝﾄﾞｳに対応するテキストを取得します
//0x000E	WM_GETTEXTLENGTH	ｳｨﾝﾄﾞｳに関連付けられているテキストの長さを取得します
//0x000F	WM_PAINT			ｳｨﾝﾄﾞｳのｸﾗｲｱﾝﾄ領域を描画する必要があることを示します
//0x0010	WM_CLOSE			コントロール・メニューの[クローズ]コマンドが選ばれました
//0x0011	WM_QUERYENDSESSION	Windowsセッションを終了するよう要求します
//0x0012	WM_QUIT				アプリケーションを強制終了するよう要求します
*/