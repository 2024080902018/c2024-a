#include<stdio.h>
#define width 10
#define height 10 
int a[height][width];
//从文件中读取迷宫并打印
void Filereadmap1() 
{
		FILE* fp = fopen("mazemaps1.txt", "r");
	
	if (fp == NULL)
	{
		perror("Error opening file: ");
		return;
	}
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				if (!feof(fp)) 
				{
					int t;
				fscanf_s(fp, "%d", &t);
				a[i][j] = t;
				}

			}
		}

		fclose(fp);
		return;
}
void Filereadmap2()
{
	FILE* fp = fopen("mazemaps2.txt", "r");

	if (fp == NULL)
	{
		perror("Error opening file: ");
		return;
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			if (!feof(fp))
			{
				int t;
				fscanf_s(fp, "%d", &t);
				a[i][j] = t;
			}

		}
	}

	fclose(fp);
	return;
}
//向文件保存步数
void Fileinputstep1(int step)
{
	FILE* fp = fopen("mazemaps1.txt", "a");
	fputc('\n', fp);
	fputs("历史记录：",fp);
	fprintf(fp, "%d", step);
	fputc('\n', fp);
	fclose(fp);
}
void Fileinputstep2(int step)
{
	FILE* fp = fopen("mazemaps2.txt", "a");
	fputc('\n', fp);
	fputs("历史记录：", fp);
	fprintf(fp, "%d", step);
	fputc('\n', fp);
	fclose(fp);
}

//显示地图函数  0:可行 1：墙壁 2：person 3：出口 4.箱子
void printmap(int m, int n)
{
	int i, j;
	for (i = 0; i < height; i++)
	{
		for (j = 0; j < width; j++)
		{
			if (i == m && j == n) {
				printf("O");
			}
			else if (a[i][j] == 0 || a[i][j] == 3) {
				printf(" ");
			}
			else if (a[i][j] == 1) {
				printf("#");
			}
			else if (a[i][j] == 4) {
				printf("*");
			}
		}
		printf("\n");
	}
}
int main() {
	char str;
	int m = 1;
	int n = 8;
	int step = 0;
	//用户选择关卡
	int select;
	printf("请输入关卡序号：");
	scanf_s("%d", &select);
	//显示迷宫
	if(select==1)Filereadmap1();
	if (select == 2)Filereadmap2();
	printmap(m, n);
	while (1)
	{
		system("cls");
		//更新地图
		printmap(m, n);
		//操作系统：a->向左；d->向右；w->向上；s->向下；
		scanf_s("%s", &str, 10);
		step++;
		switch (str)
		{
		case 'a':
			if (a[m][n - 1] == 0)
			{
				int temp = a[m][n];
				a[m][n] = a[m][n - 1];
				a[m][n - 1] = temp;
				n--;
			}
			else if (a[m][n - 1] == 4 && a[m][n - 2] == 0)
			{

				a[m][n - 2] = 4;
				a[m][n - 1] = 2;
				a[m][n] = 0;
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
			else if (a[m][n + 1] == 4 && a[m][n + 2] == 0)
			{
				a[m][n + 2] = 4;
				a[m][n + 1] = 2;
				a[m][n] = 0;
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
			else if (a[m - 1][n] == 4 && a[m - 2][n] == 0)
			{
				a[m - 2][n] = 4;
				a[m - 1][n] = 2;
				a[m][n] = 0;
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
			else if (a[m + 1][n] == 4 && a[m + 2][n] == 0)
			{
				a[m][n] = 0;
				a[m + 1][n] = 2;
				a[m + 2][n] = 4;
				m++;
			}
			else if (a[m + 1][n] == 4 && a[m + 2][n] == 3)
			{
				printf("恭喜通关！");
				if (select == 1)Fileinputstep1(step);
				if (select == 2)Fileinputstep2(step);
				goto out;
			}
			break;
		default:printf("请重新输入");
		}
	}
out:
	system("pause");
	return 0;
}
