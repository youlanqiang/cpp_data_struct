#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef struct Lnode {
	int data;//结点的数据域
	struct Lnode * next; //结点的指针域

} Lnode;

typedef Lnode * LinkList; //LinkList为指向结构体Lnode的指针类型，其中Lnode * 为Lnode的指针类型

//创建一个空的带头结点的单链表
LinkList InitList() {
	LinkList head = (LinkList)malloc(sizeof(LinkList));
	head->data = 1;
	head->next = NULL;
	return head;
}

//判断链表是否为空
//算法思路：判断头结点指针域是否为空
int ListEmpty(LinkList L) {
	if (L->next) {
		return 0;
	} else {
		return 1;
	}
}


//销毁单链表
//算法思路：从头指针开始，依次释放所有结点
void DestoryList(LinkList L) {
	Lnode *p;
	while (L) {
		p = L;
		L = L->next;
		free(p);
	}
}

//清空单链表,头结点，头元素保留
//算法思路：依次释放所有结点，并将头结点指针域设置为空
void CleanList(LinkList L) {
	Lnode *p = L->next;
	Lnode *nextP = NULL;
	while (p) {
		nextP = p->next;
		free(p);
		p = nextP;
	}
	L->next = NULL;
}

//获取链表的长度
int ListLen(LinkList L) {
	Lnode *p = L->next;
	int i = 0;
	while (p) {
		i++;
		p = p->next;
	}
	return i;
}


//获取第i位的元素
int GetElem(LinkList L, int i, int* data) {
	Lnode *p = L->next;
	int j = 1;
	//向后扫描，直到p指向第i个元素或p为空
	while (p && j < i) {
		p = p->next;
		++j;
	}
	if (!p ||  j > i) {
		return -1;
	}
	*data = p->data;
	return 1;

}

//查询元素的对应的下标
int GetElemIndex(LinkList L, int data) {
	Lnode* p = L->next;
	int i = 1;
	while (p && p->data != data) {
		p = p->next;
		i++;
	}
	if (p != NULL) {
		return i;
	}
	return -1;
}


//插入元素
int InsertElem(LinkList L, int index, int data) {
	Lnode* p = L;
	int j = 0;
	while (p && j < index - 1) {//寻找第index-1个结点，p指向i-1结点
		p = p->next;
		++j;
	}
	if (!p || j > index - 1) {//index大于表长+1或者小于1，插入位置非法
		return -1;
	}
	//插入新结点
	Lnode* s = (Lnode*)malloc(sizeof(Lnode*));
	s->data = data;
	s->next = p->next;
	p->next = s;
	return 1;
}

//删除元素,其中deletedData是被删除返回的元素数据域
int DeleteElem(LinkList L, int index, int* deletedData) {
	Lnode* p = L;
	int j = 0;
	while (p && j < index - 1) {//寻找第index-1个结点，p指向i-1结点
		p = p->next;
		++j;
	}
	if (!p || j > index - 1) {//index大于表长+1或者小于1，插入位置非法
		return -1;
	}
	Lnode* q = p->next;
	*deletedData = q->data;
	p->next = p->next->next;
	free(q);
	return 1;
}

int main() {
	LinkList list = InitList();
	InsertElem(list, 1, 1);
	InsertElem(list, 2, 10);
	printf("length:%d\n", ListLen(list));
	int data = 0;
	GetElem(list, 2, &data);
	printf("%d\n", data);
	DeleteElem(list, 1, &data);
	printf("length:%d\n", ListLen(list));
	GetElem(list, 1, &data);
	printf("%d\n", data);
	return 0;
}
