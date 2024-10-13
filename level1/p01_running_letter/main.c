#include <stdio.h>
#include <windows.h>
#include<string.h>
#define width 40
#define speed 50
int main() {
	const char letter = 'A';
	int posi=0;
	int direc = 1;
	while (true) {
		system("cls");
		int i = 0;

		for (i = 0; i < posi; i++) {
			printf(" ");
		}
		printf("A");
		posi += direc;
		if (posi == width - 1||posi==0) {
			direc *= -1;
		}
		
		Sleep(speed);
	}
	system("pause");
	return 0;
}
