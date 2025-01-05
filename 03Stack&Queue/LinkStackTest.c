/**
 * 链栈
 */

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int ElemType;

typedef struct Node {
	ElemType data;//数据
	struct Node *next;//指针域
} Node;

typedef struct LinkedStack {
	Node *top;//栈顶指针，初始值为NULL
	int size; //链栈的长度
} LinkedStack;

//初始化栈
void initStack(LinkedStack *pStack) {
	pStack->top = NULL;
	pStack->size = 0;
}

bool isEmpty(LinkedStack *pStack) {
	return pStack->size == 0;
}

//实现入栈
bool push(LinkedStack *pStack, ElemType data) {
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;

	//指针域指向栈顶，头插法
	node->next = pStack->top;
	pStack->top = node;
	pStack->size++;
	return true;
}

//实现出栈
ElemType pop(LinkedStack *pStack) {
	if (isEmpty(pStack)) {
		return NULL;
	}
	Node* node = pStack->top;
	ElemType data = node->data;
	pStack->top = node->next;
	free(node);
	return data;
}

ElemType peek(LinkedStack *pStack) {
	if (isEmpty(pStack)) {
		return NULL;
	}
	return pStack->top->data;
}

void print(LinkedStack *pStack) {
	if (!isEmpty(pStack)) {
		Node* node = pStack->top;
		while (node) {
			printf("%d->", node->data);
			node = node->next;
		}
		printf("\n");
	}
}

int main() {
	LinkedStack* linkedStack = (LinkedStack*)malloc(sizeof(LinkedStack));
	initStack(linkedStack);
	_Bool hello = false;
	push(linkedStack, 10);
	push(linkedStack, 20);
	print(linkedStack);
	ElemType data = pop(linkedStack);
	printf("%d\n", data);
	print(linkedStack);
	return 0;
}
