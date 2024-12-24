#include <stdio.h>
#include <stdlib.h>
#include<limits.h>
#define MAX_LEVEL 10
#define MAX_RAND_N 1000000
//�����е�һ������������еĽ��
typedef struct Node 
{
	int key, level;
	struct Node* up;
	struct Node* down;
	struct Node* next;

}Node;
//����ͷָ�룬βָ�룬��߲���
typedef struct Skiplist
{
	Node* head;
	Node* tail;
	int max_level;

}Skiplist;

//��ʼ�������е�һ������n��ṹ�Ľڵ�
Node* Init_newnodes(int key, int n)//��������Ϊkey������Ϊn
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
	return nodes + n - 1;//�����ж��ĵ�ַָ��
}

//��ʼ��������ʱֻ��ͷβ��������max_level��Ľڵ㣩
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

//�漴���ɲ���
int randLevel(Skiplist* s)
{
	
	int level = rand() % MAX_LEVEL + 1;
	if (rand() * 1.0 / RAND_MAX < 0.2 && level>5)
		return level - 5;
	else return level;
}

//����
void insert(Skiplist* s,int key)
{
	//����newnodes���洢keyֵ����������
	int level = randLevel(s);
	printf("rand level=%d\n", level);
	Node* newnodes = Init_newnodes(key, level);
	//��head���ڲ��С�������ߣ������ƣ�ֻ�ϲ��£�
	while (s->head->level < level - 1)s->head = s->head->up;//��֤s->head���������newnodes[level-1]->level��ƽ
	//�������ڵ�p�Ƶ�����������ƽ
	Node* p = s->head;
	printf("insert begins:\n");
	while (p->level > newnodes->level)p = p->down;
	
	//��newnodes��ǰ��ڵ�����
	while (p)
	{//�ҵ���һ����keyֵ��ĵ�ǰ��Ϊ�����
		while (p->next->key <= key)p = p->next;																		//?????
		newnodes->next = p->next;
		p->next = newnodes;
		p = p->down;
		newnodes = newnodes->down;
	}
}


//�������
void output(Skiplist* s )
{
	Node* p = s->head;
	while (p->level>0)p = p->down;//��pָ���ƶ�����0��
	p = p->next;//p�ƶ�����һ����ֵ�ĵ�0��
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
//����(����ֵΪ��ֵ���ϲ�ڵ�)
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
//ɾ��
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

//�������
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
	//����
	printf("The found key is��\n");
	int x;
	scanf("%d", &x);
	Node* res = find(s, x);
	if (res != NULL)
	{
		printf("Find result:\n");
		printf("key=%d,level=%d\n", res->key, res->level+1);
	}
	//ɾ��
	printf("The delet key:\n");
	int y;
	scanf("%d", &y);
	delet(s, y);
	output(s);

	//���
	clear_Skiplist(s);
	return 0;
}