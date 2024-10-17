#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 100
typedef struct Warehouse
{
	int Num;
	char Name[MAX];
	struct Warehouse* next;
}Warehouse;
//显示菜单
void PrintMenu()
{
	printf("********************\n");
	printf("***1.显示存货列表***\n");
	printf("***2.入库 **********\n");
	printf("***3.出库 **********\n");
	printf("***4.退出程序 ******\n");
	printf("********************\n");
}

//初始化
Warehouse* InitWarehouse() {
	Warehouse* head = (Warehouse*)malloc(sizeof(Warehouse));
	head->Num = -1;
	head->next = NULL;
	strcpy_s(head->Name,MAX, "头节点");
	return head;
}

//打开文件并读入，将值赋到结点中
void OpenreadFile(Warehouse*head)
{
	
	FILE* fp = fopen("warehouse.txt", "r");
	if (fp == NULL)
	{
		printf("Error opening file！\n");
		return;
	}
	char name[MAX] = { 0 };
	int num;
	Warehouse* current = head;
	while (fscanf(fp, "%s %d", name,&num)==2)
	{	
		//创建新结点
		Warehouse* newgoods = (Warehouse*)malloc(sizeof(Warehouse));
		newgoods->next = NULL;
		strcpy(newgoods->Name, name);
		newgoods->Num = num;
		//新结点接入链表
		current->next = newgoods;
		current = current->next;
	}
	
	fclose(fp);
}
//1.显示存货列表
void GothroughWarehouse(Warehouse* head)
{
	Warehouse* temp = head->next;
	while (temp) 
	{
		printf("%s %d\n", temp->Name, temp->Num);
		temp = temp->next;
	}
}
//2.入库
void Pushgoods(Warehouse* head)
{
	//找到最后一个结点
	Warehouse* last = head;
	while (last->next)
	{
		last = last->next;
	}
	//创建新节点
	Warehouse* newgoods = (Warehouse*)malloc(sizeof(Warehouse));
	newgoods->next = NULL;
	//用户输入值
	char name[MAX];
	int num;
	printf("请输入你要入库的货物型号：\n");
	scanf("%s", name);
	strcpy(newgoods->Name, name);
	printf("请输入件数：\n");
	scanf("%d", &num);
	newgoods->Num = num;
	//将该结点接入链表
	last->next = newgoods;
}
//3.出库
void Popgoods(Warehouse* head)
{
	char name[MAX];
	printf("请输入要出库的货物型号：\n");
	scanf("%s", name);
	//寻找目标货物并出库
	Warehouse* ahead=head;
	Warehouse* current = ahead->next;

	while (current)
	{
		if (strcmp(current->Name, name) == 0)
		{
			ahead->next = current->next;
			free(current);
			return;
		}
			ahead = current;
			current = current->next;
		
	}
	printf("查无此物！");
}
int main()
{
	Warehouse* head = InitWarehouse();
	OpenreadFile(head);
	while(1)
	{
		system("cls");
		PrintMenu();
		//读入用户选择
		int select;
		printf("请输入操作步数：");
		scanf("%d", &select);
		switch (select)
		{
		case 1://1.显示存货列表
			GothroughWarehouse(head);
			system("pause");
			break;
		case 2://入库
			Pushgoods(head);
			system("pause");
			break;
		case  3://出库
			Popgoods(head);
			system("pause");
			break;
		case 4://退出
			return 0;
			break;
		default:
			printf("输入错误，请重新输入！");
			system("pause");
			break;
		}
	}


	return 0;
}
