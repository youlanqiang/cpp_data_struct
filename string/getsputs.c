#include<stdio.h>
#define STLEN 81

int main(void) {
	char words[STLEN];
	puts("Enter a string please.");
	gets(words);//gets函数存在问题，C11已经没有该函数，后续代码尽量避免使用gets函数
	printf("Your string twice:\n");
	printf("%s\n", words);
	puts(words);
	puts("Done.");
	return 0;
}
