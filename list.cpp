#include "toolbox.h"


typedef int ElemType;

using namespace toolbox;

#define MAXSIZE 100

typedef struct {
	ElemType *elem;
	int length;
} SqList; //定义顺序表


int InitList_Sq(SqList &L) {
	L.elem = new ElemType[MAXSIZE];
	if (!L.elem) { //存储分配失败
		exit(-1);
	}
	L.length = 0;
	return 0;
}

int main() {

	println("");


	return 0;
}


