#include <stdio.h>
#include<time.h>
int isPrime(int x) {
	int t = 1;
	if (x == 2)t = 1;
	else if (x >= 3)
	{
		for (int j=2; j *j<=x; j++)
		{
			if (x % j == 0)t = 0;
		}
	}
	return t;

}
int main() {
	clock_t start, end;
	float x;
	start = clock();
	for (int i = 2; i <= 1000; i++)
	{
		if (isPrime(i) == 1)printf("%d ", i);
	}
	end = clock();
	x = end - start;
	printf("\n用时：%f", x);
	return 0;
}
