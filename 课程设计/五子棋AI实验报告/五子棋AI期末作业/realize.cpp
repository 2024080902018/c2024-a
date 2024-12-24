#include "wuziqi.h"
IMAGE p;
ExMessage msg;
int X;//用全局变量来存储落子位置
int Y;
int a[20][20];

//复制数组
void copy(int a[20][20], int c[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			c[i][j] = a[i][j];
		}
	}
}

//分数评估，返回分数为color棋子所获分数减去对手分数
int Score(int color, int a[20][20], int n)
{
	//活一：10  活二：100  活三：1000  活四：10000 连五：100000
	//死二：10  死三：100  死四：1000
	int sum = 0;
	int su = 0;
	//点
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (a[i][j] == color)
			{
				for (int k = i - 1; k <= i + 1; k++)
				{
					for (int l = j - 1; l <= j + 1; l++)
					{
						su += a[k][l];
					}
					printf("\n");
				}
				if (su - color == 0 && i != 0 && j != 0 && i != 19 && j != 19)sum += 10;
				su = 0;
			}
		}
	}
	//横向
	su = 0;
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (a[i][j] == color)su += 1;
			else if (su > 1)
			{
				if (a[i][j] == 0 && a[i][j - su - 1] == 0)
				{
					//if (su >= 3)su++;                                             //
					//if (su >= 4)su++;                                               //

					sum += pow(10, su);
					su = 0;
				}
				else if (a[i][j] != 0 && a[i][j - su - 1] != 0)
				{
					if (su == 5)sum += 100000;
					su = 0;
				}
				else
				{
					if (su == 5)sum += 100000;
					else
					{
						//if (su == 4 && n == 1)su += 1;														//
						//if (su == 4 && n == 2)su += 1;														//
						sum += pow(10, su - 1);
						su = 0;
					}
				}
			}

		}
		su = 0;
	}
	//纵向
	su = 0;
	for (int j = 0; j < 20; j++)
	{
		for (int i = 0; i < 20; i++)
		{
			if (a[i][j] == color)su += 1;
			else if (su > 1)
			{
				if (a[i][j] == 0 && a[i - su - 1][j] == 0)
				{
					//if (su >= 3)su++; 											 //
					//if (su >= 4)su++;                                               //
					sum += pow(10, su);
					su = 0;
				}
				else if (a[i][j] != 0 && a[i - su - 1][j] != 0)
				{
					if (su == 5)sum += 100000;
					su = 0;
				}
				else
				{
					if (su == 5)sum += 100000;
					else
					{
						//if (su == 4 && n == 1)su += 1;														//
						//if (su == 4 && n == 2)su += 1;														//
						sum += pow(10, su - 1);
						su = 0;
					}
				}
			}

		}
		su = 0;
	}
	//左下——右上
	su = 0;
	for (int i = -19; i < 20; i++)
	{
		for (int j = 19, k = i; j >= 0; j--, k++)
		{
			if (k >= 0 && k < 20 && j >= 0 && j < 20)
			{
				if (a[k][j] == color)su += 1;
				else if (su > 1)
				{
					if (a[k][j] == 0 && a[k + su + 1][j - su - 1] == 0)
					{
						//if (su >= 3)su++;                                              //
						//if (su >= 4)su++;                                               //
						sum += pow(10, su);
						su = 0;
					}
					else if (a[k][j] != 0 && a[k + su + 1][j - su - 1] != 0)
					{
						if (su == 5)sum += 100000;
						su = 0;
					}
					else
					{
						if (su == 5)sum += 100000;
						else
						{
							//if (su == 4 && n == 1)su += 1;													//
							//if (su == 4 && n == 2)su += 1;														//
							sum += pow(10, su - 1);
							su = 0;
						}
					}
				}
			}

		}
		su = 0;
	}
	//左上——右下
	su = 0;
	for (int j = -19; j < 20; j++)
	{
		for (int i = 0, k = j; i < 20; i++, k++)
		{
			if (k >= 0 && k < 20 && i >= 0 && i < 20)
			{
				if (a[i][k] == color && n == 2)su += 1;
				else if (su > 1)
				{
					if (a[i][k] == 0 && a[i - su - 1][k - su - 1] == 0)
					{
						//if (su >= 3)su++;                                              //
						//if (su >= 4)su++;                                              //
						sum += pow(10, su);
						su = 0;
					}
					else if (a[i][k] != 0 && a[i - su - 1][k - su - 1] != 0)
					{
						if (su == 5)sum += 100000;
						su = 0;
					}
					else
					{
						if (su == 5)sum += 100000;
						else
						{
							//if (su == 4 && n == 1)su += 1;														//
							//if (su == 4 && n == 2)su += 1;														//
							sum += pow(10, su - 1);
							su = 0;
						}
					}
				}

			}

		}
		su = 0;
	}

	if (n == 1 && color == 1)return sum*sum - Score(2, a, 2)*Score(2, a, 2);
	if (n == 1 && color == 2)return sum*sum - Score(1, a, 2)* Score(1, a, 2);
	if (n == 2)return sum;
}
//判断能否下棋  返回值为1：可下棋  返回值为-1：不可下棋  n=1：检查内侧  n=2：检查外侧
int Judge(int a[20][20], int x, int y, int n)
{
	if (a[x][y] != 0)return 0;
	if (n == 1)//检查内侧
	{
		//以a[x][y]为中心的九宫格内若有棋子则可下棋
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i >= 0 && j >= 0 && i < 20 && j < 20 && a[i][j] != 0)return 1;
			}
		}
		return 0;
	}
	else//检查外侧(n=2)
	{
		//以a[x][y]为中心隔了一格的位置若有棋子则可下棋
		for (int i = x - 2; i <= x + 2; i += 2)
		{
			for (int j = y - 2; j <= y + 2; j += 2)
			{
				if (i >= 0 && j >= 0 && i < 20 && j < 20 && a[i][j] != 0)return 1;
			}
		}
		return 0;
	}

}
//检查输赢 返回值为1则已分胜负
int Check_win(int color, int a[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (a[i][j] == color && a[i][j + 1] == color && a[i][j + 2] == color && a[i][j + 3] == color && a[i][j + 4] == color)
			{
				printf("玩家%d获胜", color);
				return 1;
			}
			if (a[i][j] == color && a[i + 1][j + 1] == color && a[i + 2][j + 2] == color && a[i + 3][j + 3] == color && a[i + 4][j + 4] == color)
			{
				printf("玩家%d获胜", color);
				return 1;
			}
			if (a[i][j] == color && a[i + 1][j] == color && a[i + 2][j] == color && a[i + 3][j] == color && a[i + 4][j] == color)
			{
				printf("玩家%d获胜", color);
				return 1;
			}
			if (a[i][j] == color && a[i - 1][j + 1] == color && a[i - 2][j + 2] == color && a[i - 3][j + 3] == color && a[i - 4][j + 4] == color)
			{
				printf("玩家%d获胜", color);
				return 1;
			}

		}
	}
	return 0;
}
//极大极小搜索
int MinMax(int color, int a[20][20], int deep, int Alpha, int Beta)
{
	int minmax;//储存返回的分数
	int c[20][20];//模拟棋盘
	int opponent = 3 - color;//对手
	int n = 0;//用于区分是否为叶子结点
	Tree tree;
	tree.Alpha = Alpha;
	tree.Beta = Beta;
	tree.data = NGIF;
	tree.X = 0;
	tree.Y = 0;
	//deep大于0时递归，等于0时返回评估分数
	if (deep > 0)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (Judge(a, i, j, 1) == 1 && tree.Alpha < tree.Beta)//（judge内侧）α-β剪枝操作
				{
					copy(a, c);//复制得到模拟棋盘
					c[i][j] = color;//模拟棋盘上下棋
					//传递分数
					minmax = MinMax(color, c, deep - 1, tree.Alpha, tree.Beta);
					if (deep % 2 == 0)//MAX层，只改变α的值
					{
						if (n == 0)//若为叶子节点直接传递分数
						{
							tree.data = minmax;
							n++;
						}
						if (tree.Alpha < minmax)//若α小于该分数，更新α，用X、Y来存储对应棋子的坐标系
						{
							tree.Alpha = minmax;
							tree.data = minmax;
							tree.X = i;
							tree.Y = j;
						}
					}
					else//MIN层，只改变β的值
					{
						if (n == 0)//若为叶子节点直接传递分数
						{
							tree.data = minmax;
							n++;
						}
						if (tree.Beta > minmax)//若β大于该分数，更新β，用X、Y来存储对应棋子的坐标系
						{
							tree.Beta = minmax;
							tree.data = minmax;
							tree.X = i;
							tree.Y = j;
						}

					}
				}
			}
		}
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{

				if (Judge(a, i, j, 2) == 1 && tree.Alpha < tree.Beta)//（judge外侧）α-β剪枝操作
				{
					copy(a, c);
					c[i][j] = color;
					minmax = MinMax(color, c, deep - 1, tree.Alpha, tree.Beta);
					if (deep % 2 == 0)//MAX层
					{
						if (tree.Alpha < minmax)
						{
							tree.Alpha = minmax;
							tree.data = minmax;
							tree.X = i;
							tree.Y = j;
						}
					}
					else
					{
						if (tree.Beta > minmax)
						{
							tree.Beta = minmax;
							tree.data = minmax;
							tree.X = i;
							tree.Y = j;
						}
					}
				}
			}
		}

		X = tree.X;//用全局变量来存储落子位置
		Y = tree.Y;
		return tree.data;
	}
	//deep=0时，直接返回分数
	else return Score(color, a, 1);
}
//电脑下棋
void AI_play(int a[20][20], int deep)
{
	if (isdfour(a, 2, 5) == 1)a[X][Y] = 2;//白棋（电脑）活四，直接连五
	else if (isdfour(a, 2, 4) == 1)a[X][Y] = 2;//白棋（电脑）死四，直接连五
	else if (isdfour(a, 1, 4) == 1)a[X][Y] = 2;//黑棋死四，直接堵
	else if (check_010110_010111(a, 2) == 1)a[X][Y] = 2;//白棋（电脑）出现010110或010111则下在中间
	else if (check_010110_010111(a, 1) == 1)a[X][Y] = 2;//黑棋（电脑）出现010110或010111则下在中间
	else if (check_01110(a, 2) == 0 && check_01110(a, 1) == 1)a[X][Y] = 2;
	else
	{
		MinMax(2, a, deep, NGIF, PTIF);
		a[X][Y] = 2;
	}
	draw(X * 30 + 15, Y * 30 + 15, 2);
	setfillcolor(RED);
	fillcircle(X * 30 + 15, Y * 30 + 15, 2);

}

//死or活四检查//检查是否存在color的死or活四，存在则返回1，否则返回0(4为检查死四，5为检查活四)
int isdfour(int a[20][20], int color, int d_or_l)
{
	int t = ((d_or_l == 4) ? 3 - color : 0);
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			if (a[i][j] == t)
			{
				//向上
				if (a[i - 1][j] == color && a[i - 2][j] == color && a[i - 3][j] == color && a[i - 4][j] == color && a[i - 5][j] == 0)
				{
					X = i - 5;
					Y = j;
					return 1;
				}
				//向下
				if (a[i + 1][j] == color && a[i + 2][j] == color && a[i + 3][j] == color && a[i + 4][j] == color && a[i + 5][j] == 0)
				{
					X = i + 5;
					Y = j;
					return 1;
				}
				//向左
				if (a[i][j - 1] == color && a[i][j - 2] == color && a[i][j - 3] == color && a[i][j - 4] == color && a[i][j - 5] == 0)
				{
					X = i;
					Y = j - 5;
					return 1;
				}
				//向右
				if (a[i][j + 1] == color && a[i][j + 2] == color && a[i][j + 3] == color && a[i][j + 4] == color && a[i][j + 5] == 0)
				{
					X = i;
					Y = j + 5;
					return 1;
				}
				//向左上
				if (a[i - 1][j - 1] == color && a[i - 2][j - 2] == color && a[i - 3][j - 3] == color && a[i - 4][j - 4] == color && a[i - 5][j - 5] == 0)
				{
					X = i - 5;
					Y = j - 5;
					return 1;
				}
				//向右下
				if (a[i + 1][j + 1] == color && a[i + 2][j + 2] == color && a[i + 3][j + 3] == color && a[i + 4][j + 4] == color && a[i + 5][j + 5] == 0)
				{
					X = i + 5;
					Y = j + 5;
					return 1;
				}
				//向右上
				if (a[i - 1][j + 1] == color && a[i - 2][j + 2] == color && a[i - 3][j + 3] == color && a[i - 4][j + 4] == color && a[i - 5][j + 5] == 0)
				{
					X = i - 5;
					Y = j + 5;
					return 1;
				}
				//向左下
				if (a[i + 1][j - 1] == color && a[i + 2][j - 2] == color && a[i + 3][j - 3] == color && a[i + 4][j - 4] == color && a[i + 5][j - 5] == 0)
				{
					X = i + 5;
					Y = j - 5;
					return 1;
				}


			}
		}
	}
	return 0;
}
//010110/010111式检查
int check_010110_010111(int a[20][20], int color)
{
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			if (a[i][j] != 3 - color)
			{
				//向上
				if (a[i - 1][j] == color && a[i - 2][j] == 0 && a[i - 3][j] == color && a[i - 4][j] == color && a[i - 5][j] != 3 - color)
				{
					X = i - 2;
					Y = j;
					return 1;
				}
				if (a[i - 1][j] == color && a[i - 2][j] == color && a[i - 3][j] == 0 && a[i - 4][j] == color && a[i - 5][j] == 0)
				{
					X = i - 3;
					Y = j;
					return 1;
				}

				//向下
				if (a[i + 1][j] == color && a[i + 2][j] == 0 && a[i + 3][j] == color && a[i + 4][j] == color && a[i + 5][j] != 3 - color)
				{
					X = i + 2;
					Y = j;
					return 1;
				}
				if (a[i + 1][j] == color && a[i + 2][j] == color && a[i + 3][j] == 0 && a[i + 4][j] == color && a[i + 5][j] == 0)
				{
					X = i + 3;
					Y = j;
					return 1;
				}
				//向左
				if (a[i][j - 1] == color && a[i][j - 2] == 0 && a[i][j - 3] == color && a[i][j - 4] == color && a[i][j - 5] != 3 - color)
				{
					X = i;
					Y = j - 2;
					return 1;
				}
				if (a[i][j - 1] == color && a[i][j - 2] == color && a[i][j - 3] == 0 && a[i][j - 4] == color && a[i][j - 5] == 0)
				{
					X = i;
					Y = j - 3;
					return 1;
				}
				//向右
				if (a[i][j + 1] == color && a[i][j + 2] == 0 && a[i][j + 3] == color && a[i][j + 4] == color && a[i][j + 5] != 3 - color)
				{
					X = i;
					Y = j + 2;
					return 1;
				}
				if (a[i][j + 1] == color && a[i][j + 2] == color && a[i][j + 3] == 0 && a[i][j + 4] == color && a[i][j + 5] == 0)
				{
					X = i;
					Y = j + 3;
					return 1;
				}

				//向左上
				if (a[i - 1][j - 1] == color && a[i - 2][j - 2] == 0 && a[i - 3][j - 3] == color && a[i - 4][j - 4] == color && a[i - 5][j - 5] != 3 - color)
				{
					X = i - 2;
					Y = j - 2;
					return 1;
				}
				if (a[i - 1][j - 1] == color && a[i - 2][j - 2] == color && a[i - 3][j - 3] == 0 && a[i - 4][j - 4] == color && a[i - 5][j - 5] == 0)
				{
					X = i - 3;
					Y = j - 3;
					return 1;
				}

				//向右下
				if (a[i + 1][j + 1] == color && a[i + 2][j + 2] == 0 && a[i + 3][j + 3] == color && a[i + 4][j + 4] == color && a[i + 5][j + 5] != 3 - color)
				{
					X = i + 2;
					Y = j + 2;
					return 1;
				}
				if (a[i + 1][j + 1] == color && a[i + 2][j + 2] == color && a[i + 3][j + 3] == 0 && a[i + 4][j + 4] == color && a[i + 5][j + 5] == 0)
				{
					X = i + 3;
					Y = j + 3;
					return 1;
				}
				//向右上
				if (a[i - 1][j + 1] == color && a[i - 2][j + 2] == 0 && a[i - 3][j + 3] == color && a[i - 4][j + 4] == color && a[i - 5][j + 5] != 3 - color)
				{
					X = i - 2;
					Y = j + 2;
					return 1;
				}
				if (a[i - 1][j + 1] == color && a[i - 2][j + 2] == color && a[i - 3][j + 3] == 0 && a[i - 4][j + 4] == color && a[i - 5][j + 5] == 0)
				{
					X = i - 3;
					Y = j + 3;
					return 1;
				}
				//向左下
				if (a[i + 1][j - 1] == color && a[i + 2][j - 2] == 0 && a[i + 3][j - 3] == color && a[i + 4][j - 4] == color && a[i + 5][j - 5] != 3 - color)
				{
					X = i + 2;
					Y = j - 2;
					return 1;
				}
				if (a[i + 1][j - 1] == color && a[i + 2][j - 2] == color && a[i + 3][j - 3] == 0 && a[i + 4][j - 4] == color && a[i + 5][j - 5] == 0)
				{
					X = i + 3;
					Y = j - 3;
					return 1;
				}


			}
		}
	}
	return 0;
}

//检查16宫格内颜色为color的棋子数
int calculate(int a[20][20], int color, int x, int y)
{
	int sum = 0;
	for (int i = x - 2; i <= x + 2; i++)
	{
		for (int j = y - 2; j <= y + 2; j++)
		{
			if (a[i][j] == color)sum++;
		}
	}
	return sum;
}

//活三检查进攻
int check_01110(int a[20][20], int color)
{
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			if (a[i][j] == 0)
			{
				//向上
				if (a[i - 1][j] == color && a[i - 2][j] == color && a[i - 3][j] == color && a[i - 4][j] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i - 4, j) ? i : i - 4);
					Y = j;
					return 1;
				}
				//向下
				if (a[i + 1][j] == color && a[i + 2][j] == color && a[i + 3][j] == color && a[i + 4][j] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i + 4, j) ? i : i + 4);
					Y = j;
					return 1;
				}
				//向左
				if (a[i][j - 1] == color && a[i][j - 2] == color && a[i][j - 3] == color && a[i][j - 4] == 0)
				{
					X = i;
					Y = (calculate(a, color, i, j) > calculate(a, color, i, j - 4) ? j : j - 4);
					return 1;
				}
				//向右
				if (a[i][j + 1] == color && a[i][j + 2] == color && a[i][j + 3] == color && a[i][j + 4] == 0)
				{
					X = i;
					Y = (calculate(a, color, i, j) > calculate(a, color, i, j + 4) ? j : j + 4);
					return 1;
				}
				//向左上
				if (a[i - 1][j - 1] == color && a[i - 2][j - 2] == color && a[i - 3][j - 3] == color && a[i - 4][j - 4] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i - 4, j - 4) ? i : i - 4);
					Y = (calculate(a, color, i, j) > calculate(a, color, i - 4, j - 4) ? j : j - 4);
					return 1;
				}
				//向右下
				if (a[i + 1][j + 1] == color && a[i + 2][j + 2] == color && a[i + 3][j + 3] == color && a[i + 4][j + 4] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i + 4, j + 4) ? i : i + 4);
					Y = (calculate(a, color, i, j) > calculate(a, color, i + 4, j + 4) ? j : j + 4);
					return 1;
				}
				//向右上
				if (a[i - 1][j + 1] == color && a[i - 2][j + 2] == color && a[i - 3][j + 3] == color && a[i - 4][j + 4] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i - 4, j + 4) ? i : i - 4);
					Y = (calculate(a, color, i, j) > calculate(a, color, i - 4, j + 4) ? j : j + 4);
					return 1;
				}
				//向左下
				if (a[i + 1][j - 1] == color && a[i + 2][j - 2] == color && a[i + 3][j - 3] == color && a[i + 4][j - 4] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i + 4, j - 4) ? i : i + 4);
					Y = (calculate(a, color, i, j) > calculate(a, color, i + 4, j - 4) ? j : j - 4);
					return 1;
				}

			}
		}
	}
	return 0;
}
