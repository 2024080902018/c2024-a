#include "wuziqi.h"
#pragma comment(lib,"Winmm.lib")																		//

extern IMAGE p;
extern ExMessage msg;
extern int X;//��ȫ�ֱ������洢����λ��
extern int Y;
extern int a[20][20];

//��ӡ���̲���������
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
//�����Ӳ�����������Ч
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
//��Ҳ���
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
//������ʾ��
void hint(int t)
{
	HWND hnd = GetHWnd();
	SetWindowText(hnd, TEXT("������"));
	int isok;
	if (t == 1)isok = MessageBox(NULL, TEXT("����ʤ"), TEXT("��ʾ"), MB_OKCANCEL);
	else if (t == 2)isok = MessageBox(NULL, TEXT("����ʤ"), TEXT("��ʾ"), MB_OKCANCEL);
	if (IDOK == isok)
	{
		exit(0);
	}
	else if (IDCANCEL == isok)
	{
		exit(0);
	}

}
//������ʼ��Ϸ��ʾ��
void hint_start()
{
	HWND hnd = GetHWnd();
	SetWindowText(hnd, TEXT("������С��Ϸ"));
	int isok;
	isok = MessageBox(NULL, TEXT("���ȷ����ʼ��Ϸ,���ȡ���˳���Ϸ"), TEXT("��ӭ����������AIС��Ϸ"), MB_OKCANCEL);
	if (IDOK == isok)
	{

	}
	else if (IDCANCEL == isok)
	{
		exit(0);
	}

}
