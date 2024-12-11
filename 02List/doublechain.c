#include<stdlib.h>
#include<stdio.h>
#include<assert.h>

//定义双向循环链表
typedef struct DLNode {
	int _data;
	struct DLNode * _prev, * _next;
} DLNode;

typedef DLNode* DList;


DList InitList() {
	DList list = (DList)malloc(sizeof(DLNode));
	list->_next = list;
	list->_prev = list;
	return list;
}
//申请结点
DLNode* CreateNode(int x) {
	DLNode* node = (DLNode*)malloc(sizeof(DLNode));
	node->_data = x;
	node->_prev = NULL;
	node->_next = NULL;
	return node;
}

//打印链表
void Print(DList list) {
	DLNode* node = list->_next;
	while (node && node != list) {
		printf("%d->", node->_data);
		node = node->_next;
	}
	printf("\n");
}

//尾插入
void DListNodePushBack(DList list, int x) {
	DLNode* node = CreateNode(x);
	node->_next = list;
	node->_prev = list->_prev;
	list->_prev->_next = node;
	list->_prev = node;
}

//尾删除，删除尾部
void DListNodePopBack(DList list) {
	DLNode* node = list->_prev;
	list->_prev = node->_prev;
	node->_prev->_next = list;
	free(node);
}

//头插入
void DListNodePushHead(DList list, int x) {
	DLNode* node = CreateNode(x);
	node->_prev = list;
	node->_next = list->_next;
	list->_next->_prev = node;
	list->_next = node;

}

//头删除
void DListNodePopHead(DList list) {
	DLNode* node = list->_next;
	list->_next = node->_next;
	node->_next->_prev = list;
	free(node);

}

int main() {
	DList list = InitList();
	DListNodePushBack(list, 10);
	DListNodePushBack(list, 20);
	DListNodePushBack(list, 30);
	Print(list);
	DListNodePopBack(list);
	Print(list);

	DListNodePushHead(list, 40);
	Print(list);
	DListNodePopHead(list);
	Print(list);
	return 0;
}
