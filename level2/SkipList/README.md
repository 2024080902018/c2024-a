### 题目：SkipList
#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define MAX_LEVEL 10
#define MAX_RAND_N 1000000
//跳表中的一个结点代表的链中的结点
typedef struct Node 
{
	int key, level;
	struct Node* up;
	struct Node* down;
	struct Node* next;

}Node;
//跳表：头指针，尾指针，最高层数
typedef struct Skiplist
{
	Node* head;
	Node* tail;
	int max_level;

}Skiplist;

//初始化跳表中的一个具有n层结构的节点
Node* Init_newnodes(int key, int n)//储存数据为key，层数为n
{
	Node* nodes = (Node*)malloc(sizeof(Node) * n);
	for (int i = 0; i < n; i++)
	{
		nodes[i].level = i;
		nodes[i].key = key;
		nodes[i].next = NULL;
		nodes[i].down = (i > 0 ? nodes + i - 1 : NULL);
		nodes[i].up = (i + 1 < n ? nodes + i + 1 : NULL);

	}
	return nodes + n - 1;//返回列顶的地址指针
}

//初始化跳表（此时只有头尾两个具有max_level层的节点）
Skiplist* Init_Skiplist(int n)
{
	Skiplist* s = (Skiplist*)malloc(sizeof(Skiplist));
	s->head = Init_newnodes(INT_MIN, n);
	s->tail = Init_newnodes(INT_MAX, n);
	s->max_level = n;
	Node* p = s->head;
	Node* q = s->tail;
	while (p)
	{
		p->next = q;
		p = p->down;
		q = q->down;
	}
	while (s->head->level != 0)s->head = s->head->down;
	return s;
}

//随即生成层数
int randLevel(Skiplist* s)
{
	
	int level = rand() % MAX_LEVEL + 1;
	if (rand() * 1.0 / RAND_MAX < 0.2 && level>5)
		return level - 5;
	else return level;
}

//插入
void insert(Skiplist* s,int key)
{
	//创建newnodes来存储key值生成随机层高
	int level = randLevel(s);
	printf("rand level=%d\n", level);
	Node* newnodes = Init_newnodes(key, level);
	//若head所在层高小于随机层高，则上移（只上不下）
	while (s->head->level < level - 1)s->head = s->head->up;//保证s->head层数与最高newnodes[level-1]->level齐平
	//将操作节点p移到与随机层高齐平
	Node* p = s->head;
	printf("insert begins:\n");
	while (p->level > newnodes->level)p = p->down;
	
	//将newnodes与前后节点相连
	while (p)
	{//找到第一个比key值大的点前即为插入点
		while (p->next->key <= key)p = p->next;																		//?????
		newnodes->next = p->next;
		p->next = newnodes;
		p = p->down;
		newnodes = newnodes->down;
	}
}


//输出跳表
void output(Skiplist* s )
{
	Node* p = s->head;
	while (p->level>0)p = p->down;//将p指针移动到第0层
	p = p->next;//p移动到第一个数值的第0层
	while (p->key != INT_MAX)
	{
		Node* q = p;
		while (q != NULL)
		{
			printf("%4d", q->key);
			q = q->up;
		}
		printf("\n");
		p = p->next;
	}
	return;
}
//查找(返回值为该值最上层节点)
Node* find(Skiplist* s, int x)
{
	Node* p = s->head;
	while (p)
	{
		if (p->next->key > x)p = p->down;
		else if (p->next->key < x)p = p->next;
		else if (p->next->key==x)return p->next;
	}
	printf("Don't exist!\n");
	return NULL;

}
//删除
void delet(Skiplist* s, int x)
{
	Node* p = s->head;
	Node* q = find(s, x);
	if (q == NULL)return;
	while (1)
	{
		if (p->next->key > x)p = p->down;
		else if (p->next->key < x)p = p->next;
		else if (p->next->key == x)
		{
			while (p != NULL)
			{
				p->next = p->next->next;
				p = p->down;
			}
			break;
		}
	}
	printf("delet done!\n");
}

//清空跳表
void clear_Skiplist(Skiplist* s)
{
	Node* p = s->head->next;
	while (p->level > 0)p = p->down;
	while (p->key!=INT_MAX)
	{
		Node* q = p->next;
		free(p);
		p = q;
	}
	printf("clear done!");
	return;
}

int main()
{
	srand(time(0));
	Skiplist* s = Init_Skiplist(MAX_LEVEL+1);
	while (1)
	{
		printf("\n");
		int key;
		scanf("%d", &key);
		if (key == -1)break;
		insert(s, key);
		output(s);
	}
	//查找
	printf("The found key is：\n");
	int x;
	scanf("%d", &x);
	Node* res = find(s, x);
	if (res != NULL)
	{
		printf("Find result:\n");
		printf("key=%d,level=%d\n", res->key, res->level+1);
	}
	//删除
	printf("The delet key:\n");
	int y;
	scanf("%d", &y);
	delet(s, y);
	output(s);

	//清空
	clear_Skiplist(s);
	return 0;
}
### 功能要求：

1. 实现[SkipList算法](https://zhuanlan.zhihu.com/p/33674267)；
