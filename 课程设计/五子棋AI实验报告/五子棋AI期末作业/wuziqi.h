#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<Windows.h>
#include<math.h>
#include<graphics.h>
#include <tchar.h>
#define DEEP 2
extern IMAGE p;
extern ExMessage msg;
extern int X;//用全局变量来存储落子位置
extern int Y;
extern int a[20][20];
#define NGIF -100000000
#define PTIF  100000000

//构建树结点结构体
typedef struct
{
	int Alpha;
	int Beta;
	int data;
	int X;
	int Y;
}Tree;


//复制数组
void copy(int a[20][20], int c[20][20]);
//绘制棋子
void draw(int x, int y, int color);
//打印棋盘
void Print_board();
//玩家下棋
void Player_operate(int a[20][20]);
//弹出提示框
void hint(int t);
//弹出开始游戏提示框
void hint_start();


//分数评估,返回分数为电脑所获分数减去玩家分数
int Score(int color, int a[20][20], int n);
//判断能否下棋  返回值为1：可下棋  返回值为-1：不可下棋  n=1：检查内侧  n=2：检查外侧
int Judge(int a[20][20], int x, int y, int n);
//检查输赢
int Check_win(int color, int a[20][20]);
//极大极小搜索
int MinMax(int color, int a[20][20], int deep, int Alpha, int Beta);


//死四检查
int isdfour(int a[20][20], int color, int d_or_l);
//010110式检查
int check_010110_010111(int a[20][20], int color);
//检查九宫格内颜色为color的棋子数
int calculate(int a[20][20], int color, int x, int y);
//活三检查
int check_01110(int a[20][20], int color);


//电脑下棋
void AI_play(int a[20][20], int deep);