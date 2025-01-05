#include<stdio.h>
#include<ctype.h>
#include<iso646.h>
#include<stdlib.h>
#define SPACE ' '


int main(void) {
	int a[5] = {0, [3] = 1, 2}; //指定初始化器
	for (int i = 0; i < 5; i++) {
		printf("i:%d val:%d \n", i, a[i]);
	}
	return 0;
}








