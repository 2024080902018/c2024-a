#include <stdio.h>
#include <stdlib.h>
//创建链表节点结构体
typedef struct Node {
	int value;
	struct Node* next;
}Node;
//初始化链表
Node* InitNode()
{
	//创建头结点
	Node* head = (Node*)malloc(sizeof(Node));

	head->next = NULL;
	head->value = -1;
	//读入输入值
	int item;
	scanf_s("%d", &item);
	do
	{
		scanf_s("%d", &item);
		//找到最后一个结点
		Node* last = head;
		if (head->next != NULL)
		{
			while (last->next)
			{
				last = last->next;
			}
		}
		//创建新结点将值赋给新结点
		Node* newnode = (Node*)malloc(sizeof(Node));
		newnode->value = item;
		newnode->next = NULL;
		last->next = newnode;

	} while (item != -1);
	//返回head
	return head;
}
//遍历显示整个链表
void GothrouhNode(Node* head)
{
	if (head == NULL)printf("链表为空!");
	else
	{
		Node* temp = head;
		while (temp)
		{
			printf("%d ", temp->value);
			temp = temp->next;
		}
		printf("\n");
	}
}

//将链表反序
Node* AntiNode(Node *head)
{
	Node* pre = NULL;
	Node* current = head;
	Node* store=NULL;
	while (current)
	{
		store = current->next;
		current->next = pre;
		pre = current;
		current = store;
	}
	
	return pre;
}

//查找目标值
int SearchNode(Node* head, int goalnum)
{
	int num=1;
	Node* temp = head->next;
	while (temp)
	{
		if (temp->value == goalnum)
		{
			return num;
		}
		temp = temp->next;
		num++;
	}
	return -1;
}
//查找下一个目标值
int SearchagainNode(Node* head, int goalnum)
{
	int num = SearchNode(head, goalnum);
	int num1 = 0;
	if (num != -1)
	{
		Node* temp = head;
		while (temp)
		{
			if (num1 > num && temp->value == goalnum)
			{
				return num1;
				printf("\n");
			}
			temp = temp->next;
			num1++;
		}
		return -1;
	}
	else {
		printf("该链表中无%d\n", goalnum);
		return -1;
	}
}

int main()
{
	//初始化
	Node* head = InitNode();
	GothrouhNode(head);
	//链表反序
	Node* head2 = AntiNode(head);
	GothrouhNode(head2);
	//查找目标值
	int goal;
	scanf_s("%d", &goal);
	int return1 = SearchNode(head2, goal);
	printf("%d\n", return1);
	//继续查找目标值
	int return2 = SearchagainNode(head2, goal);
	printf("%d", return2);
	//释放内存
	free(head);
	return 0;
}
