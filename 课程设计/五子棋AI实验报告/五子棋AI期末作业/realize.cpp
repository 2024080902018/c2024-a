#include "wuziqi.h"
IMAGE p;
ExMessage msg;
int X;//��ȫ�ֱ������洢����λ��
int Y;
int a[20][20];

//��������
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

//�������������ط���Ϊcolor�������������ȥ���ַ���
int Score(int color, int a[20][20], int n)
{
	//��һ��10  �����100  ������1000  ���ģ�10000 ���壺100000
	//������10  ������100  ���ģ�1000
	int sum = 0;
	int su = 0;
	//��
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
	//����
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
	//����
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
	//���¡�������
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
	//���ϡ�������
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
//�ж��ܷ�����  ����ֵΪ1��������  ����ֵΪ-1����������  n=1������ڲ�  n=2��������
int Judge(int a[20][20], int x, int y, int n)
{
	if (a[x][y] != 0)return 0;
	if (n == 1)//����ڲ�
	{
		//��a[x][y]Ϊ���ĵľŹ��������������������
		for (int i = x - 1; i <= x + 1; i++)
		{
			for (int j = y - 1; j <= y + 1; j++)
			{
				if (i >= 0 && j >= 0 && i < 20 && j < 20 && a[i][j] != 0)return 1;
			}
		}
		return 0;
	}
	else//������(n=2)
	{
		//��a[x][y]Ϊ���ĸ���һ���λ�����������������
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
//�����Ӯ ����ֵΪ1���ѷ�ʤ��
int Check_win(int color, int a[20][20])
{
	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if (a[i][j] == color && a[i][j + 1] == color && a[i][j + 2] == color && a[i][j + 3] == color && a[i][j + 4] == color)
			{
				printf("���%d��ʤ", color);
				return 1;
			}
			if (a[i][j] == color && a[i + 1][j + 1] == color && a[i + 2][j + 2] == color && a[i + 3][j + 3] == color && a[i + 4][j + 4] == color)
			{
				printf("���%d��ʤ", color);
				return 1;
			}
			if (a[i][j] == color && a[i + 1][j] == color && a[i + 2][j] == color && a[i + 3][j] == color && a[i + 4][j] == color)
			{
				printf("���%d��ʤ", color);
				return 1;
			}
			if (a[i][j] == color && a[i - 1][j + 1] == color && a[i - 2][j + 2] == color && a[i - 3][j + 3] == color && a[i - 4][j + 4] == color)
			{
				printf("���%d��ʤ", color);
				return 1;
			}

		}
	}
	return 0;
}
//����С����
int MinMax(int color, int a[20][20], int deep, int Alpha, int Beta)
{
	int minmax;//���淵�صķ���
	int c[20][20];//ģ������
	int opponent = 3 - color;//����
	int n = 0;//���������Ƿ�ΪҶ�ӽ��
	Tree tree;
	tree.Alpha = Alpha;
	tree.Beta = Beta;
	tree.data = NGIF;
	tree.X = 0;
	tree.Y = 0;
	//deep����0ʱ�ݹ飬����0ʱ������������
	if (deep > 0)
	{
		for (int i = 0; i < 20; i++)
		{
			for (int j = 0; j < 20; j++)
			{
				if (Judge(a, i, j, 1) == 1 && tree.Alpha < tree.Beta)//��judge�ڲࣩ��-�¼�֦����
				{
					copy(a, c);//���Ƶõ�ģ������
					c[i][j] = color;//ģ������������
					//���ݷ���
					minmax = MinMax(color, c, deep - 1, tree.Alpha, tree.Beta);
					if (deep % 2 == 0)//MAX�㣬ֻ�ı����ֵ
					{
						if (n == 0)//��ΪҶ�ӽڵ�ֱ�Ӵ��ݷ���
						{
							tree.data = minmax;
							n++;
						}
						if (tree.Alpha < minmax)//����С�ڸ÷��������¦�����X��Y���洢��Ӧ���ӵ�����ϵ
						{
							tree.Alpha = minmax;
							tree.data = minmax;
							tree.X = i;
							tree.Y = j;
						}
					}
					else//MIN�㣬ֻ�ı�µ�ֵ
					{
						if (n == 0)//��ΪҶ�ӽڵ�ֱ�Ӵ��ݷ���
						{
							tree.data = minmax;
							n++;
						}
						if (tree.Beta > minmax)//���´��ڸ÷��������¦£���X��Y���洢��Ӧ���ӵ�����ϵ
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

				if (Judge(a, i, j, 2) == 1 && tree.Alpha < tree.Beta)//��judge��ࣩ��-�¼�֦����
				{
					copy(a, c);
					c[i][j] = color;
					minmax = MinMax(color, c, deep - 1, tree.Alpha, tree.Beta);
					if (deep % 2 == 0)//MAX��
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

		X = tree.X;//��ȫ�ֱ������洢����λ��
		Y = tree.Y;
		return tree.data;
	}
	//deep=0ʱ��ֱ�ӷ��ط���
	else return Score(color, a, 1);
}
//��������
void AI_play(int a[20][20], int deep)
{
	if (isdfour(a, 2, 5) == 1)a[X][Y] = 2;//���壨���ԣ����ģ�ֱ������
	else if (isdfour(a, 2, 4) == 1)a[X][Y] = 2;//���壨���ԣ����ģ�ֱ������
	else if (isdfour(a, 1, 4) == 1)a[X][Y] = 2;//�������ģ�ֱ�Ӷ�
	else if (check_010110_010111(a, 2) == 1)a[X][Y] = 2;//���壨���ԣ�����010110��010111�������м�
	else if (check_010110_010111(a, 1) == 1)a[X][Y] = 2;//���壨���ԣ�����010110��010111�������м�
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

//��or���ļ��//����Ƿ����color����or���ģ������򷵻�1�����򷵻�0(4Ϊ������ģ�5Ϊ������)
int isdfour(int a[20][20], int color, int d_or_l)
{
	int t = ((d_or_l == 4) ? 3 - color : 0);
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			if (a[i][j] == t)
			{
				//����
				if (a[i - 1][j] == color && a[i - 2][j] == color && a[i - 3][j] == color && a[i - 4][j] == color && a[i - 5][j] == 0)
				{
					X = i - 5;
					Y = j;
					return 1;
				}
				//����
				if (a[i + 1][j] == color && a[i + 2][j] == color && a[i + 3][j] == color && a[i + 4][j] == color && a[i + 5][j] == 0)
				{
					X = i + 5;
					Y = j;
					return 1;
				}
				//����
				if (a[i][j - 1] == color && a[i][j - 2] == color && a[i][j - 3] == color && a[i][j - 4] == color && a[i][j - 5] == 0)
				{
					X = i;
					Y = j - 5;
					return 1;
				}
				//����
				if (a[i][j + 1] == color && a[i][j + 2] == color && a[i][j + 3] == color && a[i][j + 4] == color && a[i][j + 5] == 0)
				{
					X = i;
					Y = j + 5;
					return 1;
				}
				//������
				if (a[i - 1][j - 1] == color && a[i - 2][j - 2] == color && a[i - 3][j - 3] == color && a[i - 4][j - 4] == color && a[i - 5][j - 5] == 0)
				{
					X = i - 5;
					Y = j - 5;
					return 1;
				}
				//������
				if (a[i + 1][j + 1] == color && a[i + 2][j + 2] == color && a[i + 3][j + 3] == color && a[i + 4][j + 4] == color && a[i + 5][j + 5] == 0)
				{
					X = i + 5;
					Y = j + 5;
					return 1;
				}
				//������
				if (a[i - 1][j + 1] == color && a[i - 2][j + 2] == color && a[i - 3][j + 3] == color && a[i - 4][j + 4] == color && a[i - 5][j + 5] == 0)
				{
					X = i - 5;
					Y = j + 5;
					return 1;
				}
				//������
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
//010110/010111ʽ���
int check_010110_010111(int a[20][20], int color)
{
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			if (a[i][j] != 3 - color)
			{
				//����
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

				//����
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
				//����
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
				//����
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

				//������
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

				//������
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
				//������
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
				//������
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

//���16��������ɫΪcolor��������
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

//����������
int check_01110(int a[20][20], int color)
{
	for (int i = 0; i <= 19; i++)
	{
		for (int j = 0; j <= 19; j++)
		{
			if (a[i][j] == 0)
			{
				//����
				if (a[i - 1][j] == color && a[i - 2][j] == color && a[i - 3][j] == color && a[i - 4][j] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i - 4, j) ? i : i - 4);
					Y = j;
					return 1;
				}
				//����
				if (a[i + 1][j] == color && a[i + 2][j] == color && a[i + 3][j] == color && a[i + 4][j] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i + 4, j) ? i : i + 4);
					Y = j;
					return 1;
				}
				//����
				if (a[i][j - 1] == color && a[i][j - 2] == color && a[i][j - 3] == color && a[i][j - 4] == 0)
				{
					X = i;
					Y = (calculate(a, color, i, j) > calculate(a, color, i, j - 4) ? j : j - 4);
					return 1;
				}
				//����
				if (a[i][j + 1] == color && a[i][j + 2] == color && a[i][j + 3] == color && a[i][j + 4] == 0)
				{
					X = i;
					Y = (calculate(a, color, i, j) > calculate(a, color, i, j + 4) ? j : j + 4);
					return 1;
				}
				//������
				if (a[i - 1][j - 1] == color && a[i - 2][j - 2] == color && a[i - 3][j - 3] == color && a[i - 4][j - 4] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i - 4, j - 4) ? i : i - 4);
					Y = (calculate(a, color, i, j) > calculate(a, color, i - 4, j - 4) ? j : j - 4);
					return 1;
				}
				//������
				if (a[i + 1][j + 1] == color && a[i + 2][j + 2] == color && a[i + 3][j + 3] == color && a[i + 4][j + 4] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i + 4, j + 4) ? i : i + 4);
					Y = (calculate(a, color, i, j) > calculate(a, color, i + 4, j + 4) ? j : j + 4);
					return 1;
				}
				//������
				if (a[i - 1][j + 1] == color && a[i - 2][j + 2] == color && a[i - 3][j + 3] == color && a[i - 4][j + 4] == 0)
				{
					X = (calculate(a, color, i, j) > calculate(a, color, i - 4, j + 4) ? i : i - 4);
					Y = (calculate(a, color, i, j) > calculate(a, color, i - 4, j + 4) ? j : j + 4);
					return 1;
				}
				//������
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
