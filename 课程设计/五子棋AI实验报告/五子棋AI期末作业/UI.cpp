#include "wuziqi.h"
#pragma comment(lib,"Winmm.lib")																		//

extern IMAGE p;
extern ExMessage msg;
extern int X;//用全局变量来存储落子位置
extern int Y;
extern int a[20][20];

//打印棋盘并播放音乐
void Print_board()
{
	initgraph(600, 600);
	loadimage(&p, _T("background.png"), 600, 600);
	putimage(0, 0, &p);

	mciSendString(_T("open background.MP3 alias mymusic"), NULL, 0, NULL);
	mciSendString(_T("play mymusic"), NULL, 0, NULL);

	setlinecolor(BLACK);
	for (int x = 15; x < 600; x += 30)
	{
		line(x, 15, x, 585);
	}
	for (int y = 15; y <= 585; y += 30)
	{
		line(15, y, 585, y);
	}
	setfillcolor(BLACK);
	fillcircle(15 + 5 * 30, 15 + 5 * 30, 3);
	fillcircle(15 + 5 * 30, 15 + 15 * 30, 3);
	fillcircle(15 + 15 * 30, 15 + 5 * 30, 3);
	fillcircle(15 + 15 * 30, 15 + 15 * 30, 3);
	fillcircle(15 + 10 * 30, 15 + 10 * 30, 3);

}
//画棋子并设置落子音效
void draw(int x, int y, int color)
{
	mciSendString(_T("stop mymusic1"), NULL, 0, NULL);
	mciSendString(_T("close mymusic1"), NULL, 0, NULL);
	mciSendString(_T("open playchess.mp3 alias mymusic1"), NULL, 0, NULL);
	mciSendString(_T("play mymusic1"), NULL, 0, NULL);
	Sleep(50);

	if (color == 1)setfillcolor(BLACK);
	if (color == 2)setfillcolor(WHITE);
	fillcircle((x / 30) * 30 + 15, (y / 30) * 30 + 15, 10);
}
//玩家操作
void Player_operate(int a[20][20])
{
	while (1)
	{
		if (peekmessage(&msg, EX_MOUSE))
		{
			switch (msg.message)
			{
			case WM_LBUTTONDOWN:
			{
				if (a[msg.x / 30][msg.y / 30] != 0)break;
				draw(msg.x, msg.y, 1);
				a[msg.x / 30][msg.y / 30] = 1;
				goto out;
			}
			}
		}
	}
out:
	return;
}
//弹出提示框
void hint(int t)
{
	HWND hnd = GetHWnd();
	SetWindowText(hnd, TEXT("五子棋"));
	int isok;
	if (t == 1)isok = MessageBox(NULL, TEXT("黑子胜"), TEXT("提示"), MB_OKCANCEL);
	else if (t == 2)isok = MessageBox(NULL, TEXT("白子胜"), TEXT("提示"), MB_OKCANCEL);
	if (IDOK == isok)
	{
		exit(0);
	}
	else if (IDCANCEL == isok)
	{
		exit(0);
	}

}
//弹出开始游戏提示框
void hint_start()
{
	HWND hnd = GetHWnd();
	SetWindowText(hnd, TEXT("五子棋小游戏"));
	int isok;
	isok = MessageBox(NULL, TEXT("点击确定开始游戏,点击取消退出游戏"), TEXT("欢迎来到五子棋AI小游戏"), MB_OKCANCEL);
	if (IDOK == isok)
	{

	}
	else if (IDCANCEL == isok)
	{
		exit(0);
	}

}
