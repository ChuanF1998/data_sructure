#include"stack.h"
#include<stdio.h>
#include<assert.h>
#include<malloc.h>

//初始化栈
void StackInit(Stack* ps){
	assert(ps != NULL);
	ps->_capacity = 5;   //设置容量为5的栈
	ps->_a = (STDataType*)malloc(sizeof(STDataType)*ps->_capacity);
	ps->_top = -1;  //栈为空时置栈顶为-1
}
//销毁栈
void StackDestory(Stack* ps){
	assert(ps != NULL);
	free(ps->_a);
}
//检测栈是否为空，空->非0，非空->0
int StackEmpty(Stack* ps){
	assert(ps != NULL);
	if (ps->_top == -1){ //栈空为1，其他情况为0
		return 1;
	}
	else{
		return 0;
	}
}
//入栈
void StackPush(Stack* ps, STDataType x){
	if (ps == NULL){//栈为空或栈满，直接返回
		return;
	}
	else if (ps->_top + 1 == ps->_capacity){
		printf("栈满，进栈失败\n");
		return;
	}
	else{
		ps->_top++;
		ps->_a[ps->_top] = x;
	}
}
//出栈
void StackPop(Stack* ps){
	if ((ps == NULL)||(ps->_top==-1)){  //栈不存在或栈为空，直接返回
		return;
	}
	else{
		ps->_top--;
	}
}
//获取栈顶元素
STDataType StackTop(Stack* ps){
	if (ps == NULL){
		return;
	}
	else if(ps->_top==-1){
		printf("栈为空\n");
		return;
	}
	return ps->_a[ps->_top];
}

//获取栈顶元素有效个数
int StackSize(Stack* ps){
	if (ps == NULL){
		return -1;
	}
	return ps->_top + 1;
}

void TestStack(){
	Stack s;
	StackInit(&s);
	StackPush(&s, 4);
	StackPush(&s, 7);
	StackPush(&s, 8);
	StackPush(&s, 9);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
	StackPop(&s);
	printf("%d\n", StackTop(&s));
	printf("%d\n", StackSize(&s));
}