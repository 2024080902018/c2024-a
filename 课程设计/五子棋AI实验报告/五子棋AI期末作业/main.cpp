#include"wuziqi.h"
extern IMAGE p;
extern ExMessage msg;
extern int X;//用全局变量来存储落子位置
extern int Y;
extern int a[20][20];


int main()
{
	hint_start();
	int end = 0;
	int deep = DEEP;
	int locate = 0;
	Print_board();
	while (1)
	{
		Player_operate(a);
		//检查是否分出胜负
		end = Check_win(1, a);
		if (end == 1)
		{
			hint(1);
			break;
		}
		//去掉上一个红点标记
		if (locate > 0)
		{
			setfillcolor(WHITE);
			fillcircle(X * 30 + 15, Y * 30 + 15, 10);
		}


		AI_play(a, deep);
		//检查是否分出胜负
		end = Check_win(2, a);
		if (end == 1)
		{
			hint(2);
			break;
		}
		locate++;
	}
	return 0;
}
