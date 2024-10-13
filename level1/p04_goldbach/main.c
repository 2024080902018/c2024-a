#include <stdio.h>
int a[5000] = { 0 };

//判断素数 
int isPrime(int x) {
	int t = 1;
	if (x == 1)t = 0;
	else if (x == 2)t = 1;
	else {
		for (int i = 2; i * i <= x; i++) {
			if (x % i == 0)t = 0;
		}
	}
	return t;
}

int main() {
	int n = 100;
	int j = 0;
	//给出素数组 
	for (int i = 0; i < n; i++) {
		if (isPrime(i) == 1) {
			a[j] = i;
			j++;
		}
	}

	//给出偶数分法
	for (int t = 4; t <= n; t = t + 2)
	{

		for (int x = 0; x < j + 1; x++)
		{
			for (int y = x; y < j + 1; y++)
			{
				if (a[x] + a[y] == t)
				{
					printf("%d=%d+%d\n", t, a[x], a[y]);
					goto out;
				}
			}
		}
	out:
		continue;
	}
	return 0;
}
