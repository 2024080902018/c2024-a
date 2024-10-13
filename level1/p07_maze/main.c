#include<iostream>
using namespace std;
#include<string>
#define width 10
#define height 10
//创建迷宫
int a[height][width] = {
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,1,0,0,0,2,1},
	{1,0,1,0,1,0,1,1,1,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,1,1,1,1,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,0,1,1},
	{1,0,1,0,0,0,0,0,0,1},
	{1,0,0,0,0,1,0,0,0,1},
	{1,3,1,1,1,1,1,1,1,1}
};
//显示地图函数  0:可行 1：墙壁 2：person 3：出口
void printmap(int m, int n)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (i == m && j == n) {
				cout << "O";
			}
			else if (a[i][j] == 0 || a[i][j] == 3) {
				cout << " ";
			}
			else if (a[i][j] == 1) {
				cout << "#";
			}
		}
		cout << endl;
	}
}
int main() {
	string str;
	int m = 1;
	int n = 8;

	while (1)
	{
		system("cls");
		//更新地图
		printmap(m, n);
		//操作系统：a->向左；d->向右；w->向上；s->向下；
		cin >> str;
		switch (str[0])
		{
		case 'a':
			if (a[m][n - 1] == 0)
			{
				int temp = a[m][n];
				a[m][n] = a[m][n - 1];
				a[m][n - 1] = temp;
				n--;
			}
			break;
		case 'd':
			if (a[m][n + 1] == 0)
			{
				int temp = a[m][n];
				a[m][n] = a[m][n + 1];
				a[m][n + 1] = temp;
				n++;
			}
			break;
		case 'w':
			if (a[m - 1][n] == 0)
			{
				int temp = a[m][n];
				a[m][n] = a[m - 1][n];
				a[m - 1][n] = temp;
				m--;
			}
			break;
		case 's':
			if (a[m + 1][n] == 0)
			{
				int temp = a[m][n];
				a[m][n] = a[m + 1][n];
				a[m + 1][n] = temp;
				m++;
			}
			else if (a[m + 1][n] == 3)
			{
				cout << "恭喜通关！" << endl;
				goto out;
			}
			break;
		default:cout << "请重新输入" << endl;
		}
	}
out:

	return 0;
}
