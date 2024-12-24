#include<stdio.h>
#define width 10
#define height 10 
int a[height][width];
//���ļ��ж�ȡ�Թ�����ӡ
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
//���ļ����沽��
void Fileinputstep1(int step)
{
	FILE* fp = fopen("mazemaps1.txt", "a");
	fputc('\n', fp);
	fputs("��ʷ��¼��",fp);
	fprintf(fp, "%d", step);
	fputc('\n', fp);
	fclose(fp);
}
void Fileinputstep2(int step)
{
	FILE* fp = fopen("mazemaps2.txt", "a");
	fputc('\n', fp);
	fputs("��ʷ��¼��", fp);
	fprintf(fp, "%d", step);
	fputc('\n', fp);
	fclose(fp);
}

//��ʾ��ͼ����  0:���� 1��ǽ�� 2��person 3������ 4.����
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
	//�û�ѡ��ؿ�
	int select;
	printf("������ؿ���ţ�");
	scanf_s("%d", &select);
	//��ʾ�Թ�
	if(select==1)Filereadmap1();
	if (select == 2)Filereadmap2();
	printmap(m, n);
	while (1)
	{
		system("cls");
		//���µ�ͼ
		printmap(m, n);
		//����ϵͳ��a->����d->���ң�w->���ϣ�s->���£�
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
				printf("��ϲͨ�أ�");
				if (select == 1)Fileinputstep1(step);
				if (select == 2)Fileinputstep2(step);
				goto out;
			}
			break;
		default:printf("����������");
		}
	}
out:
	system("pause");
	return 0;
}