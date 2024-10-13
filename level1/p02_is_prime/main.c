#include <stdio.h>
int main()
{
	int x;
	int t = 1;
	scanf_s("%d", &x);
	if (x == 1)
	{
		t = 0;
	}
	else if (x == 2) {
		t = 1;
	}
	else if (x >= 3)
	{
		for (int i = 2; i*i < x; i++) 
		{
			if (x%i==0) t = 0;
		}
		
	}
	if (t == 0)printf("不是素数");
	if (t == 1)printf("是素数");
	return 0;

}
