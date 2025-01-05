#include<stdio.h>
#define STLEN 14

int main(void) {
	char words[STLEN];

	puts("Enter a string please.");
	fgets(words, STLEN, stdin);//fgets读取到换行符号不会抛弃，这点和gets有区别
	printf("Your string twice (puts(), then fputs()):\n");
	puts(words);//puts会在打印完字符串后再打印一个换行符，这就导致这一步打印了2个换行符号
	fputs(words, stdout);
	return 0;
}
