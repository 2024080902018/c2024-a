#include<stdio.h>
#include<string.h>
#define SHIFT 5
#define MAX 100
//加密函数
void encrypt(char str[MAX])
{
	printf("加密密码为：");
	for (int i = 0; i < strlen(str); i++)
	{
		str[i] += 5;
		printf("%c", str[i]);
	}
	printf("\n");
}
//解密函数
void decrypt(char str[MAX])
{
	printf("解密密码为：");
	for (int j = 0; j < strlen(str); j++)
	{
		str[j] -= 5;
		printf("%c", str[j]);
	}
	printf("\n");
}
int main()
{
	char str[100] = { 0 };
	//请输入原密码
	scanf_s("%s", str,MAX);
	//输出加密后字符
	encrypt(str);
	//解密
	decrypt(str);
	return 0;
}
