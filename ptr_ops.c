#include<stdio.h>


void printarr(int x, int y, int (*arr)[x]);

int main(void) {
	int arr[3][3] = {
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 9}
	};
	printarr(3, 3, arr);
	return 0;
}


void printarr(int x, int y, int (*arr)[x]) {
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			printf("%d ", *(*(arr + i) + j));
		}
		printf("\n");
	}
}
