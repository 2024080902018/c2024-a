#include<stdio.h>
#include<stdlib.h>
void print(char start, char end)
{
	printf("%c->%c\n", start, end);
}
void move(int n, char start, char end, char temp)
{
	if (n == 1) {
		print(start, end);
	}
	else {
		move(n-1, start, temp, end);
		print(start, end);
		move(n-1, temp, end, start);
	}
}

int main()
{
	int n = 64;
	move(n, 'A', 'B', 'C');
	return 0;
}
