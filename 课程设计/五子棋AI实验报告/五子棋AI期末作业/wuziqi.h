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
extern int X;//��ȫ�ֱ������洢����λ��
extern int Y;
extern int a[20][20];
#define NGIF -100000000
#define PTIF  100000000

//���������ṹ��
typedef struct
{
	int Alpha;
	int Beta;
	int data;
	int X;
	int Y;
}Tree;


//��������
void copy(int a[20][20], int c[20][20]);
//��������
void draw(int x, int y, int color);
//��ӡ����
void Print_board();
//�������
void Player_operate(int a[20][20]);
//������ʾ��
void hint(int t);
//������ʼ��Ϸ��ʾ��
void hint_start();


//��������,���ط���Ϊ�������������ȥ��ҷ���
int Score(int color, int a[20][20], int n);
//�ж��ܷ�����  ����ֵΪ1��������  ����ֵΪ-1����������  n=1������ڲ�  n=2��������
int Judge(int a[20][20], int x, int y, int n);
//�����Ӯ
int Check_win(int color, int a[20][20]);
//����С����
int MinMax(int color, int a[20][20], int deep, int Alpha, int Beta);


//���ļ��
int isdfour(int a[20][20], int color, int d_or_l);
//010110ʽ���
int check_010110_010111(int a[20][20], int color);
//���Ź�������ɫΪcolor��������
int calculate(int a[20][20], int color, int x, int y);
//�������
int check_01110(int a[20][20], int color);


//��������
void AI_play(int a[20][20], int deep);