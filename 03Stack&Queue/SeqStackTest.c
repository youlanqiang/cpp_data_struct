/**
 * 顺序栈，使用顺序线性表来当作存储结构的栈
 * 将数组下标为0表示栈底（buttom），将lenght表示栈顶的指针，指向数组最后一个元素的指针
 */

#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>
#define StackSize 100

typedef struct {
	int data[StackSize];
	int top; //指向栈顶的下标
} SeqStack;



//初始化Stack对象
SeqStack* InitStack() {
	SeqStack* stack = (SeqStack*)malloc(sizeof(SeqStack));
	stack->top = -1;
	return stack;
}

//判断stack是否为空
bool IsEmpty(SeqStack* stack) {
	return stack->top == -1;
}

//判断stack是否满了
bool IsFull(SeqStack* stack) {
	return stack->top == StackSize - 1;
}

//入栈
void Push(SeqStack* stack, int data) {
	if (IsFull(stack)) {
		return;
	}
	stack->top++;
	stack->data[stack->top] = data;
}

//出栈
int Pop(SeqStack* stack) {
	if (IsEmpty(stack)) {
		return NULL;
	}
	int data = stack->data[stack->top];
	stack->top--;
	return data;
}

//打印stack操作
void Print(SeqStack* stack) {
	if (!IsEmpty(stack)) {
		for (int i = 0; i <= stack->top; i++) {
			printf("%d->", stack->data[i]);
		}
		printf("\n");
	}
}

int main() {
	SeqStack* stack = InitStack();
	Push(stack, 1);
	Push(stack, 2);
	Push(stack, 3);
	Push(stack, 4);
	Print(stack);
	Pop(stack);
	Print(stack);
	Pop(stack);
	Print(stack);
	Pop(stack);
	Print(stack);

	return 0;
}
