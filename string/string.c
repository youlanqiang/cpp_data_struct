#include<stdio.h>




int main(void) {
	//如果要修改字符串或者为字符串输入预留空间，不要使用指向字符串字面量的指针
	const char * str1 = "Java";
	char * str2 = "Java";
	char strarr[] = "Java";
	char strarr2[] = "Java";
	printf("str1 = %s str2 = %s  strarr = %s strarr2 = %s \n", str1, str2, strarr, strarr2);
	//str1[0] = 'P'; //修改字符串这一步直接导致进程卡住，因为修改字符串常量可能回导致内存访问错误。
	strarr[0] = 'p';
	printf("str1 = %s str2 = %s  strarr = %s strarr2 = %s \n", str1, str2, strarr, strarr2);


	return 0;
}
