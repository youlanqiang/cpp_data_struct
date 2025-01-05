#include<stdio.h>


#define SIZE 7

int sump(int *, int *);


int main(void) {
	int marbles[SIZE] = {20, 10, 5, 39, 4, 16, 19};//合计 113
	long answer;

	answer = sump(marbles, marbles + SIZE);
	printf("The total number of marbles is %ld.\n", answer);
	return 0;
}


int sump(int * start, int * end) {
	int total = 0;
	while (start < end) {
		total += *start;
		start++;
		//上面这2句代码可以压缩为一句 total += *start++;
	}
	return total;
}
